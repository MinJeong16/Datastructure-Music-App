#include "identifyadminwidget.h"

//������ ������ ���� ui ������
identifyadminwidget::identifyadminwidget(QWidget *parent)
	: QDialog(parent),ui(new Ui::identifyadminwidget)
{
	ui->setupUi(this);
}

//�Ҹ���
identifyadminwidget::~identifyadminwidget()
{
	delete ui;
}

///////// ui slot �Լ�//////////
void identifyadminwidget::admin_textChanged(const QString &_adminnum)
{
	adminnum = _adminnum.toStdString();
}

void identifyadminwidget::admin_clicked()
{
	if (adminnum.empty())
		QMessageBox::information(this, QString::fromLocal8Bit("����!!"), QString::fromLocal8Bit("�����ڹ�ȣ�� �Է��ϼ���!"));
	else if (adminnum != "1234")
		QMessageBox::information(this, QString::fromLocal8Bit("����!!"), QString::fromLocal8Bit("�����ڹ�ȣ�� ��ġ���� �ʽ��ϴ�."));
	else
	{
		done(QDialog::Accepted);
	}

}
