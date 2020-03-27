#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_QtGuiApplication1.h"
#include <qstring.h>
#include <qmessagebox.h>
#include <qdialog.h>
#include "identiwidget.h"
#include "joinwidget.h"
#include "identifyadminwidget.h"
#include "adminmodewidget.h"
#include "DoublySortedLinkedList.h"
#include "DoublyIterator.h"

/////////////// MCI ////////////////
#include <Windows.h>
#include <io.h>
#include <conio.h>
#include <stdio.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")


namespace Ui { class QtGuiApplication1; }

//유저모드 메인 ui
class QtGuiApplication1 : public QMainWindow
{
	Q_OBJECT

public:
	QtGuiApplication1(QWidget *parent = Q_NULLPTR);

	//전체 곡 리스트를 display
	void displayAll();

	// 플레이리스트를 display
	void displayPlayList();

	//전체 곡 목록에서 곡을 읽어들임
	void readfile();

	// 플레이리스트 곡 목록에서 곡을 읽어들임
	void readplayfile();

	// 플레이리스트의 곡을 저장
	void saveplaylist();

private:
	Ui::QtGuiApplication1Class ui;
	QSignalMapper* checkboxMapper;
	string search;
	string searchtype;

	AvlTree<MusicType> MasterList;
	LinkedList<ArtistType> ArtistList;
	LinkedList<GenreType> GenreList;
	LinkedList<AlbumType> AlbumList;
	LinkedList<TitleType> TitleList;
	LinkedList<LylicsType> LylicsList;
	SortedList<MusicType> DisplayList;
	DoublySortedLinkedList<PlayType> PlayList;

	QWidget* addwidget;
	QPushButton* addbutton;

	//곡을 실행시키기 위한 파라미터
	int dwID;
	MCI_OPEN_PARMS mciOpen;
	MCI_PLAY_PARMS mciPlay;
	MCI_STATUS_PARMS mciStatus;

	enum Column
	{
		ALBUM, GENRE ,TITLE, ARTIST, LYLICS, ADD
	};

	enum Column2
	{
		_TITLE, _ARTIST, _LYLICS
	};

private slots:

	//유저모드 ui slot 함수
	void addtoplaylist_clicked();
	void search_textEdited(const QString& _search);
	void searchcombo_activated(const QString& _search);
	void searchbutton_clicked();
	void logout_clicked();
	void playbutton_clicked();
	int stopbutton_clicked();

};
