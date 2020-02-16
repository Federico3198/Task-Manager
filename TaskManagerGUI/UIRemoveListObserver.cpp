#include "stdafx.h"
#include "UIRemoveListObserver.h"

void UIRemoveListObserver::update(QListWidgetItem * currentItem)
{
	if (currentItem != NULL && !currentItem->text().contains(important))
	{
		currentItem = ui->listWidgetLists->takeItem(ui->listWidgetLists->currentRow());
		auto listItem = static_cast<ToDoListWidgetItem*>(currentItem);

		int listId = listItem->GetListId();

		tdManager->RemoveList(listId);
		delete currentItem;

		if (tdManager->GetToDoLists().size() == 0)
		{
			ui->listWidgetCompletedTasks->clear();
			ui->listWidgetUncompletedTasks->clear();
			ui->listWidgetTaskInfo->clear();
		}
		tdManager->SaveToJson(filePath);
	}

}

UIRemoveListObserver::UIRemoveListObserver(Ui_TaskManagerMainWindowClass * ui, ToDoListManager * tdManager) : UIObserver(ui, tdManager) {}

UIRemoveListObserver::~UIRemoveListObserver()
{
}
