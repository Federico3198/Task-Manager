#pragma once
#include "UIObserver.h"

class UIObserverListItem : 
	public UIObserver
{
public:
	UIObserverListItem(TaskManagerMainWindow *mainWindow);

	virtual void update(QListWidgetItem *currentItem) {}
};

