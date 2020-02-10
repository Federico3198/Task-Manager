#pragma once
#include "UISubTaskObserver.h"

class UIRemoveSubTaskObserver :
	public UISubTaskObserver
{
public:
	UIRemoveSubTaskObserver(Ui_TaskManagerMainWindowClass * ui, ToDoListManager * tdManager);
	~UIRemoveSubTaskObserver();

	void update(QListWidgetItem *currentTaskItem, QListWidgetItem *currentSubTaskItem);

};