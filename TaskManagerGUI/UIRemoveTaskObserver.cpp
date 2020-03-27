#include "stdafx.h"
#include "UIRemoveTaskObserver.h"
#include "TaskManagerMainWindow.h"

UIRemoveTaskObserver::UIRemoveTaskObserver(TaskManagerMainWindow *mainWindow) : UIObserverEmpty(mainWindow)
{
}

UIRemoveTaskObserver::~UIRemoveTaskObserver()
{
}

void UIRemoveTaskObserver::update()
{
	auto currentListItem = ui->listWidgetLists->item(ui->listWidgetLists->currentRow());
	auto currentTaskList = mainWindow->GetSelectedTaskList();

	if (currentListItem != NULL && typeid(*currentListItem) == typeid(ToDoListWidgetItem))
	{
		auto todoListItem = static_cast<ToDoListWidgetItem*>(currentListItem);

		if (!todoListItem->text().contains(mainWindow->important))
		{
			int listId = todoListItem->GetListId();
			auto todoList = tdManager->GetListByID(listId);

			auto taskListItem = currentTaskList->takeItem(currentTaskList->currentRow());

			if (taskListItem != NULL && typeid(*taskListItem) == typeid(TaskWidgetItem))
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

	mainWindow->RefreshUI();
}
