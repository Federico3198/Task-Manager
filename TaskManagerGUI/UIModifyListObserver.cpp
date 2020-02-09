#include "stdafx.h"
#include "UIModifyListObserver.h"


UIModifyListObserver::UIModifyListObserver(Ui_TaskManagerMainWindowClass * ui, ToDoListManager * tdManager) : UIObserver(ui,tdManager)
{
}

void UIModifyListObserver::update(QListWidgetItem * currentItem)
{
	auto todoListItem = static_cast<ToDoListWidgetItem*>(currentItem);

	if (todoListItem->text().compare(important) != 0)
	{
		CreateListDialog createListDialog;
		createListDialog.setModal(true);

		int listId = todoListItem->GetListId();
		auto todoList = tdManager->GetListByID(listId);

		createListDialog.SetFieldListName(QString(todoList->listName.c_str()));

		int result = createListDialog.exec();

		if (result == 1)
		{
			auto fieldlistName = createListDialog.GetFieldListName();
			auto listName = fieldlistName->text();

			todoList->listName = listName.toStdString();

			todoListItem->setText(QString(todoList->listName.c_str()));
			tdManager->SaveToJson(filePath);
		}
	}
}

UIModifyListObserver::~UIModifyListObserver()
{
}
