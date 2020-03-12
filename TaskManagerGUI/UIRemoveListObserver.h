#pragma once
#include "UIObserver.h"
#include "ToDoListWidgetItem.h"
#include "UIObserverListItem.h"

class UIRemoveListObserver :
	public UIObserverListItem
{
public:

	void update(QListWidgetItem *currentItem) override;

	UIRemoveListObserver(TaskManagerMainWindow *mainWindow);
	~UIRemoveListObserver();
};