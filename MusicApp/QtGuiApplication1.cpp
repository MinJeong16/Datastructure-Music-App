#include "QtGuiApplication1.h"

//유저모드 생성자
QtGuiApplication1::QtGuiApplication1(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//tableWidget Setting
	
	ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableWidget->setRowCount(0);
	ui.tableWidget->setColumnWidth(ALBUM, 100);
	ui.tableWidget->setColumnWidth(GENRE, 70);
	ui.tableWidget->setColumnWidth(TITLE, 100);
	ui.tableWidget->setColumnWidth(ARTIST, 90);
	ui.tableWidget->setColumnWidth(LYLICS, 100);
	ui.tableWidget->setColumnWidth(ADD, 80);

	// playlist setting
	ui.tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableWidget_2->setRowCount(0);
	ui.tableWidget_2->setColumnWidth(_TITLE, 100);
	ui.tableWidget_2->setColumnWidth(_ARTIST, 70);
	ui.tableWidget_2->setColumnWidth(_LYLICS, 100);
	
	readfile();
	readplayfile();
	displayAll();
	displayPlayList();
}

////// ui slot 함수//////
void QtGuiApplication1::addtoplaylist_clicked()
{
	QWidget *w = qobject_cast<QWidget *>(sender()->parent());

	int row = ui.tableWidget->indexAt(w->pos()).row();
	MusicType item;
	item.SetID(DisplayList.at(row).GetID());
	bool found;
	MasterList.RetrieveItem(item, found);

	PlayType pitem;
	pitem.SetArtist(item.GetArtist());
	pitem.SetLylics(item.GetLylics());
	pitem.SetPlayID(item.GetID());
	pitem.SetTitle(item.GetTitle());

	int det = PlayList.Add(pitem);
	if (det == 1)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("플레이리스트에 저장"), QString::fromLocal8Bit("플레이리스트에 추가되었습니다!"));
		saveplaylist();
		displayPlayList();
	}
	else if (det == 0)
		QMessageBox::information(this, QString::fromLocal8Bit("에러!"), QString::fromLocal8Bit("같은 곡이 이미 있습니다!"));
}

void QtGuiApplication1::search_textEdited(const QString & _search)
{
	search = _search.toLocal8Bit();
}

// 전체 곡 목록을 display
void QtGuiApplication1::displayAll()
{
	ui.tableWidget->setRowCount(0);
	if (!DisplayList.IsEmpty())
	{
		DisplayList.ResetList();
		MusicType temp;
		while (DisplayList.GetNextItem(temp) != -1)
		{
			ui.tableWidget->insertRow(ui.tableWidget->rowCount());
			ui.tableWidget->setShowGrid(true);
			int index = ui.tableWidget->rowCount() - 1;

			addwidget = new QWidget();
			addbutton = new QPushButton();
			addbutton->setText(QString::fromLocal8Bit("추가"));
			connect(addbutton, &QPushButton::clicked, this, &QtGuiApplication1::addtoplaylist_clicked);
			QHBoxLayout* AddLayout = new QHBoxLayout(addwidget);
			AddLayout->addWidget(addbutton);
			AddLayout->setAlignment(Qt::AlignCenter);
			AddLayout->setContentsMargins(0, 0, 0, 0);
			addwidget->setLayout(AddLayout);

			QTableWidgetItem* album = new QTableWidgetItem(QString::fromStdString(temp.GetAlbum()));
			QTableWidgetItem* genre = new QTableWidgetItem(QString::fromStdString(temp.GetGenre()));
			QTableWidgetItem* title = new QTableWidgetItem(QString::fromStdString(temp.GetTitle()));
			QTableWidgetItem* artist = new QTableWidgetItem(QString::fromStdString(temp.GetArtist()));
			QTableWidgetItem* lylics = new QTableWidgetItem(QString::fromStdString(temp.GetLylics()));

			album->setTextAlignment(Qt::AlignCenter);
			genre->setTextAlignment(Qt::AlignCenter);
			title->setTextAlignment(Qt::AlignCenter);
			artist->setTextAlignment(Qt::AlignCenter);
			lylics->setTextAlignment(Qt::AlignCenter);
			//			type->setTextAlignment(Qt::AlignCenter);

			ui.tableWidget->setItem(index, ALBUM, album);
			ui.tableWidget->setItem(index, GENRE, genre);
			ui.tableWidget->setItem(index, TITLE, title);
			ui.tableWidget->setItem(index, ARTIST, artist);
			ui.tableWidget->setItem(index, LYLICS, lylics);
			ui.tableWidget->setCellWidget(index, ADD, addwidget);
			//	ui->tablewidget->setItem(index, TYPE, type);
		}
	}
}

//플레이리스트를 display
void QtGuiApplication1::displayPlayList()
{
	ui.tableWidget_2->setRowCount(0);
	if (!PlayList.IsEmpty())
	{
		DoublyIterator<PlayType> itor(PlayList);
		while (itor.NextNotNull())
		{
			itor.Next();

			ui.tableWidget_2->insertRow(ui.tableWidget_2->rowCount());
			ui.tableWidget_2->setShowGrid(true);
			int index = ui.tableWidget_2->rowCount() - 1;

			QTableWidgetItem* title = new QTableWidgetItem(QString::fromStdString(itor.GetCurrentNode().data.GetTitle()));
			QTableWidgetItem* artist = new QTableWidgetItem(QString::fromStdString(itor.GetCurrentNode().data.GetArtist()));
			QTableWidgetItem* lylics = new QTableWidgetItem(QString::fromStdString(itor.GetCurrentNode().data.GetLylics()));

			title->setTextAlignment(Qt::AlignCenter);
			artist->setTextAlignment(Qt::AlignCenter);
			lylics->setTextAlignment(Qt::AlignCenter);

			ui.tableWidget_2->setItem(index, _TITLE, title);
			ui.tableWidget_2->setItem(index, _ARTIST, artist);
			ui.tableWidget_2->setItem(index, _LYLICS, lylics);

		}
	}
}

//파일을 읽어들임
void QtGuiApplication1::readfile()
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
	}

	m_InFile.close();
}

//playfile을 읽어들임
void QtGuiApplication1::readplayfile()
{
	ifstream m_InFile;
	m_InFile.open("playfile.txt");

	DoublyIterator<PlayType> itor(PlayList);
	if (m_InFile.is_open())
	{
		while (itor.NextNotNull())
		{
			itor.GetCurrentNode().data.readitem(m_InFile);
			itor.Next();
		}
	}
	m_InFile.close();
}

//플레이리스트를 저장
void QtGuiApplication1::saveplaylist()
{
	PlayType item;
	ofstream m_OutFile;
	m_OutFile.open("playfile.txt");
	DoublyIterator<PlayType> itor(PlayList);
//	PlayList.ResetList();
	if (m_OutFile.is_open())
	{
		//while(PlayList.GetNextItem(item) != -1)
		while (itor.NextNotNull())
		{
		//	item.saveitem(m_OutFile);
			itor.GetCurrentNode().data.saveitem(m_OutFile);
			itor.Next();
		}
	}

	m_OutFile.close();
}

void QtGuiApplication1::searchcombo_activated(const QString & _search)
{
	searchtype = _search.toLocal8Bit();
}

//검색 버튼을 눌렀을 때
void QtGuiApplication1::searchbutton_clicked()
{
	if (searchtype == "Search")
	{//Search이면 유지
		readfile();
		displayAll();
	}
	else if (searchtype == "ID")
	{//ID이면 ID로 검색
		string id = search;
		MusicType music;
		music.SetID(search);
		bool found;
		MasterList.RetrieveItem(music, found);
		DisplayList.MakeEmpty();
		DisplayList.Add(music);
		displayAll();
	}
	else if (searchtype == "Title")
	{
		SortedList<MusicType> tempList;
		string title = search;
		MusicType music;
		DisplayList.ResetList();
		while (DisplayList.GetNextItem(music) != -1)
		{
			if (music.GetTitle().find(title) != -1)
			{
				tempList.Add(music);
			}
		}

		if (tempList.GetLength() != 0)
		{
			DisplayList.MakeEmpty();
			DisplayList = tempList;
			displayAll();
		}
	}
	else if (searchtype == "Artist")
	{
		SortedList<MusicType> tempList;
		string artist = search;
		MusicType music;
		DisplayList.ResetList();
		while (DisplayList.GetNextItem(music) != -1)
		{
			if (music.GetArtist() == artist)
			{
				tempList.Add(music);
			}
		}

		if (tempList.GetLength() != 0)
		{
			DisplayList.MakeEmpty();
			DisplayList = tempList;
			displayAll();
		}
	}
	else if (searchtype == "Album")
	{
		SortedList<MusicType> tempList;
		string album = search;
		MusicType music;
		DisplayList.ResetList();
		while (DisplayList.GetNextItem(music) != -1)
		{
			if (music.GetAlbum() == album)
			{
				tempList.Add(music);
			}
		}

		if (tempList.GetLength() != 0)
		{
			DisplayList.MakeEmpty();
			DisplayList = tempList;
			displayAll();
		}
	}
	else if (searchtype == "Lyrics")
	{
		SortedList<MusicType> tempList;
		string lylics = search;
		MusicType music;

		LylicsType data;
		LylicsList.ResetList();
		int i = 0;
		while (i < LylicsList.GetLength())
		{
			LylicsList.GetNextItem(data);
			if (data.GetLylics().find(lylics) != -1)
			{
				music.SetID(data.GetID());
				DisplayList.Retrieve(music);
				tempList.Add(music);
			}
			i++;
		}

		if (tempList.GetLength() != 0)
		{
			DisplayList.MakeEmpty();
			DisplayList = tempList;
			displayAll();
		}
	}
}

// ui slot 함수 ////////
void QtGuiApplication1::logout_clicked()
{
	QMessageBox msg;
	msg.setText(QString::fromLocal8Bit("로그아웃 하시겠습니까?"));
	msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	msg.setDefaultButton(QMessageBox::Ok);
	if (msg.exec() == QMessageBox::Ok)
		this->close();
}


void QtGuiApplication1::playbutton_clicked()
{
	string item;
	PlayType temp;
	DoublyIterator<PlayType> itor(PlayList);
	bool find = false;
	const char* constc;
	while (itor.NextNotNull())
	{
		item = itor.GetCurrentNode().data.GetTitle();
		if (item == "")
		{
			itor.Next();
			item = itor.GetCurrentNode().data.GetTitle();
		}

		item += ".mp3";
		constc = item.c_str();
		wchar_t Lwconstc[56] = { L'\0', };

		int len = strlen(constc) + 1;
		mbstowcs(Lwconstc, constc, len);

		mciOpen.lpstrDeviceType = TEXT("mpegvideo");  // mpegvideo : mp3, waveaudio : wav, avivideo : avi
		mciOpen.lpstrElementName = TEXT(wconstc); // 파일이름


		mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&mciOpen);

		dwID = mciOpen.wDeviceID;
		MCI_PLAY_PARMS m_mciPlayParms;

		mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&m_mciPlayParms);
		
	}
}

int QtGuiApplication1::stopbutton_clicked()
{
	QMessageBox msg;
	msg.setText(QString::fromLocal8Bit("재생을 중단하시겠습니까?"));
	msg.setStandardButtons(QMessageBox::Ok|QMessageBox::No);
	if (msg.exec() == QMessageBox::Ok)
	{
		mciSendCommand(dwID, MCI_PAUSE, MCI_NOTIFY, (DWORD)(LPVOID)&mciPlay);
		return 1;
	}
	else
		return 0;
}


