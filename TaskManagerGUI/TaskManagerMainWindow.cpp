#include "stdafx.h"
#include "TaskManagerMainWindow.h"

//Gui da rifare
//task main managerwindow implementare observer
//funzione di ricerca per le task e per le liste
//test per la ricerca
//numerino task non completate


TaskManagerMainWindow::TaskManagerMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	tdManager = ToDoListManager();
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
	auto currentItem = ui.listWidgetLists->item(ui.listWidgetLists->currentRow());

	if (currentItem->text().compare(important) != 0)
	{
		currentItem = ui.listWidgetLists->takeItem(ui.listWidgetLists->currentRow());
		auto listItem = static_cast<ToDoListWidgetItem*>(currentItem);

		int listId = listItem->GetListId();

		tdManager.RemoveList(listId);
		delete currentItem;

		if (tdManager.GetToDoLists().size() == 0)
		{
			ui.listWidgetCompletedTasks->clear();
			ui.listWidgetUncompletedTasks->clear();
			ui.listWidgetTaskInfo->clear();
		}
		tdManager.SaveToJson(filePath);
	}
}

void TaskManagerMainWindow::on_listWidgetLists_currentRowChanged(int currentRow)
{
	ui.listWidgetUncompletedTasks->clear();
	ui.listWidgetCompletedTasks->clear();
	ui.listWidgetTaskInfo->clear();
	ui.listWidgetComments->clear();

	auto currentItem = ui.listWidgetLists->item(currentRow);
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
	if (currentItem != NULL && currentItem->text().compare(important) != 0)
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
			auto listItem = new TaskWidgetItem(sharedTask);
			ui.listWidgetUncompletedTasks->addItem(listItem);

			RefreshImportantList(sharedTask, ui.listWidgetUncompletedTasks, listItem);

			tdManager.SaveToJson(filePath);
		}
	}
}

void TaskManagerMainWindow::on_actionRemoveTask_triggered()
{
	auto currentList = ui.listWidgetLists->item(ui.listWidgetLists->currentRow());
	auto todoListItem = static_cast<ToDoListWidgetItem*>(currentList);

	if (todoListItem->text().compare(important) != 0)
	{
		int listId = todoListItem->GetListId();
		auto todoList = tdManager.GetListByID(listId);

		auto listWidget = GetSelectedTaskList();
		auto taskListItem = listWidget->takeItem(listWidget->currentRow());

		if (taskListItem != NULL)
		{
			auto taskItem = static_cast<TaskWidgetItem*>(taskListItem);
			auto task = taskItem->GetTask();

			todoList->RemoveTask(task);
			delete taskListItem;

			ui.listWidgetTaskInfo->clear();
			listWidget->clearSelection();
			RefreshImportantList(task, listWidget, taskListItem);
			tdManager.SaveToJson(filePath);
		}
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

		if (ui.listWidgetLists->item(ui.listWidgetLists->currentRow())->text().compare(important) == 0)
		{
			ui.listWidgetCompletedTasks->clear();
			ui.listWidgetTaskInfo->clear();
		}
		else
		{
			ShowTaskInfo(taskListItem);
			RefreshImportantList(task, ui.listWidgetCompletedTasks, taskListItem);
		}
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

		RefreshImportantList(task, ui.listWidgetUncompletedTasks, taskListItem);

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
	auto currentList = ui.listWidgetLists->item(ui.listWidgetLists->currentRow());
	auto todoListItem = static_cast<ToDoListWidgetItem*>(currentList);

	if (todoListItem->text().compare(important) != 0)
	{
		CreateListDialog createListDialog;
		createListDialog.setModal(true);

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
			RefreshImportantList(task, listWidget, taskListItem);

			tdManager.SaveToJson(filePath);
		}
	}
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

void TaskManagerMainWindow::on_actionAdd_Comment_triggered()
{
	auto listWidget = GetSelectedTaskList();
	auto taskListItem = listWidget->item(listWidget->currentRow());

	if (taskListItem != NULL)
	{
		AddCommentDialog dialog;
		dialog.setModal(true);
		auto taskItem = static_cast<TaskWidgetItem*>(taskListItem);
		auto task = taskItem->GetTask();

		if (dialog.exec() == 1)
		{
			DateTime today = DateTime::GetToday();
			std::string  owner = dialog.GetOwnerField()->text().toStdString();
			std::string text = dialog.GetCommentText()->toPlainText().toStdString();

			std::shared_ptr<Comment> sharedComment(new Comment(owner, text, today));

			task->AddComment(sharedComment);


			ui.listWidgetComments->addItem(new CommentWidgetItem(sharedComment));

			tdManager.SaveToJson(filePath);
		}
	}
}

void TaskManagerMainWindow::on_actionRemove_Comment_triggered()
{
	auto listWidget = GetSelectedTaskList();
	auto taskListItem = listWidget->item(listWidget->currentRow());

	if (taskListItem != NULL)
	{
		auto commentListItem = ui.listWidgetComments->item(ui.listWidgetComments->currentRow());

		if (commentListItem != NULL)
		{
			commentListItem = ui.listWidgetComments->takeItem(ui.listWidgetComments->currentRow());
			auto commentItem = static_cast<CommentWidgetItem*>(commentListItem);

			auto taskItem = static_cast<TaskWidgetItem*>(taskListItem);
			auto task = taskItem->GetTask();

			task->RemoveComment(commentItem->GetComment());

			tdManager.SaveToJson(filePath);
		}
	}
}

void TaskManagerMainWindow::on_fieldSearch_textChanged(const QString & searchText)
{
	auto text = searchText.toStdString();

	//ricerca nel nome
	//ricerca nel nelle sub task
	//ricerca nelle note

	std::list<std::shared_ptr<Task> > result = std::list<std::shared_ptr<Task> >();

	if (!text.empty())
	{
		auto todoLists = tdManager.GetToDoLists();

		for (auto tdListIterator = todoLists.begin(); tdListIterator != todoLists.end(); tdListIterator++)
		{
			auto tdList = *tdListIterator;
			auto taskList = tdList->GetAllTasks();

			for (auto taskIterator = taskList.begin(); taskIterator != taskList.end(); taskIterator++)
			{
				auto task = *taskIterator;
				if (task->title.find(text) != std::string::npos)
				{
					result.push_back(task);
				}
			}
		}
	}




	//ui.listWidgetSearch->clear();
	ui.listWidgetCompletedTasks->clear();
	ui.listWidgetUncompletedTasks->clear();
	ui.listWidgetLists->clearSelection();

	for (auto resultIterator = result.begin(); resultIterator != result.end(); resultIterator++)
	{
		auto task = *resultIterator;

		TaskWidgetItem *taskItem = new TaskWidgetItem(task);

		if (task->isCompleted)
		{
			ui.listWidgetCompletedTasks->addItem(taskItem);
			//ui.listWidgetSearch->addItem(taskItem);
		}
		else
		{
			ui.listWidgetUncompletedTasks->addItem(taskItem);

		}
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

	ui.listWidgetLists->clear();

	if (tdManager.GetImportantTasks().size() > 0)
	{
		auto listItem = new ToDoListWidgetItem(QString(important), -1);
		ui.listWidgetLists->addItem(listItem);
	}

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
