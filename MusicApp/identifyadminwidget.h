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
//�����ڸ�� ������ ���� ui
class identifyadminwidget : public QDialog
{
	Q_OBJECT

public:
	identifyadminwidget(QWidget *parent = Q_NULLPTR);
	~identifyadminwidget();

private slots:
	//�����ڸ�� ui slot �Լ�
	void admin_textChanged(const QString &_adminnum);
	void admin_clicked();

private:
	Ui::identifyadminwidget *ui;
	string adminnum;
};
