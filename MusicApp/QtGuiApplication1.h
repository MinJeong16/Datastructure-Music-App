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

//������� ���� ui
class QtGuiApplication1 : public QMainWindow
{
	Q_OBJECT

public:
	QtGuiApplication1(QWidget *parent = Q_NULLPTR);

	//��ü �� ����Ʈ�� display
	void displayAll();

	// �÷��̸���Ʈ�� display
	void displayPlayList();

	//��ü �� ��Ͽ��� ���� �о����
	void readfile();

	// �÷��̸���Ʈ �� ��Ͽ��� ���� �о����
	void readplayfile();

	// �÷��̸���Ʈ�� ���� ����
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

	//���� �����Ű�� ���� �Ķ����
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

	//������� ui slot �Լ�
	void addtoplaylist_clicked();
	void search_textEdited(const QString& _search);
	void searchcombo_activated(const QString& _search);
	void searchbutton_clicked();
	void logout_clicked();
	void playbutton_clicked();
	int stopbutton_clicked();

};
