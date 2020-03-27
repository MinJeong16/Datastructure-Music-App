#include "musicmanagewidget.h"
extern adminmodewidget *adminmode;

//���� ����(�߰�,����)�� ���� ui ������
musicmanagewidget::musicmanagewidget(QWidget *parent)
	: QDialog(parent),ui(new Ui::musicmanagewidget)
{
	ui->setupUi(this);

	ui->pkEdit->setPlaceholderText(QString::fromLocal8Bit("�� �����ÿ��� �Է��ϼ���."));
}

//�Ҹ���
musicmanagewidget::~musicmanagewidget()
{
	delete ui;
}

/////////////// ui slot �Լ� //////////////////
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
	if (pk.empty()) //�� �߰�
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
			QMessageBox::information(this, QString::fromLocal8Bit("����!"), QString::fromLocal8Bit("�Էµ��� ���� ������ �����մϴ�!"));
		}
		else
		{
			QMessageBox msg;
			msg.setText(QString::fromLocal8Bit("�����Ͻðڽ��ϱ�?"));
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
					QMessageBox::information(this, QString::fromLocal8Bit("����!"), QString::fromLocal8Bit("�̹� ���� ���� �����մϴ�!"));
			}
		}
	}
	else // �� ����
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
			QMessageBox::information(this, QString::fromLocal8Bit("����!"), QString::fromLocal8Bit("�Էµ��� ���� ������ �����մϴ�!"));
		}
		else
		{
			QMessageBox msg;
			msg.setText(QString::fromLocal8Bit("�����Ͻðڽ��ϱ�?"));
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
					QMessageBox::information(this, QString::fromLocal8Bit("����!"), QString::fromLocal8Bit("�ش� ������ȣ�� ���� ���� �������� �ʽ��ϴ�!"));
			}

		}
	}
}
