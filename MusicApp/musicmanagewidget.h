#pragma once

#include <QDialog>
#include "qmessagebox.h"
#include "ui_musicmanagewidget.h"
#include "adminmodewidget.h"
#include "MusicType.h"

namespace Ui
{
	class musicmanagewidget;
}

//���� ���� (�߰�,����) �� ���� ui
class musicmanagewidget : public QDialog
{
	Q_OBJECT

public:
	//������
	musicmanagewidget(QWidget *parent = Q_NULLPTR);
	//�Ҹ���
	~musicmanagewidget();

private:
	Ui::musicmanagewidget *ui;
	MusicType newmusic;
	MusicType replacemusic;
	string pk;
	string album;
	string artist;
	string ent;
	string genre;
	string lylics;
	string producer;
	string rdate;
	string title;
	string type;

private slots:
	//���� ���� ui slot �Լ�
	void album_textChanged(const QString& album);
	void artist_textChanged(const QString& artist);
	void ent_textChanged(const QString& ent);
	void genre_textChanged(const QString& genre);
	void lylics_textChanged(const QString& lylics);
	void pk_textChanged(const QString& pk);
	void producer_textChanged(const QString& producer);
	void rdate_textChanged(const QString& rdate);
	void title_textChanged(const QString& title);
	void type_textChanged(const QString& type);
	void savebutton_clicked();

};
