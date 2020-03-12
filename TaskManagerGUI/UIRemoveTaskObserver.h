#pragma once
#include "UITaskObserver.h"

class UIRemoveTaskObserver :
	public UITaskObserver
{
public:
	UIRemoveTaskObserver(TaskManagerMainWindow *mainWindow);
	~UIRemoveTaskObserver();

	void update(QListWidget * currentTaskList, QListWidgetItem *currentListItem);
};