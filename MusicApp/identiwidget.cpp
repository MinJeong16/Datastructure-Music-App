#include "identiwidget.h"

//���� ȭ�� ������
identiwidget::identiwidget(QWidget *parent)
	: QDialog(parent),ui(new Ui::identiwidget)
{
	ui->setupUi(this);
	getuserfile();
}
//�Ҹ���
identiwidget::~identiwidget()
{
	delete ui;
}

//���� ������ �о����
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
//������ ����
UserType identiwidget::getUser() const
{
	return user;
}

//////////// ui slot �Լ� //////////////
void identiwidget::adminPB_Clicked()
{
	identifyadminwidget adminlogin;
	int res = adminlogin.exec();
	if (res == QDialog::Accepted)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("�����ڸ��"), QString::fromLocal8Bit("������������ �Ϸ�Ǿ����ϴ�!"));
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
		QMessageBox::information(this, QString::fromLocal8Bit("ȸ������"), QString::fromLocal8Bit("ȸ�������� �Ϸ�Ǿ����ϴ�!"));
	}
}

void identiwidget::loginPB_Clicked()
{
	UserType temp;
	temp.SetUserID(user.GetUserID());

	bool found;
	UserList.RetrieveItem(temp, found);

	if (id.empty() || pw.empty())
		QMessageBox::information(this, QString::fromLocal8Bit("����!!"), QString::fromLocal8Bit("�Էµ��� ���� �׸��� �����մϴ�!"));
	else if (found)
	{//���� ��������Ʈ���� �߰��ϸ�
		if (temp.GetUserPW() != user.GetUserPW())
			QMessageBox::information(this, QString::fromLocal8Bit("����!!"), QString::fromLocal8Bit("��й�ȣ�� Ʋ�Ⱦ��!"));
		else
			done(QDialog::Accepted);
	}
	else
		QMessageBox::information(this, QString::fromLocal8Bit("����!!"), QString::fromLocal8Bit("���̵� Ʋ�Ⱦ��!"));

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
	msg.setText(QString::fromLocal8Bit("�����Ͻðڽ��ϱ�?"));
	msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	msg.setDefaultButton(QMessageBox::Ok);
	if (msg.exec() == QMessageBox::Ok)
		done(QDialog::Rejected);
}
