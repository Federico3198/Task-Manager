﻿#include "stdafx.h"
#include "TaskManagerMainWindow.h"

TaskManagerMainWindow::TaskManagerMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	tdManager = ToDoListManager();

	/*std::fstream fs;

	fs.open(filePath, std::fstream::in | std::fstream::out | std::fstream::trunc);
*/
//if (fs.is_open())
//{
//	//fs.open(fileName, std::fstream::in | std::fstream::out | std::fstream::trunc);
//	fs << "{}" << std::endl; //BUG non scrive in realtà
//	fs.close();
//}


	tdManager.LoadFromJson(filePath);
	RefreshUI();

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

		tdManager.SaveToJson(filePath);
	}
}

void TaskManagerMainWindow::on_actionDeleteList_triggered()
{
	auto currentItem = ui.listWidgetLists->takeItem(ui.listWidgetLists->currentRow());

	auto listItem = static_cast<ToDoListWidgetItem*>(currentItem);
	int listId = listItem->GetListId();

	tdManager.RemoveList(listId);

	delete currentItem;
	tdManager.SaveToJson(filePath);
}

void TaskManagerMainWindow::on_listWidgetLists_currentRowChanged(int currentRow)
{
	ui.listWidgetUncompletedTasks->clear();
	ui.listWidgetCompletedTasks->clear();
	ui.listWidgetTaskInfo->clear();

	auto currentItem = ui.listWidgetLists->item(currentRow);
	auto listItem = static_cast<ToDoListWidgetItem*>(currentItem);
	int listId = listItem->GetListId();

	auto todoList = tdManager.GetListByID(listId);
	auto uncompletedTasks = todoList->GetUncompletedTasks();

	for (auto tasksIterator = uncompletedTasks.begin(); tasksIterator != uncompletedTasks.end(); tasksIterator++)
	{
		ui.listWidgetUncompletedTasks->addItem(new TaskWidgetItem(*tasksIterator));
	}

	auto completedTasks = todoList->GetCompletedTasks();

	for (auto tasksIterator = completedTasks.begin(); tasksIterator != completedTasks.end(); tasksIterator++)
	{
		ui.listWidgetCompletedTasks->addItem(new TaskWidgetItem(*tasksIterator));
	}
}

void TaskManagerMainWindow::on_actionAddTask_triggered()
{
	auto currentItem = ui.listWidgetLists->currentItem();
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
			sharedTask->expire = createTaskDialog.GetCheckExpire()->checkState();

			todoList->AddTask(sharedTask);
			ui.listWidgetUncompletedTasks->addItem(new TaskWidgetItem(sharedTask));

			tdManager.SaveToJson(filePath);
		}
	}
}

void TaskManagerMainWindow::on_actionRemoveTask_triggered()
{
	//get todolist
	auto currentList = ui.listWidgetLists->item(ui.listWidgetLists->currentRow());
	auto todoListItem = static_cast<ToDoListWidgetItem*>(currentList);
	int listId = todoListItem->GetListId();
	auto todoList = tdManager.GetListByID(listId);

	auto listWidget = GetSelectedTaskList();
	auto taskListItem = listWidget->takeItem(listWidget->currentRow());

	if (taskListItem != NULL)
	{
		auto taskItem = static_cast<TaskWidgetItem*>(taskListItem);
		auto task = taskItem->GetTask();

		//remove task
		todoList->RemoveTask(task);
		delete taskListItem;

		ui.listWidgetTaskInfo->clear();
		listWidget->clearSelection();
		tdManager.SaveToJson(filePath);
	}
	else
	{
		//TODO avverti utente che non ha selezionato nulla
	}
}

void TaskManagerMainWindow::on_listWidgetUncompletedTasks_itemClicked(QListWidgetItem * listWidgetItem)
{
	ui.listWidgetCompletedTasks->clearSelection();
	ShowTaskInfo(listWidgetItem);
}


void TaskManagerMainWindow::on_listWidgetCompletedTasks_itemClicked(QListWidgetItem * listWidgetItem)
{
	ui.listWidgetUncompletedTasks->clearSelection();
	ShowTaskInfo(listWidgetItem);
}

void TaskManagerMainWindow::on_actionSet_CompletedTask_triggered()
{
	if (ui.listWidgetUncompletedTasks->selectedItems().length() > 0)
	{
		auto taskListItem = ui.listWidgetUncompletedTasks->takeItem(ui.listWidgetUncompletedTasks->currentRow());
		auto taskItem = static_cast<TaskWidgetItem*>(taskListItem);
		auto task = taskItem->GetTask();
		task->isCompleted = true;

		ui.listWidgetCompletedTasks->addItem(taskListItem);
		ui.listWidgetUncompletedTasks->clearSelection();
		ui.listWidgetCompletedTasks->clearSelection();
		ui.listWidgetCompletedTasks->setCurrentItem(taskListItem);
		ShowTaskInfo(taskListItem);
		tdManager.SaveToJson(filePath);
	}
}

void TaskManagerMainWindow::on_actionSet_UncompletedTask_triggered()
{
	if (ui.listWidgetCompletedTasks->selectedItems().length() > 0)
	{
		auto taskListItem = ui.listWidgetCompletedTasks->takeItem(ui.listWidgetCompletedTasks->currentRow());
		auto taskItem = static_cast<TaskWidgetItem*>(taskListItem);
		auto task = taskItem->GetTask();
		task->isCompleted = false;

		ui.listWidgetUncompletedTasks->addItem(taskListItem);
		ui.listWidgetUncompletedTasks->clearSelection();
		ui.listWidgetCompletedTasks->clearSelection();
		ui.listWidgetUncompletedTasks->setCurrentItem(taskListItem);
		ShowTaskInfo(taskListItem);
		tdManager.SaveToJson(filePath);
	}
}

void TaskManagerMainWindow::on_actionAdd_Sub_Task_triggered()
{
	auto listWidget = GetSelectedTaskList();
	auto taskListItem = listWidget->item(listWidget->currentRow());
	if (taskListItem != NULL)
	{
		auto taskItem = static_cast<TaskWidgetItem*>(taskListItem);
		auto task = taskItem->GetTask();


		CreateSubTaskDialog createSubTaskDialog;
		createSubTaskDialog.setModal(true);
		int result = createSubTaskDialog.exec();

		if (result == 1)
		{
			auto text = createSubTaskDialog.GetText()->text().toStdString();

			SubTask* subTask;
			subTask = new SubTask(text);
			task->AddSubTask(std::shared_ptr<SubTask>(subTask));
			ShowTaskInfo(taskListItem);

			tdManager.SaveToJson(filePath);
		}
	}
}

void TaskManagerMainWindow::on_actionRemove_Sub_Task_triggered()
{
	auto subTaskListItem = ui.listWidgetTaskInfo->item(ui.listWidgetTaskInfo->currentRow());
	auto listWidget = GetSelectedTaskList();
	auto taskListItem = listWidget->item(listWidget->currentRow());

	if (taskListItem != NULL && subTaskListItem != NULL && typeid(*subTaskListItem) == typeid(SubTaskWidgetItem))
	{
		auto subTaskItem = static_cast<SubTaskWidgetItem *>(subTaskListItem);
		auto subTask = subTaskItem->GetSubTask();

		auto taskItem = static_cast<TaskWidgetItem*>(taskListItem);
		auto task = taskItem->GetTask();

		task->RemoveSubTask(subTask);

		ShowTaskInfo(taskListItem);
		tdManager.SaveToJson(filePath);
	}
}

void TaskManagerMainWindow::on_actionSet_Sub_Task_Completed_triggered()
{
	SetSubTaskCompleted(true);
	tdManager.SaveToJson(filePath);
}

void TaskManagerMainWindow::on_actionSet_Sub_Task_Uncompleted_triggered()
{
	SetSubTaskCompleted(false);
	tdManager.SaveToJson(filePath);
}

void TaskManagerMainWindow::on_actionModifyList_triggered()
{
	CreateListDialog createListDialog;
	createListDialog.setModal(true);

	auto currentList = ui.listWidgetLists->item(ui.listWidgetLists->currentRow());
	auto todoListItem = static_cast<ToDoListWidgetItem*>(currentList);
	int listId = todoListItem->GetListId();
	auto todoList = tdManager.GetListByID(listId);

	createListDialog.SetFieldListName(QString(todoList->listName.c_str()));

	int result = createListDialog.exec();

	if (result == 1)
	{
		auto fieldlistName = createListDialog.GetFieldListName();
		auto listName = fieldlistName->text();

		todoList->listName = listName.toStdString();

		todoListItem->setText(QString(todoList->listName.c_str()));
		tdManager.SaveToJson(filePath);
	}
}

void TaskManagerMainWindow::on_actionModifyTask_triggered()
{
	auto listWidget = GetSelectedTaskList();

	CreateTaskDialog createTaskDialog;
	createTaskDialog.setModal(true);

	auto taskListItem = listWidget->item(listWidget->currentRow());
	if (taskListItem != NULL)
	{
		auto taskItem = static_cast<TaskWidgetItem*>(taskListItem);
		auto task = taskItem->GetTask();

		createTaskDialog.SetName(QString(task->title.c_str()));
		createTaskDialog.SetCheckIsImportant(task->isImportant);
		createTaskDialog.SetCheckExpire(task->expire);
		createTaskDialog.SetRepetition(task->repetition);
		createTaskDialog.SetNotes(QString(task->notes.c_str()));
		createTaskDialog.SetDueDate(task->dueDate);

		int result = createTaskDialog.exec();

		if (result == 1)
		{
			auto fieldTaskName = createTaskDialog.GetName();
			auto taskName = fieldTaskName->text();
			task->title = taskName.toStdString();

			task->isImportant = createTaskDialog.GetCheckIsImportant()->checkState();
			task->expire = createTaskDialog.GetCheckExpire()->checkState();
			task->repetition = RepetitionTypeUtils::ConvertItaToEnum(createTaskDialog.GetRepetition()->currentText().toStdString());
			task->notes = createTaskDialog.GetNotes()->toPlainText().toStdString();
			task->dueDate = DateTime(createTaskDialog.GetDueDate()->dateTime().toTime_t());

			taskListItem->setText(taskName);
			ShowTaskInfo(taskListItem);
			tdManager.SaveToJson(filePath);
		}
	}
	else
	{
		//TODO avverti utente
	}

}

void TaskManagerMainWindow::on_actionModify_Sub_Task_triggered()
{
	auto subTaskListItem = ui.listWidgetTaskInfo->item(ui.listWidgetTaskInfo->currentRow());
	auto listWidget = GetSelectedTaskList();
	auto taskListItem = listWidget->item(listWidget->currentRow());

	if (taskListItem != NULL && subTaskListItem != NULL && typeid(*subTaskListItem) == typeid(SubTaskWidgetItem))
	{
		auto subTaskItem = static_cast<SubTaskWidgetItem *>(subTaskListItem);
		auto subTask = subTaskItem->GetSubTask();

		CreateSubTaskDialog createSubTaskDialog;
		createSubTaskDialog.setModal(true);


		createSubTaskDialog.SetText(QString(subTask->GetText().c_str()));

		int result = createSubTaskDialog.exec();

		if (result == 1)
		{
			auto text = createSubTaskDialog.GetText()->text().toStdString();

			subTask->SetText(text);

			tdManager.SaveToJson(filePath);
		}

		ShowTaskInfo(taskListItem);
	}
}

void TaskManagerMainWindow::SetSubTaskCompleted(bool isCompleted)
{
	auto subTaskListItem = ui.listWidgetTaskInfo->item(ui.listWidgetTaskInfo->currentRow());

	auto listWidget = GetSelectedTaskList();
	auto taskListItem = listWidget->item(listWidget->currentRow());

	if (taskListItem != NULL && subTaskListItem != NULL && typeid(*subTaskListItem) == typeid(SubTaskWidgetItem))
	{
		auto subTaskItem = static_cast<SubTaskWidgetItem *>(subTaskListItem);
		auto subTask = subTaskItem->GetSubTask();

		subTask->SetIsCompleted(isCompleted);

		ShowTaskInfo(taskListItem);
	}
}

void TaskManagerMainWindow::RefreshUI()
{
	auto toDoLists = tdManager.GetToDoLists();

	for (auto todoListIterator = toDoLists.begin(); todoListIterator != toDoLists.end(); todoListIterator++)
	{
		auto listItem = new ToDoListWidgetItem(QString((*todoListIterator)->listName.c_str()), (*todoListIterator)->GetId());
		ui.listWidgetLists->addItem(listItem);
	}
}

void TaskManagerMainWindow::ShowTaskInfo(QListWidgetItem *taskListItem)
{
	auto taskItem = static_cast<TaskWidgetItem*>(taskListItem);
	auto task = taskItem->GetTask();

	ui.listWidgetTaskInfo->clear();

	ui.listWidgetTaskInfo->addItem(new QListWidgetItem(QString(task->title.c_str())));

	ui.listWidgetTaskInfo->addItem(new QListWidgetItem(QString(("Completato: " + BoolUtils::ConvertBoolToYesNoIta(task->isCompleted)).c_str())));
	ui.listWidgetTaskInfo->addItem(new QListWidgetItem(QString(("Importante: " + BoolUtils::ConvertBoolToYesNoIta(task->isImportant)).c_str())));

	if (task->expire)
	{
		std::stringstream stringStream;
		stringStream << "Scadenza: " << task->dueDate.GetDay() << "-" << task->dueDate.GetMonth() << "-" << task->dueDate.GetYear();
		std::string date = stringStream.str();
		ui.listWidgetTaskInfo->addItem(new QListWidgetItem(QString(date.c_str())));

		stringStream = std::stringstream();
		stringStream << "Ricordamelo alle: " << task->dueDate.GetHours() << ":";

		if (task->dueDate.GetMinutes() < 10)
		{
			stringStream << "0";
		}
		stringStream << task->dueDate.GetMinutes();

		std::string time = stringStream.str();
		ui.listWidgetTaskInfo->addItem(new QListWidgetItem(QString(time.c_str())));
	}

	ui.listWidgetTaskInfo->addItem(new QListWidgetItem(QString(("Ripetizione: " + RepetitionTypeUtils::ConvertEnumToIta(task->repetition)).c_str())));

	if (!task->notes.empty())
	{
		ui.listWidgetTaskInfo->addItem(new QListWidgetItem(QString(("Note: " + task->notes).c_str())));
	}

	auto subTasks = task->GetSubTasks();

	if (subTasks.size() > 0) {
		ui.listWidgetTaskInfo->addItem(new QListWidgetItem(QString("Sotto Task:")));

		for (auto subTasksIterator = subTasks.begin(); subTasksIterator != subTasks.end(); subTasksIterator++)
		{
			ui.listWidgetTaskInfo->addItem(new SubTaskWidgetItem((*subTasksIterator)));
		}
	}

	//"☑⬜"
	//"►"
}

QListWidget * TaskManagerMainWindow::GetSelectedTaskList()
{
	auto selectedListItemUncompleted = ui.listWidgetUncompletedTasks->selectedItems();
	auto listItemUncompleted = selectedListItemUncompleted.length() > 0 ? selectedListItemUncompleted.first() : NULL;

	auto selectedListItemCompleted = ui.listWidgetCompletedTasks->selectedItems();
	auto listItemCompleted = selectedListItemCompleted.length() > 0 ? selectedListItemCompleted.first() : NULL;


	auto listWidget = (listItemCompleted != NULL ? ui.listWidgetCompletedTasks : ui.listWidgetUncompletedTasks);

	return listWidget;
}




