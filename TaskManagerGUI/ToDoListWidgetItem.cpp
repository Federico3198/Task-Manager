#include "stdafx.h"
#include "ToDoListWidgetItem.h"


ToDoListWidgetItem::ToDoListWidgetItem(QString name, int listId)
{
	setText(name);
	this->listId = listId;
}

int ToDoListWidgetItem::GetListId()
{
	return listId;
}


ToDoListWidgetItem::~ToDoListWidgetItem()
{
}
