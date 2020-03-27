#pragma once

#include <QDialog>
#include "ui_identifyadminwidget.h"
#include <qmessagebox.h>
#include "adminmodewidget.h"
#include <string>
using namespace std;

namespace Ui
{
	class identifyadminwidget;
}
//관리자모드 인증을 위한 ui
class identifyadminwidget : public QDialog
{
	Q_OBJECT

public:
	identifyadminwidget(QWidget *parent = Q_NULLPTR);
	~identifyadminwidget();

private slots:
	//관리자모드 ui slot 함수
	void admin_textChanged(const QString &_adminnum);
	void admin_clicked();

private:
	Ui::identifyadminwidget *ui;
	string adminnum;
};
