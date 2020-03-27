#pragma once

#include <QDialog>
#include "ui_joinwidget.h"
#include <qmessagebox.h>
#include "UserType.h"
#include "AvlTree.h"
#include <iostream>
#include <string>
using namespace std;

namespace Ui {
	class joinwidget;
}

//ȸ�������� ���� ui
class joinwidget : public QDialog
{
	Q_OBJECT

public:
	joinwidget(QWidget *parent = Q_NULLPTR);
	~joinwidget();
	//������ ����
	UserType getuser() const;

private slots:
	//ȸ������ ui slot �Լ�
	void join_Clicked();
	void joinid_textChanged(const QString &_id);
	void joinpw_textChanged(const QString &_pw); 
	void joinnickname_textChanged(const QString &_nickname);
	void joinphone_textChanged(const QString &_phone);
	void joinemail_textChanged(const QString &_email);


private:
	Ui::joinwidget *ui;
	UserType user;
	AvlTree<UserType> UserList;
	string id;
	string pw;
	string nickname;
	string phone;
	string email;
};
