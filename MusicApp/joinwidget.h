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

//회원가입을 위한 ui
class joinwidget : public QDialog
{
	Q_OBJECT

public:
	joinwidget(QWidget *parent = Q_NULLPTR);
	~joinwidget();
	//유저를 리턴
	UserType getuser() const;

private slots:
	//회원가입 ui slot 함수
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
