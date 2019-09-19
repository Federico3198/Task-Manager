#pragma once
#include <qlistwidget.h>
class ToDoListWidgetItem :
	public QListWidgetItem
{
private:
	int listId;
public:
	ToDoListWidgetItem(QString name, int listId);
	int GetListId();
	~ToDoListWidgetItem();

};

