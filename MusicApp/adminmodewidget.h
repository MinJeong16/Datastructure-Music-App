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

//�����ڸ�� ���� ui
class adminmodewidget : public QMainWindow
{
	Q_OBJECT

public:
	adminmodewidget(QWidget *parent = Q_NULLPTR);
	~adminmodewidget();
	
	//ȭ�鿡 �� ����� ���÷���
	void displayAll();

	// �� ����
	int Replace(MusicType& data);

	// �� �߰�
	int Add(MusicType &music);

	//���Ͽ� ����
	void savefile();

	//���Ͽ��� �о���̱�
	int readfile();

private slots:
	//ui slot �Լ�
	void adminexit_clicked();
	void selectfile_clicked();
	void addmusic_clicked();
	void replacemusic_clicked();
	void selectdelete_clicked();
	void alldelete_clicked();

	//checkbox�� üũ�Ǿ����� Ȯ���ϴ� �Լ�
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
