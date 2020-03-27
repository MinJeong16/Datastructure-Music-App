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

//���� ȭ�� ui
class identiwidget : public QDialog
{
	Q_OBJECT

public:
	identiwidget(QWidget *parent = Q_NULLPTR);
	~identiwidget();
	//���������� �о����
	void getuserfile();
	//������ ����
	UserType getUser() const;

private slots:
	//����ȭ�� ui slot �Լ�
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
