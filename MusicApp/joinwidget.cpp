#include "joinwidget.h"

//ȸ������ ui ������
joinwidget::joinwidget(QWidget *parent)
	: QDialog(parent),ui(new Ui::joinwidget)
{
	ui->setupUi(this);
}
//�Ҹ���
joinwidget::~joinwidget()
{
	delete ui;
}
//������ ����
UserType joinwidget::getuser() const
{
	return user;
}
///////// ui slot �Լ� /////////
void joinwidget::join_Clicked()
{
	UserType temp;
	temp.SetUserID(id);

	bool found;
	UserList.RetrieveItem(temp, found);

	if(id.empty() || pw.empty() || 
		nickname.empty() || phone.empty() || email.empty())
		QMessageBox::information(this, QString::fromLocal8Bit("����!!"), QString::fromLocal8Bit("��� ������ �Է����ּ���!"));
	else if(found)
		QMessageBox::information(this, QString::fromLocal8Bit("����!!"), QString::fromLocal8Bit("���� ������ ���� ȸ���� �̹� �����մϴ�!"));
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
