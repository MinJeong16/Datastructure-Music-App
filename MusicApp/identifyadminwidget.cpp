#include "identifyadminwidget.h"

//관리자 인증을 위한 ui 생성자
identifyadminwidget::identifyadminwidget(QWidget *parent)
	: QDialog(parent),ui(new Ui::identifyadminwidget)
{
	ui->setupUi(this);
}

//소멸자
identifyadminwidget::~identifyadminwidget()
{
	delete ui;
}

///////// ui slot 함수//////////
void identifyadminwidget::admin_textChanged(const QString &_adminnum)
{
	adminnum = _adminnum.toStdString();
}

void identifyadminwidget::admin_clicked()
{
	if (adminnum.empty())
		QMessageBox::information(this, QString::fromLocal8Bit("에러!!"), QString::fromLocal8Bit("관리자번호를 입력하세요!"));
	else if (adminnum != "1234")
		QMessageBox::information(this, QString::fromLocal8Bit("에러!!"), QString::fromLocal8Bit("관리자번호가 일치하지 않습니다."));
	else
	{
		done(QDialog::Accepted);
	}

}
