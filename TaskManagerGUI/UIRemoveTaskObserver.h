#pragma once
#include "UITaskObserver.h"


class UIRemoveTaskObserver :
	public UITaskObserver
{
public:
	UIRemoveTaskObserver(Ui_TaskManagerMainWindowClass * ui, ToDoListManager * tdManager);
	~UIRemoveTaskObserver();

	void update(QListWidget * currentTaskList, QListWidgetItem *currentListItem);
};