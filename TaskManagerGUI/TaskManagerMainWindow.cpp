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
		std::shared_ptr<ToDoList> sharedTDL(new ToDoList(listName.toStdString()));
		tdManager.AddList(sharedTDL);

		auto listItem = new ToDoListWidgetItem(listName, sharedTDL->GetId());

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
	auto tasks = todoList->GetUncompletedTasks();

	for (auto tasksIterator = tasks.begin(); tasksIterator != tasks.end(); tasksIterator++)
	{
		ui.listWidgetTasks->addItem(new TaskWidgetItem(*tasksIterator));
	}
}

void TaskManagerMainWindow::on_actionAddTask_triggered()
{
	auto currentItem = ui.listWidgetLists->item(ui.listWidgetLists->currentRow());
	if (currentItem != NULL)
	{
		auto listItem = static_cast<ToDoListWidgetItem*>(currentItem);
		int listId = listItem->GetListId();

		auto todoList = tdManager.GetListByID(listId);

		CreateTaskDialog createTaskDialog;
		createTaskDialog.setModal(true);
		int result = createTaskDialog.exec();

		if (result == 1)
		{
			auto fieldTaskName = createTaskDialog.GetName();
			auto taskName = fieldTaskName->text();
			Task *task = new Task(taskName.toStdString());
			std::shared_ptr<Task> sharedTask(task);

			sharedTask->isImportant = createTaskDialog.GetCheckIsImportant()->checkState();
			sharedTask->repetition = RepetitionTypeUtils::ConvertItaToEnum(createTaskDialog.GetRepetition()->currentText().toStdString());
			sharedTask->notes = createTaskDialog.GetNotes()->toPlainText().toStdString();
			sharedTask->dueDate = DateTime(createTaskDialog.GetDueDate()->dateTime().toTime_t());

			todoList->AddTask(sharedTask);
			ui.listWidgetTasks->addItem(new TaskWidgetItem(sharedTask));
		}
	}
	else 
	{
		//TODO dialogo "devi selezionare una lista prima di aggiungere una task"
	}
}

void TaskManagerMainWindow::on_actionRemoveTask_triggered()
{
	//TODO implementare pls
}

