#pragma once
#include <qlistwidget.h>

class ToDoListWidgetItem :
	public QListWidgetItem
{
public:
	ToDoListWidgetItem(QString name, int listId);
	int GetListId();

	~ToDoListWidgetItem();

private:
	int listId;
};