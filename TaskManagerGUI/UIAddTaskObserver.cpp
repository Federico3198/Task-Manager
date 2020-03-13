#include "stdafx.h"
#include "UIAddTaskObserver.h"
#include "TaskManagerMainWindow.h"

UIAddTaskObserver::UIAddTaskObserver(TaskManagerMainWindow *mainWindow) : UIObserverListItem(mainWindow)
{
}

UIAddTaskObserver::~UIAddTaskObserver()
{
}

void UIAddTaskObserver::update(QListWidgetItem * currentItem)
{
	if (currentItem != NULL && ui->listWidgetLists->isItemSelected(currentItem) && !currentItem->text().contains(mainWindow->important))
	{
		auto listItem = static_cast<ToDoListWidgetItem*>(currentItem);
		int listId = listItem->GetListId();

		auto todoList = tdManager->GetListByID(listId);

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
			ui->listWidgetUncompletedTasks->addItem(listItem);

			mainWindow->RefreshImportantList(sharedTask, ui->listWidgetUncompletedTasks, listItem);

			tdManager->SaveToJson(mainWindow->filePath);
		}
	}

	mainWindow->RefreshUI();
}
