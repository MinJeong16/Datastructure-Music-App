#include "musicmanagewidget.h"
extern adminmodewidget *adminmode;

//음악 관리(추가,수정)을 위한 ui 생성자
musicmanagewidget::musicmanagewidget(QWidget *parent)
	: QDialog(parent),ui(new Ui::musicmanagewidget)
{
	ui->setupUi(this);

	ui->pkEdit->setPlaceholderText(QString::fromLocal8Bit("곡 수정시에만 입력하세요."));
}

//소멸자
musicmanagewidget::~musicmanagewidget()
{
	delete ui;
}

/////////////// ui slot 함수 //////////////////
void musicmanagewidget::album_textChanged(const QString & _album)
{
	album = _album.toLocal8Bit();	
}

void musicmanagewidget::artist_textChanged(const QString & _artist)
{
	artist = _artist.toLocal8Bit();
}

void musicmanagewidget::ent_textChanged(const QString & _ent)
{
	ent = _ent.toLocal8Bit();
}

void musicmanagewidget::genre_textChanged(const QString & _genre)
{
	genre = _genre.toLocal8Bit();
}

void musicmanagewidget::lylics_textChanged(const QString & _lylics)
{
	lylics = _lylics.toLocal8Bit();
}

void musicmanagewidget::pk_textChanged(const QString & _pk)
{
	pk = _pk.toLocal8Bit();
}

void musicmanagewidget::producer_textChanged(const QString & _producer)
{
	producer = _producer.toLocal8Bit();
}

void musicmanagewidget::rdate_textChanged(const QString & _rdate)
{
	rdate = _rdate.toLocal8Bit();
}

void musicmanagewidget::title_textChanged(const QString & _title)
{
	title = _title.toLocal8Bit();
}

void musicmanagewidget::type_textChanged(const QString & _type)
{
	type = _type.toLocal8Bit();
}

void musicmanagewidget::savebutton_clicked()
{
	if (pk.empty()) //곡 추가
	{
		newmusic.SetAlbum(album);
		newmusic.SetArtist(artist);
		newmusic.SetEntertainment(ent);
		newmusic.SetGenre(genre);
		newmusic.SetLylics(lylics);
		newmusic.SetProducer(producer);
		newmusic.SetReleaseDate(rdate);
		newmusic.SetTitle(title);
		newmusic.SetType(type);
		
		if (album.empty() || artist.empty() || ent.empty() || genre.empty() || lylics.empty() ||
			producer.empty() || rdate.empty() || title.empty() || type.empty())
		{
			QMessageBox::information(this, QString::fromLocal8Bit("에러!"), QString::fromLocal8Bit("입력되지 않은 정보가 존재합니다!"));
		}
		else
		{
			QMessageBox msg;
			msg.setText(QString::fromLocal8Bit("저장하시겠습니까?"));
			msg.setStandardButtons(QMessageBox::Ok | QMessageBox::No);
			msg.setDefaultButton(QMessageBox::Ok);
			if (msg.exec() == QMessageBox::Ok)
			{
				newmusic.SetID_AUTO();
				int det = adminmode->Add(newmusic);
				if (det == 1)
				{
					done(QDialog::Accepted);
				}
				else if (det == 0)
					QMessageBox::information(this, QString::fromLocal8Bit("에러!"), QString::fromLocal8Bit("이미 같은 곡이 존재합니다!"));
			}
		}
	}
	else // 곡 수정
	{
		replacemusic.SetID(pk);
		replacemusic.SetAlbum(album);
		replacemusic.SetArtist(artist);
		replacemusic.SetEntertainment(ent);
		replacemusic.SetGenre(genre);
		replacemusic.SetLylics(lylics);
		replacemusic.SetProducer(producer);
		replacemusic.SetReleaseDate(rdate);
		replacemusic.SetTitle(title);
		replacemusic.SetType(type);

		if (pk.empty() || album.empty() || artist.empty() || ent.empty() || genre.empty() || lylics.empty() ||
			producer.empty() || rdate.empty() || title.empty() || type.empty())
		{
			QMessageBox::information(this, QString::fromLocal8Bit("에러!"), QString::fromLocal8Bit("입력되지 않은 정보가 존재합니다!"));
		}
		else
		{
			QMessageBox msg;
			msg.setText(QString::fromLocal8Bit("저장하시겠습니까?"));
			msg.setStandardButtons(QMessageBox::Ok | QMessageBox::No);
			msg.setDefaultButton(QMessageBox::Ok);
			if (msg.exec() == QMessageBox::Ok)
			{
				int det = adminmode->Replace(newmusic);
				if (det == 1)
				{
					done(QDialog::Changed);
				}
				else if (det == 0)
					QMessageBox::information(this, QString::fromLocal8Bit("에러!"), QString::fromLocal8Bit("해당 고유번호를 가진 곡이 존재하지 않습니다!"));
			}

		}
	}
}
