#include "stdafx.h"
#include "TaskManagerMainWindow.h"

TaskManagerMainWindow::TaskManagerMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	tdManager = ToDoListManager();
}

void TaskManagerMainWindow::on_actionCreateList_triggered()
{
	//TODO chiedere il nome della lista all' utente
	ToDoList td = ToDoList("Test");
	tdManager.toDoLists.push_back(td);
}
