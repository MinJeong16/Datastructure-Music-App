#pragma once

#include <QDialog>
#include "ui_identiwidget.h"
#include <qmessagebox.h>
#include "UserType.h"
#include "AvlTree.h"
#include "joinwidget.h"
#include "identifyadminwidget.h"
#include <fstream>
using namespace std;

namespace Ui 
{
	class identiwidget;
}

//메인 화면 ui
class identiwidget : public QDialog
{
	Q_OBJECT

public:
	identiwidget(QWidget *parent = Q_NULLPTR);
	~identiwidget();
	//유저파일을 읽어들임
	void getuserfile();
	//유저를 리턴
	UserType getUser() const;

private slots:
	//메인화면 ui slot 함수
	void adminPB_Clicked();
	void joinPB_Clicked();
	void loginPB_Clicked();
	void id_TextChanged(const QString &str);
	void pw_TextChanged(const QString &str);
	void exit_clicked();

private:
	Ui::identiwidget *ui;
	ifstream m_InFile;
	ofstream m_OutFile;
	AvlTree<UserType> UserList;
	UserType user;
	string id;
	string pw;

};
