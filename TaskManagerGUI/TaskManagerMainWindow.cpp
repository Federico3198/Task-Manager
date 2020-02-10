#include "stdafx.h"
#include "TaskManagerMainWindow.h"

TaskManagerMainWindow::TaskManagerMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	tdManager = ToDoListManager();
	tdManager.LoadFromJson(filePath);

	createListObserver = new UICreateListObserver(&ui, &tdManager);
	removeListObserver = new UIRemoveListObserver(&ui, &tdManager);
	modifyListObserver = new UIModifyListObserver(&ui, &tdManager);

	addTaskObserver = new UIAddTaskObserver(&ui, &tdManager);
	removeTaskObserver = new UIRemoveTaskObserver(&ui, &tdManager);
	setTaskCompletionObserver = new UISetTaskCompletionObserver(&ui, &tdManager);
	modifyTaskObserver = new UIModifyTaskObserver(&ui, &tdManager);

	addCommentObserver = new UIAddCommentObserver(&ui, &tdManager);
	removeCommentObserver = new UIRemoveCommentObserver(&ui, &tdManager);

	addSubTaskObserver = new UIAddSubTaskObserver(&ui, &tdManager);
	removeSubTaskObserver = new UIRemoveSubTaskObserver(&ui, &tdManager);
	modifySubTaskObserver = new UIModifySubTaskObserver(&ui, &tdManager);
	setSubTaskCompletionObserver = new UISetSubTaskCompletionObserver(&ui, &tdManager);

	RefreshUI();
}

void TaskManagerMainWindow::on_actionCreateList_triggered()
{
	createListObserver->update();
}

void TaskManagerMainWindow::on_actionDeleteList_triggered()
{
	auto currentItem = ui.listWidgetLists->item(ui.listWidgetLists->currentRow());
	removeListObserver->update(currentItem);
}

void TaskManagerMainWindow::on_listWidgetLists_itemClicked(QListWidgetItem *item)
{
	ui.listWidgetUncompletedTasks->clear();
	ui.listWidgetCompletedTasks->clear();
	ui.listWidgetTaskInfo->clear();
	ui.listWidgetComments->clear();

	auto currentItem = item;
	auto listItem = static_cast<ToDoListWidgetItem*>(currentItem);

	if (listItem->text().compare(important) == 0)
	{
		ui.listWidgetCompletedTasks->clear();

		auto uncompletedTasks = tdManager.GetImportantTasks();

		for (auto tasksIterator = uncompletedTasks.begin(); tasksIterator != uncompletedTasks.end(); tasksIterator++)
		{
			ui.listWidgetUncompletedTasks->addItem(new TaskWidgetItem(*tasksIterator));
		}
	}
	else
	{
		int listId = listItem->GetListId();
		auto todoList = tdManager.GetListByID(listId);

		if (todoList != NULL)
		{
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
	}
}

void TaskManagerMainWindow::on_actionAddTask_triggered()
{
	auto currentItem = ui.listWidgetLists->currentItem();
	addTaskObserver->update(currentItem);
	RefreshUI();
}

void TaskManagerMainWindow::on_actionRemoveTask_triggered()
{
	auto listWidgetItem = ui.listWidgetLists->item(ui.listWidgetLists->currentRow());
	auto listWidget = GetSelectedTaskList();

	removeTaskObserver->update(listWidget, listWidgetItem);
	RefreshUI();
}

void TaskManagerMainWindow::on_listWidgetUncompletedTasks_itemClicked(QListWidgetItem * listWidgetItem)
{
	if (listWidgetItem != NULL && typeid(*listWidgetItem) == typeid(TaskWidgetItem))
	{
		ui.listWidgetCompletedTasks->clearSelection();
		ShowTaskInfo(listWidgetItem);
	}
}

void TaskManagerMainWindow::on_listWidgetCompletedTasks_itemClicked(QListWidgetItem * listWidgetItem)
{
	if (listWidgetItem != NULL && typeid(*listWidgetItem) == typeid(TaskWidgetItem))
	{
		ui.listWidgetUncompletedTasks->clearSelection();
		ShowTaskInfo(listWidgetItem);
	}
}

void TaskManagerMainWindow::on_actionSet_CompletedTask_triggered()
{
	setTaskCompletionObserver->update(true);
	RefreshUI();
}

void TaskManagerMainWindow::on_actionSet_UncompletedTask_triggered()
{
	setTaskCompletionObserver->update(false);
	RefreshUI();
}

void TaskManagerMainWindow::on_actionAdd_Sub_Task_triggered()
{
	auto listWidget = GetSelectedTaskList();
	auto taskListItem = listWidget->item(listWidget->currentRow());
	addSubTaskObserver->update(taskListItem);
}

void TaskManagerMainWindow::on_actionRemove_Sub_Task_triggered()
{
	auto subTaskListItem = ui.listWidgetTaskInfo->item(ui.listWidgetTaskInfo->currentRow());
	auto listWidget = GetSelectedTaskList();
	auto taskListItem = listWidget->item(listWidget->currentRow());
	removeSubTaskObserver->update(taskListItem, subTaskListItem);
}

void TaskManagerMainWindow::on_actionSet_Sub_Task_Completed_triggered()
{
	auto subTaskListItem = ui.listWidgetTaskInfo->item(ui.listWidgetTaskInfo->currentRow());
	auto listWidget = GetSelectedTaskList();
	auto taskListItem = listWidget->item(listWidget->currentRow());

	setSubTaskCompletionObserver->update(taskListItem, subTaskListItem, true);
}

void TaskManagerMainWindow::on_actionSet_Sub_Task_Uncompleted_triggered()
{
	auto subTaskListItem = ui.listWidgetTaskInfo->item(ui.listWidgetTaskInfo->currentRow());
	auto listWidget = GetSelectedTaskList();
	auto taskListItem = listWidget->item(listWidget->currentRow());

	setSubTaskCompletionObserver->update(taskListItem, subTaskListItem, false);
}

void TaskManagerMainWindow::on_actionModifyList_triggered()
{
	auto currentList = ui.listWidgetLists->item(ui.listWidgetLists->currentRow());
	modifyListObserver->update(currentList);
}

void TaskManagerMainWindow::on_actionModifyTask_triggered()
{
	auto listWidget = GetSelectedTaskList();
	auto taskListItem = listWidget->item(listWidget->currentRow());

	modifyTaskObserver->update(taskListItem, listWidget);
	RefreshUI();
}

void TaskManagerMainWindow::RefreshImportantList(std::shared_ptr<Task> &task, QListWidget * listWidget, QListWidgetItem * taskListItem)
{
	if (tdManager.GetImportantTasks().size() > 0)
	{
		if (ui.listWidgetLists->item(0)->text().compare(important) != 0)
		{
			auto listItem = new ToDoListWidgetItem(QString(important), -1);
			ui.listWidgetLists->insertItem(0, listItem);
		}
		else if (ui.listWidgetLists->currentRow() == 0 && !task->isImportant)
		{
			delete listWidget->takeItem(listWidget->row(taskListItem));
			ui.listWidgetTaskInfo->clear();
		}
	}
	else if (ui.listWidgetLists->item(0)->text().compare(important) == 0)
	{
		delete ui.listWidgetLists->takeItem(0);
	}
}

void TaskManagerMainWindow::on_actionModify_Sub_Task_triggered()
{
	auto subTaskListItem = ui.listWidgetTaskInfo->item(ui.listWidgetTaskInfo->currentRow());
	auto listWidget = GetSelectedTaskList();
	auto taskListItem = listWidget->item(listWidget->currentRow());

	modifySubTaskObserver->update(taskListItem, subTaskListItem);
}

void TaskManagerMainWindow::on_actionAdd_Comment_triggered()
{
	auto listWidget = GetSelectedTaskList();
	auto taskListItem = listWidget->item(listWidget->currentRow());
	addCommentObserver->update(taskListItem);
}

void TaskManagerMainWindow::on_actionRemove_Comment_triggered()
{
	auto listWidget = GetSelectedTaskList();
	auto taskListItem = listWidget->item(listWidget->currentRow());
	removeCommentObserver->update(taskListItem);
}

void TaskManagerMainWindow::on_fieldSearch_textChanged(const QString & searchText)
{
	ui.listWidgetCompletedTasks->clear();
	ui.listWidgetUncompletedTasks->clear();
	ui.listWidgetLists->clearSelection();

	auto pairs = tdManager.Find(searchText.toStdString());

	if (pairs.size() > 0)
	{
		bool isListCompltetedAdded = false;
		bool isListUncompltetedAdded = false;

		std::shared_ptr<ToDoList> previousList = NULL;

		for (auto pairIterator = pairs.begin(); pairIterator != pairs.end(); pairIterator++)
		{
			auto task = (*pairIterator).task;
			auto list = (*pairIterator).list;

			if (previousList != list)
			{
				isListCompltetedAdded = false;
				isListUncompltetedAdded = false;
			}

			TaskWidgetItem *taskItem = new TaskWidgetItem(task);

			if (task->isCompleted)
			{
				if (!isListCompltetedAdded)
				{
					std::stringstream stringStream;
					stringStream << list->listName << ":";

					QListWidgetItem *listNameItem = new QListWidgetItem(QString(stringStream.str().c_str()));
					ui.listWidgetCompletedTasks->addItem(listNameItem);
					isListCompltetedAdded = true;
				}

				ui.listWidgetCompletedTasks->addItem(taskItem);
			}
			else
			{
				if (!isListUncompltetedAdded)
				{
					std::stringstream stringStream;
					stringStream << list->listName << ":";

					QListWidgetItem *listNameItem = new QListWidgetItem(QString(stringStream.str().c_str()));
					ui.listWidgetUncompletedTasks->addItem(listNameItem);
					isListUncompltetedAdded = true;
				}

				ui.listWidgetUncompletedTasks->addItem(taskItem);
			}

			previousList = list;
		}
	}
}

void TaskManagerMainWindow::RefreshUI()
{
	auto toDoLists = tdManager.GetToDoLists();

	auto row = ui.listWidgetLists->currentRow();

	ui.listWidgetLists->clear();

	if (tdManager.GetImportantTasks().size() > 0)
	{
		auto listName = important;
		auto listItemCount = tdManager.GetImportantTasks().size();

		std::stringstream stringStream;
		stringStream << listName;// << " [" << listItemCount << "]";

		auto listItem = new ToDoListWidgetItem(QString(stringStream.str().c_str()), -1);
		ui.listWidgetLists->addItem(listItem);
	}

	for (auto todoListIterator = toDoLists.begin(); todoListIterator != toDoLists.end(); todoListIterator++)
	{
		auto currentToDoList = *todoListIterator;
		auto listName = currentToDoList->listName;
		auto listItemCount = currentToDoList->GetUncompletedTaskCount();

		std::stringstream stringStream;
		stringStream << listName << " [" << listItemCount << "]";

		auto listItem = new ToDoListWidgetItem(QString(stringStream.str().c_str()), (*todoListIterator)->GetId());
		ui.listWidgetLists->addItem(listItem);
	}

	ui.listWidgetLists->setCurrentRow(row-1);
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

	auto comments = task->GetComments();
	ui.listWidgetComments->clear();
	if (comments.size() > 0)
	{
		for (auto commentsIterator = comments.begin(); commentsIterator != comments.end(); commentsIterator++)
		{
			ui.listWidgetComments->addItem(new CommentWidgetItem((*commentsIterator)));
		}
	}
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
