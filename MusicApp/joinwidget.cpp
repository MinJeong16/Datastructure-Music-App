#include "joinwidget.h"

//회원가입 ui 생성자
joinwidget::joinwidget(QWidget *parent)
	: QDialog(parent),ui(new Ui::joinwidget)
{
	ui->setupUi(this);
}
//소멸자
joinwidget::~joinwidget()
{
	delete ui;
}
//유저를 리턴
UserType joinwidget::getuser() const
{
	return user;
}
///////// ui slot 함수 /////////
void joinwidget::join_Clicked()
{
	UserType temp;
	temp.SetUserID(id);

	bool found;
	UserList.RetrieveItem(temp, found);

	if(id.empty() || pw.empty() || 
		nickname.empty() || phone.empty() || email.empty())
		QMessageBox::information(this, QString::fromLocal8Bit("에러!!"), QString::fromLocal8Bit("모든 정보를 입력해주세요!"));
	else if(found)
		QMessageBox::information(this, QString::fromLocal8Bit("에러!!"), QString::fromLocal8Bit("같은 정보를 가진 회원이 이미 존재합니다!"));
	else
	{
		user.SetUserID(id);
		user.SetUserPW(pw);
		user.SetUserNickName(nickname);
		user.SetUserPhone(phone);
		user.SetUserMail(email);

		UserList.Add(user);

		accept();
	}
}

void joinwidget::joinid_textChanged(const QString & _id)
{
	id = _id.toLocal8Bit();
}

void joinwidget::joinpw_textChanged(const QString & _pw)
{
	pw = _pw.toLocal8Bit();
}

void joinwidget::joinnickname_textChanged(const QString & _nickname)
{
	nickname = _nickname.toLocal8Bit();
}

void joinwidget::joinphone_textChanged(const QString & _phone)
{
	phone = _phone.toLocal8Bit();
}

void joinwidget::joinemail_textChanged(const QString & _email)
{
	email = _email.toLocal8Bit();
}
