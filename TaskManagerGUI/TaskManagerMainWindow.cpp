#include "stdafx.h"
#include "TaskManagerMainWindow.h"

TaskManagerMainWindow::TaskManagerMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void TaskManagerMainWindow::on_actionCreateList_triggered()
{
	std::cout << "Aggiunta una nuova lista yeah" << std::endl;
}
