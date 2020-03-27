#include "identiwidget.h"

//메인 화면 생성자
identiwidget::identiwidget(QWidget *parent)
	: QDialog(parent),ui(new Ui::identiwidget)
{
	ui->setupUi(this);
	getuserfile();
}
//소멸자
identiwidget::~identiwidget()
{
	delete ui;
}

//유저 파일을 읽어들임
void identiwidget::getuserfile()
{
	m_InFile.open("userinfo.txt");
	if (m_InFile.is_open())
	{
		UserType temp;
		while (!m_InFile.eof())
		{
			temp.ReadDataFromFile(m_InFile);
			UserList.Add(temp);
		}
		m_InFile.close();
	}
}
//유저를 리턴
UserType identiwidget::getUser() const
{
	return user;
}

//////////// ui slot 함수 //////////////
void identiwidget::adminPB_Clicked()
{
	identifyadminwidget adminlogin;
	int res = adminlogin.exec();
	if (res == QDialog::Accepted)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("관리자모드"), QString::fromLocal8Bit("관리자인증이 완료되었습니다!"));
		done(QDialog::Changed);
	}
}

void identiwidget::joinPB_Clicked()
{
	joinwidget joinwidget;
	int res = joinwidget.exec();
	if (res == QDialog::Accepted)
	{
		UserList.Add(joinwidget.getuser());
		m_OutFile.open("userinfo.txt");
		if (m_OutFile)
		{
			UserList.WriteUser(m_OutFile);
		}
		m_OutFile.close();
		QMessageBox::information(this, QString::fromLocal8Bit("회원가입"), QString::fromLocal8Bit("회원가입이 완료되었습니다!"));
	}
}

void identiwidget::loginPB_Clicked()
{
	UserType temp;
	temp.SetUserID(user.GetUserID());

	bool found;
	UserList.RetrieveItem(temp, found);

	if (id.empty() || pw.empty())
		QMessageBox::information(this, QString::fromLocal8Bit("에러!!"), QString::fromLocal8Bit("입력되지 않은 항목이 존재합니다!"));
	else if (found)
	{//기존 유저리스트에서 발견하면
		if (temp.GetUserPW() != user.GetUserPW())
			QMessageBox::information(this, QString::fromLocal8Bit("에러!!"), QString::fromLocal8Bit("비밀번호가 틀렸어요!"));
		else
			done(QDialog::Accepted);
	}
	else
		QMessageBox::information(this, QString::fromLocal8Bit("에러!!"), QString::fromLocal8Bit("아이디가 틀렸어요!"));

}

void identiwidget::id_TextChanged(const QString & _id)
{
	id = _id.toLocal8Bit();
	user.SetUserID(id);
}

void identiwidget::pw_TextChanged(const QString & _pw)
{
	pw = _pw.toLocal8Bit();
	user.SetUserPW(pw);
}

void identiwidget::exit_clicked()
{
	QMessageBox msg;
	msg.setText(QString::fromLocal8Bit("종료하시겠습니까?"));
	msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	msg.setDefaultButton(QMessageBox::Ok);
	if (msg.exec() == QMessageBox::Ok)
		done(QDialog::Rejected);
}
