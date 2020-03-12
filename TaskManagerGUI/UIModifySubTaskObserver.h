#pragma once
#include "UISubTaskObserver.h"
#include "CreateSubTaskDialog.h"

class UIModifySubTaskObserver :
	public UISubTaskObserver
{
public:
	UIModifySubTaskObserver(TaskManagerMainWindow *mainWindow);
	~UIModifySubTaskObserver();

	void update(QListWidgetItem *currentTaskItem, QListWidgetItem  *currentSubTaskItem);
};