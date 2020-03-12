#include "stdafx.h"
#include "UIRemoveTaskObserver.h"
#include "TaskManagerMainWindow.h"

UIRemoveTaskObserver::UIRemoveTaskObserver(TaskManagerMainWindow *mainWindow) : UITaskObserver(mainWindow)
{
}

UIRemoveTaskObserver::~UIRemoveTaskObserver()
{
}

void UIRemoveTaskObserver::update(QListWidget * currentTaskList, QListWidgetItem *currentListItem)
{
	if (currentListItem != NULL && typeid(*currentListItem) == typeid(ToDoListWidgetItem))
	{
		auto todoListItem = static_cast<ToDoListWidgetItem*>(currentListItem);

		if (!todoListItem->text().contains(mainWindow->important))
		{
			int listId = todoListItem->GetListId();
			auto todoList = tdManager->GetListByID(listId);

			auto taskListItem = currentTaskList->takeItem(currentTaskList->currentRow());

			if (taskListItem != NULL)
			{
				auto taskItem = static_cast<TaskWidgetItem*>(taskListItem);
				auto task = taskItem->GetTask();

				todoList->RemoveTask(task);
				delete taskListItem;

				ui->listWidgetTaskInfo->clear();
				currentTaskList->clearSelection();
				mainWindow->RefreshImportantList(task, currentTaskList, taskListItem);
				tdManager->SaveToJson(mainWindow->filePath);
			}
		}
	}
}
