#pragma once
#include "UISubTaskObserver.h"
#include "CreateSubTaskDialog.h"

class UIModifySubTaskObserver :
	public UISubTaskObserver
{
public:
	UIModifySubTaskObserver(Ui_TaskManagerMainWindowClass * ui, ToDoListManager * tdManager);
	~UIModifySubTaskObserver();

	void update(QListWidgetItem *currentTaskItem, QListWidgetItem  *currentSubTaskItem);
};