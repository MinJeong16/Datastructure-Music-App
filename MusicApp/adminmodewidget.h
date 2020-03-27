#pragma once

#include <qstring.h>
#include <qmessagebox.h>
#include <qmenu.h>
#include <qmenubar.h>
#include <qfiledialog.h>
#include <qsignalmapper.h>
#include <qcheckbox.h>
#include <qaction.h>
#include <qboxlayout.h>
#include <QMainWindow>
#include "ui_adminmodewidget.h"
#include "musicmanagewidget.h"

#include "MusicType.h"
#include "AvlTree.h"
#include "ArtistType.h"
#include "LinkedList.h"
#include "TitleType.h"
#include "LylicsType.h"
#include "AlbumType.h"
#include "GenreType.h"
#include "SortedList.h"
namespace Ui
{
	class adminmodewidget;
}

//관리자모드 메인 ui
class adminmodewidget : public QMainWindow
{
	Q_OBJECT

public:
	adminmodewidget(QWidget *parent = Q_NULLPTR);
	~adminmodewidget();
	
	//화면에 곡 목록을 디스플레이
	void displayAll();

	// 곡 수정
	int Replace(MusicType& data);

	// 곡 추가
	int Add(MusicType &music);

	//파일에 저장
	void savefile();

	//파일에서 읽어들이기
	int readfile();

private slots:
	//ui slot 함수
	void adminexit_clicked();
	void selectfile_clicked();
	void addmusic_clicked();
	void replacemusic_clicked();
	void selectdelete_clicked();
	void alldelete_clicked();

	//checkbox가 체크되었는지 확인하는 함수
	void checkChanged(int id);

private:
	Ui::adminmodewidget *ui;

	AvlTree<MusicType> MasterList;
	LinkedList<ArtistType> ArtistList;
	LinkedList<GenreType> GenreList;
	LinkedList<AlbumType> AlbumList;
	LinkedList<TitleType> TitleList;
	LinkedList<LylicsType> LylicsList;
	SortedList<MusicType> DisplayList;
	
	LinkedList<int> checklist;

	QSignalMapper* checkboxMapper;

	enum Column
	{
		CHECK ,ID, GENRE, ALBUM, TITLE, ARTIST, PRODUCER, ENT
	};
	

};
