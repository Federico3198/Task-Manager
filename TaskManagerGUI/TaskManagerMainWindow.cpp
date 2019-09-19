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
	CreateListDialog createListDialog;
	createListDialog.setModal(true);
	int result = createListDialog.exec();

	if (result == 1)
	{
		auto fieldlistName = createListDialog.GetFieldListName();
		auto listName = fieldlistName->text();
		ToDoList td = ToDoList(listName.toStdString());
		tdManager.AddList(td);

		auto listItem = new ToDoListWidgetItem(listName, td.GetId());

		ui.listWidgetLists->addItem(listItem);
	}
}

void TaskManagerMainWindow::on_actionDeleteList_triggered()
{
	auto currentItem = ui.listWidgetLists->takeItem(ui.listWidgetLists->currentRow());

	auto listItem = static_cast<ToDoListWidgetItem*>(currentItem);
	int listId = listItem->GetListId();

	tdManager.RemoveList(listId);

	delete currentItem;
}



void TaskManagerMainWindow::on_listWidgetLists_currentRowChanged(int currentRow) //TODO fill completed task list
{
	ui.listWidgetTasks->clear();
	
	auto currentItem = ui.listWidgetLists->item(currentRow);
	auto listItem = static_cast<ToDoListWidgetItem*>(currentItem);
	int listId = listItem->GetListId();

	auto todoList = tdManager.GetListByID(listId);
	auto tasks = todoList.GetUncompletedTasks(); 
	
	for (auto tasksIterator = tasks.begin(); tasksIterator != tasks.end(); tasksIterator++)
	{
		ui.listWidgetTasks->addItem(new TaskWidgetItem(*tasksIterator));
	}
}
