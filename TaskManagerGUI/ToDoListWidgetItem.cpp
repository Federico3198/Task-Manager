#include "stdafx.h"
#include "ToDoListWidgetItem.h"

ToDoListWidgetItem::ToDoListWidgetItem(QString name, int listId)
{
	setText(name);
	this->listId = listId;
}

int ToDoListWidgetItem::GetListId()
{
	if (this != NULL)
	{
		return listId;
	}
	else
	{
		return 0;
	}
}

ToDoListWidgetItem::~ToDoListWidgetItem()
{
}
