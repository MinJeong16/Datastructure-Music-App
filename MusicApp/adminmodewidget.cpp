#include "adminmodewidget.h"
adminmodewidget *adminmode;

//관리자모드 ui 생성자
adminmodewidget::adminmodewidget(QWidget *parent)
	: QMainWindow(parent),ui(new Ui::adminmodewidget)
{
	adminmode = this;

	ui->setupUi(this);
	checkboxMapper = new QSignalMapper(this);
	ui->tablewidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->tablewidget->setRowCount(0);
	ui->tablewidget->setColumnWidth(CHECK, 20);
	ui->tablewidget->setColumnWidth(ID, 70);
	ui->tablewidget->setColumnWidth(ALBUM, 100);
	ui->tablewidget->setColumnWidth(GENRE, 70);
	ui->tablewidget->setColumnWidth(TITLE, 100);
	ui->tablewidget->setColumnWidth(ARTIST, 90);
	ui->tablewidget->setColumnWidth(PRODUCER, 90);

	displayAll();
}

//소멸자
adminmodewidget::~adminmodewidget()
{
	delete ui;
}

//저장된 곡 목록을 디스플레이
void adminmodewidget::displayAll()
{
	ui->tablewidget->setRowCount(0);
	if(!DisplayList.IsEmpty())
	{
		DisplayList.ResetList();
		MusicType temp;
		while (DisplayList.GetNextItem(temp) != -1)
		{
			ui->tablewidget->insertRow(ui->tablewidget->rowCount());
			ui->tablewidget->setShowGrid(true);
			int index = ui->tablewidget->rowCount() - 1;
			
			int chkid = atoi(temp.GetID().c_str());

			QCheckBox *checkBox = new QCheckBox(this);
			checkBox->setChecked(false);
			connect(checkBox, SIGNAL(clicked()), checkboxMapper, SLOT(map()));
			checkboxMapper->setMapping(checkBox, chkid);
			connect(checkboxMapper, SIGNAL(mapped(int)), this, SLOT(checkChanged(int)));

			QTableWidgetItem* id = new QTableWidgetItem(QString::fromStdString(temp.GetID()));
			QTableWidgetItem* album = new QTableWidgetItem(QString::fromStdString(temp.GetAlbum()));
			QTableWidgetItem* genre = new QTableWidgetItem(QString::fromStdString(temp.GetGenre()));
			QTableWidgetItem* title = new QTableWidgetItem(QString::fromStdString(temp.GetTitle()));
			QTableWidgetItem* artist = new QTableWidgetItem(QString::fromStdString(temp.GetArtist()));
			QTableWidgetItem* producer = new QTableWidgetItem(QString::fromStdString(temp.GetProducer()));


			id->setTextAlignment(Qt::AlignCenter);
			album->setTextAlignment(Qt::AlignCenter);
			genre->setTextAlignment(Qt::AlignCenter);
			title->setTextAlignment(Qt::AlignCenter);
			artist->setTextAlignment(Qt::AlignCenter);
			producer->setTextAlignment(Qt::AlignCenter);

			ui->tablewidget->setCellWidget(index, CHECK, checkBox);
			ui->tablewidget->setItem(index, ID, id);
			ui->tablewidget->setItem(index, ALBUM, album);
			ui->tablewidget->setItem(index, GENRE, genre);
			ui->tablewidget->setItem(index, TITLE, title);
			ui->tablewidget->setItem(index, ARTIST, artist);
			ui->tablewidget->setItem(index, PRODUCER, producer);
		}
	}
}

//곡을 수정하는 함수
int adminmodewidget::Replace(MusicType& music)
{
	MusicType data;
	data.SetID(music.GetID());
	bool found;
	if (!MasterList.RetrieveItem(data, found))
		return 0;
	else
	{
		//마스터리스트 제거
		MasterList.DeleteItem(data);

		LylicsType lylics1;
		string l1;
		l1 = data.GetLylics();
		l1.erase(remove(l1.begin(), l1.end(), ' '), l1.end());
		lylics1.SetLylics(l1);
		lylics1.SetID(data.GetID());
		LylicsList.Delete(lylics1);

		//앨범리스트 제거
		AlbumType album;
		album.SetAlbum(data.GetAlbum());
		SimpleMusicType simpledata1;
		simpledata1.SetSimpleMusic(data.GetID(), data.GetTitle());

		if (AlbumList.Get(album))
		{
			album.DeleteMusicInMusicList(simpledata1);
			AlbumList.Delete(album);
		}

		//가수리스트 제거
		ArtistType artist;
		artist.SetName(data.GetArtist());
		artist.SetEnt(data.GetEntertainment());
		SimpleMusicType simpledata2;
		simpledata2.SetSimpleMusic(data.GetID(), data.GetTitle());

		if (ArtistList.Get(artist))
		{
			artist.DeleteList(simpledata2);
			ArtistList.Delete(artist);
		}

		//장르리스트 제거
		GenreType genre;
		genre.SetGenre(data.GetGenre());
		SimpleMusicType simpledata3;
		simpledata3.SetSimpleMusic(data.GetID(), data.GetTitle());

		if (GenreList.Get(genre))
		{
			genre.DeleteMusicInGenre(simpledata3);
			GenreList.Delete(genre);
		}

		// 곡리스트 제거
		TitleType title;
		title.SetTitle(data.GetTitle());
		string data4 = data.GetArtist();

		if (TitleList.Get(title))
		{
			title.DeleteArtistInList(data4);
			TitleList.Delete(title);
		}

		/////////////////// 추가 ///////////////////

		MasterList.Add(music);
		DisplayList.Replace(music);

		//곡명리스트 추가
		if (TitleList.GetLength() == 0)
		{
			TitleType title;
			string temp = music.GetArtist();
			title.SetTitle(music.GetTitle());
			title.AddArtistInList(temp);
			TitleList.Add(title);
		}
		else
		{
			TitleType title;
			string temp = music.GetArtist();
			title.SetTitle(music.GetTitle());
			if (TitleList.Get(title))
			{
				title.AddArtistInList(temp);
				TitleList.Replace(title);
			}
			else
			{
				title.AddArtistInList(temp);
				TitleList.Add(title);
			}

		}

		//앨범리스트 추가
		if (AlbumList.GetLength() == 0)
		{
			AlbumType album;
			album.SetAlbum(music.GetAlbum());
			album.SetArtist(music.GetArtist());
			SimpleMusicType simplemusic;
			simplemusic.SetSimpleMusic(music.GetID(), music.GetTitle());
			album.AddMusicInMusicList(simplemusic);
			AlbumList.Add(album);
		}
		else
		{
			AlbumType album;
			album.SetAlbum(music.GetAlbum());
			album.SetArtist(music.GetArtist());
			SimpleMusicType simplemusic;
			simplemusic.SetSimpleMusic(music.GetID(), music.GetTitle());
			if (AlbumList.Get(album))
			{
				album.AddMusicInMusicList(simplemusic);
				AlbumList.Replace(album);
			}
			else
			{
				album.AddMusicInMusicList(simplemusic);
				AlbumList.Add(album);
			}
		}

		//가수리스트 추가
		if (ArtistList.GetLength() == 0)
		{
			ArtistType artist;
			artist.SetName(music.GetArtist());
			artist.SetEnt(music.GetEntertainment());
			SimpleMusicType simplemusic;
			simplemusic.SetSimpleMusic(music.GetID(), music.GetTitle());
			artist.AddList(simplemusic);
			ArtistList.Add(artist);
		}
		else
		{
			ArtistType artist;
			artist.SetName(music.GetArtist());
			artist.SetEnt(music.GetEntertainment());
			SimpleMusicType simplemusic;
			simplemusic.SetSimpleMusic(music.GetID(), music.GetTitle());
			if (ArtistList.Get(artist))
			{
				artist.AddList(simplemusic);
				ArtistList.Replace(artist);
			}
			else
			{
				artist.AddList(simplemusic);
				ArtistList.Add(artist);
			}
		}

		//장르리스트 추가
		if (GenreList.GetLength() == 0)
		{
			GenreType genre;
			genre.SetGenre(music.GetGenre());
			SimpleMusicType simplemusic;
			simplemusic.SetSimpleMusic(music.GetID(), music.GetTitle());
			genre.AddMusicInGenre(simplemusic);
			GenreList.Add(genre);
		}
		else
		{
			GenreType genre;
			genre.SetGenre(music.GetGenre());
			SimpleMusicType simplemusic;
			simplemusic.SetSimpleMusic(music.GetID(), music.GetTitle());
			if (GenreList.Get(genre))
			{
				genre.AddMusicInGenre(simplemusic);
				GenreList.Replace(genre);
			}
			else
			{
				genre.AddMusicInGenre(simplemusic);
				GenreList.Add(genre);
			}
		}

		LylicsType lylics2;
		string l2;
		l2 = music.GetLylics();
		l2.erase(remove(l2.begin(), l2.end(), ' '), l2.end());
		lylics2.SetLylics(l2);
		lylics2.SetID(music.GetID());
		LylicsList.Add(lylics2);
		return 1;
	}

	savefile();
	displayAll();
}

int adminmodewidget::Add(MusicType &item)
{
	DisplayList.Add(item);
	//마스터리스트에 추가
	MasterList.Add(item);

	//곡명리스트 추가
	if (TitleList.GetLength() == 0)
	{
		TitleType title;
		string temp = item.GetArtist();
		title.SetTitle(item.GetTitle());
		title.AddArtistInList(temp);
		TitleList.Add(title);
	}
	else
	{
		TitleType title;
		string temp = item.GetArtist();
		title.SetTitle(item.GetTitle());
		if (TitleList.Get(title))
		{
			title.AddArtistInList(temp);
			TitleList.Replace(title);
		}
		else
		{
			title.AddArtistInList(temp);
			TitleList.Add(title);
		}

	}

	//앨범리스트 추가
	if (AlbumList.GetLength() == 0)
	{
		AlbumType album;
		album.SetAlbum(item.GetAlbum());
		album.SetArtist(item.GetArtist());
		SimpleMusicType simplemusic;
		simplemusic.SetSimpleMusic(item.GetID(), item.GetTitle());
		album.AddMusicInMusicList(simplemusic);
		AlbumList.Add(album);
	}
	else
	{
		AlbumType album;
		album.SetAlbum(item.GetAlbum());
		album.SetArtist(item.GetArtist());
		SimpleMusicType simplemusic;
		simplemusic.SetSimpleMusic(item.GetID(), item.GetTitle());
		if (AlbumList.Get(album))
		{
			album.AddMusicInMusicList(simplemusic);
			AlbumList.Replace(album);
		}
		else
		{
			album.AddMusicInMusicList(simplemusic);
			AlbumList.Add(album);
		}
	}

	//가수리스트 추가
	if (ArtistList.GetLength() == 0)
	{
		ArtistType artist;
		artist.SetName(item.GetArtist());
		artist.SetEnt(item.GetEntertainment());
		SimpleMusicType simplemusic;
		simplemusic.SetSimpleMusic(item.GetID(), item.GetTitle());
		artist.AddList(simplemusic);
		ArtistList.Add(artist);
	}
	else
	{
		ArtistType artist;
		artist.SetName(item.GetArtist());
		artist.SetEnt(item.GetEntertainment());
		SimpleMusicType simplemusic;
		simplemusic.SetSimpleMusic(item.GetID(), item.GetTitle());
		if (ArtistList.Get(artist))
		{
			artist.AddList(simplemusic);
			ArtistList.Replace(artist);
		}
		else
		{
			artist.AddList(simplemusic);
			ArtistList.Add(artist);
		}
	}

	//장르리스트 추가
	if (GenreList.GetLength() == 0)
	{
		GenreType genre;
		genre.SetGenre(item.GetGenre());
		SimpleMusicType simplemusic;
		simplemusic.SetSimpleMusic(item.GetID(), item.GetTitle());
		genre.AddMusicInGenre(simplemusic);
		GenreList.Add(genre);
	}
	else
	{
		GenreType genre;
		genre.SetGenre(item.GetGenre());
		SimpleMusicType simplemusic;
		simplemusic.SetSimpleMusic(item.GetID(), item.GetTitle());
		if (GenreList.Get(genre))
		{
			genre.AddMusicInGenre(simplemusic);
			GenreList.Replace(genre);
		}
		else
		{
			genre.AddMusicInGenre(simplemusic);
			GenreList.Add(genre);
		}
	}

	LylicsType lylics;
	string l;
	l = item.GetLylics();
	l.erase(remove(l.begin(), l.end(), ' '), l.end());
	lylics.SetLylics(l);
	lylics.SetID(item.GetID());
	LylicsList.Add(lylics);

	savefile();
	displayAll();

	return 1;
}

//파일에 저장
void adminmodewidget::savefile()
{
	MusicType item;
	ofstream m_OutFile;
	m_OutFile.open("musicfile.txt");
	if (m_OutFile.is_open())
	{
		DisplayList.ResetList();
		while (DisplayList.GetNextItem(item) != -1)
		{
			item.WriteDataToFile(m_OutFile);
		}
	}
}
//파일을 읽어들임
int adminmodewidget::readfile()
{
	ifstream m_InFile;
	MusicType item;
	m_InFile.open("musicfile.txt");
	if (m_InFile.is_open())
	{
		while (!m_InFile.eof())
		{
			item.ReadDataFromFile(m_InFile);
			DisplayList.Add(item);
			MasterList.Add(item);

			//곡명리스트 추가
			if (TitleList.GetLength() == 0)
			{
				TitleType title;
				string temp = item.GetArtist();
				title.SetTitle(item.GetTitle());
				title.AddArtistInList(temp);
				TitleList.Add(title);
			}
			else
			{
				TitleType title;
				string temp = item.GetArtist();
				title.SetTitle(item.GetTitle());
				if (TitleList.Get(title))
				{
					title.AddArtistInList(temp);
					TitleList.Replace(title);
				}
				else
				{
					title.AddArtistInList(temp);
					TitleList.Add(title);
				}

			}

			//앨범리스트 추가
			if (AlbumList.GetLength() == 0)
			{
				AlbumType album;
				album.SetAlbum(item.GetAlbum());
				album.SetArtist(item.GetArtist());
				SimpleMusicType simplemusic;
				simplemusic.SetSimpleMusic(item.GetID(), item.GetTitle());
				album.AddMusicInMusicList(simplemusic);
				AlbumList.Add(album);
			}
			else
			{
				AlbumType album;
				album.SetAlbum(item.GetAlbum());
				album.SetArtist(item.GetArtist());
				SimpleMusicType simplemusic;
				simplemusic.SetSimpleMusic(item.GetID(), item.GetTitle());
				if (AlbumList.Get(album))
				{
					album.AddMusicInMusicList(simplemusic);
					AlbumList.Replace(album);
				}
				else
				{
					album.AddMusicInMusicList(simplemusic);
					AlbumList.Add(album);
				}
			}

			//가수리스트 추가
			if (ArtistList.GetLength() == 0)
			{
				ArtistType artist;
				artist.SetName(item.GetArtist());
				artist.SetEnt(item.GetEntertainment());
				SimpleMusicType simplemusic;
				simplemusic.SetSimpleMusic(item.GetID(), item.GetTitle());
				artist.AddList(simplemusic);
				ArtistList.Add(artist);
			}
			else
			{
				ArtistType artist;
				artist.SetName(item.GetArtist());
				artist.SetEnt(item.GetEntertainment());
				SimpleMusicType simplemusic;
				simplemusic.SetSimpleMusic(item.GetID(), item.GetTitle());
				if (ArtistList.Get(artist))
				{
					artist.AddList(simplemusic);
					ArtistList.Replace(artist);
				}
				else
				{
					artist.AddList(simplemusic);
					ArtistList.Add(artist);
				}
			}

			//장르리스트 추가
			if (GenreList.GetLength() == 0)
			{
				GenreType genre;
				genre.SetGenre(item.GetGenre());
				SimpleMusicType simplemusic;
				simplemusic.SetSimpleMusic(item.GetID(), item.GetTitle());
				genre.AddMusicInGenre(simplemusic);
				GenreList.Add(genre);
			}
			else
			{
				GenreType genre;
				genre.SetGenre(item.GetGenre());
				SimpleMusicType simplemusic;
				simplemusic.SetSimpleMusic(item.GetID(), item.GetTitle());
				if (GenreList.Get(genre))
				{
					genre.AddMusicInGenre(simplemusic);
					GenreList.Replace(genre);
				}
				else
				{
					genre.AddMusicInGenre(simplemusic);
					GenreList.Add(genre);
				}
			}

			LylicsType lylics;
			string l;
			l = item.GetLylics();
			l.erase(remove(l.begin(), l.end(), ' '), l.end());
			lylics.SetLylics(l);
			lylics.SetID(item.GetID());
			LylicsList.Add(lylics);
		}
		return 1;
	}
	else
	{
		return 0;
	}

	m_InFile.close();

}

void adminmodewidget::adminexit_clicked()
{
	QMessageBox msgbox;
	msgbox.setText(QString::fromLocal8Bit("관리자모드를 종료합니다."));
	this->close();
}

void adminmodewidget::selectfile_clicked()
{
	if (readfile())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("파일"), QString::fromLocal8Bit("파일을 정상적으로 불러왔습니다!"));
		displayAll();
	}
}

void adminmodewidget::addmusic_clicked()
{
	musicmanagewidget musicadd;
	int res = musicadd.exec();
	if (res == QDialog::Accepted)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("음악추가"), QString::fromLocal8Bit("음악이 추가되었습니다!"));
	}
}

void adminmodewidget::replacemusic_clicked()
{
	musicmanagewidget musicreplace;
	int res = musicreplace.exec();
	if (res == QDialog::Changed)
		QMessageBox::information(this, QString::fromLocal8Bit("음악수정"), QString::fromLocal8Bit("음악이 수정되었습니다!"));
}

void adminmodewidget::selectdelete_clicked()
{
	if (checklist.GetLength() == 0)
	{
		QMessageBox::information(this,
			QString::fromLocal8Bit("에러!"),
			QString::fromLocal8Bit("곡이 선택되지 않았습니다!"));
		return;
	}
	
	QMessageBox msgbox;
	msgbox.setText(QString::fromLocal8Bit("삭제하시겠습니까?"));
	msgbox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	msgbox.setDefaultButton(QMessageBox::Ok);
	if (msgbox.exec() == QMessageBox::Cancel)
		return;

	int chk;
	int i = 0;
	checklist.ResetList();
//	while (checklist.GetNextItem(chk) != -1)
	while(i < checklist.GetLength())
	{
		checklist.GetNextItem(chk);
		string id = to_string(chk);
		MusicType data;
		data.SetID(id);
		
		bool found;
		MasterList.RetrieveItem(data, found);
		if (found)
		{
			DisplayList.Delete(data);
			MasterList.DeleteItem(data);

			LylicsType lylics;
			string l;
			l = data.GetLylics();
			lylics.SetLylics(l);
			lylics.SetID(data.GetID());
			LylicsList.Delete(lylics);

			//앨범리스트 제거
			AlbumType album;
			album.SetAlbum(data.GetAlbum());
			SimpleMusicType simpledata1;
			simpledata1.SetSimpleMusic(data.GetID(), data.GetTitle());

			if (AlbumList.Get(album))
			{
				album.DeleteMusicInMusicList(simpledata1);
				AlbumList.Delete(album);
			}

			//가수리스트 제거
			ArtistType artist;
			artist.SetName(data.GetArtist());
			artist.SetEnt(data.GetEntertainment());
			SimpleMusicType simpledata2;
			simpledata2.SetSimpleMusic(data.GetID(), data.GetTitle());

			if (ArtistList.Get(artist))
			{
				artist.DeleteList(simpledata2);
				ArtistList.Delete(artist);
			}

			//장르리스트 제거
			GenreType genre;
			genre.SetGenre(data.GetGenre());
			SimpleMusicType simpledata3;
			simpledata3.SetSimpleMusic(data.GetID(), data.GetTitle());

			if (GenreList.Get(genre))
			{
				genre.DeleteMusicInGenre(simpledata3);
				GenreList.Delete(genre);
			}

			// 곡리스트 제거
			TitleType title;
			title.SetTitle(data.GetTitle());
			string data4 = data.GetArtist();

			if (TitleList.Get(title))
			{
				title.DeleteArtistInList(data4);
				TitleList.Delete(title);
			}
		}
		i++;
	}

	checklist.MakeEmpty();
	savefile();
	displayAll();
}

void adminmodewidget::alldelete_clicked()
{
	QMessageBox MsgBox;
	MsgBox.setText(QString::fromLocal8Bit("모두 삭제하시겠습니까"));
	MsgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	MsgBox.setDefaultButton(QMessageBox::Ok);
	if (MsgBox.exec() == QMessageBox::Cancel)
		return;
	MasterList.MakeEmpty();
	DisplayList.MakeEmpty();
	savefile();
	displayAll();
}

void adminmodewidget::checkChanged(int id)
{
	string _id = to_string(id);
	MusicType music;
	music.SetID(_id);
	DisplayList.Retrieve(music);
	int index = DisplayList.GetCur();

	bool state;
	state = static_cast<QCheckBox*>(ui->tablewidget->cellWidget(index, CHECK))->isChecked();

	if (state)
	{
		checklist.Add(id);
		return;
	}
	else
	{
		checklist.Delete(id);
		return;
	}
}
