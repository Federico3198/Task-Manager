#pragma once
#include "CreateSubTaskDialog.h"
#include "UIObserverListItem.h"

class UIAddSubTaskObserver :
	public UIObserverListItem
{
public:
	UIAddSubTaskObserver(TaskManagerMainWindow *mainWindow);
	~UIAddSubTaskObserver();

	void update(QListWidgetItem *currentItem) override;
};