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

			todoList->AddTask(sharedTask);
			ui.listWidgetUncompletedTasks->addItem(new TaskWidgetItem(sharedTask));
		}
	}
	else 
	{
		//TODO dialogo "devi selezionare una lista prima di aggiungere una task"
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
	auto taskItem = static_cast<TaskWidgetItem*>(taskListItem);
	auto task = taskItem->GetTask();

	//remove task
	todoList->RemoveTask(task);
	delete taskListItem;

	ui.listWidgetTaskInfo->clear();
	listWidget->clearSelection();
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
	}
}

void TaskManagerMainWindow::on_actionAdd_Sub_Task_triggered()
{
	auto listWidget = GetSelectedTaskList();
	auto taskListItem = listWidget->item(listWidget->currentRow());
	if(taskListItem!=NULL)
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
			}
	}
	else
	{
		//TODO MessageBox: devi selezionare una task
	}
}

void TaskManagerMainWindow::on_actionRemove_Sub_Task_triggered()
{
	auto subTaskListItem = ui.listWidgetTaskInfo->item(ui.listWidgetTaskInfo->currentRow());
	auto listWidget = GetSelectedTaskList();
	auto taskListItem = listWidget->takeItem(listWidget->currentRow());

	if (taskListItem !=NULL && subTaskListItem != NULL && typeid(*subTaskListItem) == typeid(SubTaskWidgetItem))
	{
		auto subTaskItem = static_cast<SubTaskWidgetItem *>(subTaskListItem);
		auto subTask = subTaskItem->GetSubTask();


		auto taskItem = static_cast<TaskWidgetItem*>(taskListItem);
		auto task = taskItem->GetTask();

		task->RemoveSubTask(subTask);

		ShowTaskInfo(taskListItem);
		
		FixRandomClearTaskListBug();
	}
	else
	{
		// se no messaggio all' utente che deve selezionare una sub task
	}
}

void TaskManagerMainWindow::on_actionSet_Sub_Task_Completed_triggered()
{
	SetSubTaskCompleted(true);
}

void TaskManagerMainWindow::on_actionSet_Sub_Task_Uncompleted_triggered()
{
	SetSubTaskCompleted(false);
}

void TaskManagerMainWindow::SetSubTaskCompleted(bool isCompleted)
{
	auto subTaskListItem = ui.listWidgetTaskInfo->item(ui.listWidgetTaskInfo->currentRow());

	auto listWidget = GetSelectedTaskList();
	auto taskListItem = listWidget->takeItem(listWidget->currentRow());

	if (taskListItem !=NULL && subTaskListItem != NULL && typeid(*subTaskListItem) == typeid(SubTaskWidgetItem))
	{
		auto subTaskItem = static_cast<SubTaskWidgetItem *>(subTaskListItem);
		auto subTask = subTaskItem->GetSubTask();

		subTask->SetIsCompleted(isCompleted);

		ShowTaskInfo(taskListItem);
		FixRandomClearTaskListBug();
	}
}

#pragma region  fix random task list clear bug

void TaskManagerMainWindow::FixRandomClearTaskListBug()
{

	ui.listWidgetUncompletedTasks->clear();
	ui.listWidgetCompletedTasks->clear();

	auto currentItem = ui.listWidgetLists->item(ui.listWidgetLists->currentRow());
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
#pragma endregion

void TaskManagerMainWindow::ShowTaskInfo(QListWidgetItem *taskListItem)
{
	auto taskItem = static_cast<TaskWidgetItem*>(taskListItem);
	auto task = taskItem->GetTask();

	ui.listWidgetTaskInfo->clear();

	ui.listWidgetTaskInfo->addItem(new QListWidgetItem(QString(task->title.c_str())));

	ui.listWidgetTaskInfo->addItem(new QListWidgetItem(QString(("Completato: " + BoolUtils::ConvertBoolToYesNoIta(task->isCompleted)).c_str())));
	ui.listWidgetTaskInfo->addItem(new QListWidgetItem(QString(("Importante: " + BoolUtils::ConvertBoolToYesNoIta(task->isImportant)).c_str())));

	
	//TODO mettere un check nel form per settare la scadenza
	std::stringstream stringStream;
	stringStream << "Scadenza: " << task->dueDate.GetDay() << "-" << task->dueDate.GetMonth() << "-" << task->dueDate.GetYear();
	std::string date = stringStream.str();
	ui.listWidgetTaskInfo->addItem(new QListWidgetItem(QString(date.c_str())));

	stringStream = std::stringstream();
	stringStream << "Ricordamelo alle: " << task->dueDate.GetHours() << ":" << task->dueDate.GetMinutes();
	std::string time = stringStream.str();
	ui.listWidgetTaskInfo->addItem(new QListWidgetItem(QString(time.c_str())));
	//--------------------------------


	ui.listWidgetTaskInfo->addItem(new QListWidgetItem(QString(("Ripetizione: " + RepetitionTypeUtils::ConvertEnumToIta(task->repetition)).c_str())));
	
	ui.listWidgetTaskInfo->addItem(new QListWidgetItem(QString(("Note: " + task->notes).c_str())));
	

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




