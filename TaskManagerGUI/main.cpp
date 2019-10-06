#include "stdafx.h"
#include "TaskManagerMainWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//QTextCodec::setCodecForCStrings(QTextCodec::codecForUtfText(""));
	TaskManagerMainWindow w;
	w.show();
	return a.exec();
}
