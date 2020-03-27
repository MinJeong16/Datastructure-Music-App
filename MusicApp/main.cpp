#include "QtGuiApplication1.h"
#include "adminmodewidget.h"
#include <QtWidgets/QApplication>
#include <qfontdatabase.h>
#include <qlabel.h>
#include <qwidget.h>

//뮤직플레이어를 구동시키기 위한 메인 함수
int main(int argc, char *argv[])
{
//	w.setStyleSheet("background:rgb(237,246,255)");
//	ad.setStyleSheet("background:rgb(237,246,255)");
//	i_widget.setStyleSheet("background:rgb(237,246,255)");
	
	QApplication a(argc, argv);
	QFont f;
	QtGuiApplication1 w;
	adminmodewidget ad;
	identiwidget i;

	f.setFamily("NanumGothic");
	a.setFont(f);

	int det = i.exec();
	if (det == QDialog::Rejected)
		return 0;
	else if (det == QDialog::Changed)
		ad.show();
	else
		w.show();
	
	return a.exec();
}
