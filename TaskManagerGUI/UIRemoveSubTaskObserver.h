#pragma once
#include "UISubTaskObserver.h"

class UIRemoveSubTaskObserver :
	public UISubTaskObserver
{
public:
	UIRemoveSubTaskObserver(TaskManagerMainWindow *mainWindow);
	~UIRemoveSubTaskObserver();

	void update(QListWidgetItem *currentTaskItem, QListWidgetItem *currentSubTaskItem);

};