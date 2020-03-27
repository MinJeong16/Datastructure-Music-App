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

//음악 관리 (추가,수정) 을 위한 ui
class musicmanagewidget : public QDialog
{
	Q_OBJECT

public:
	//생성자
	musicmanagewidget(QWidget *parent = Q_NULLPTR);
	//소멸자
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
	//음악 관리 ui slot 함수
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
