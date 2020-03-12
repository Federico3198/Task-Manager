#pragma once
#include "UITaskObserver.h"
#include "TaskWidgetItem.h"
#include "createtaskdialog.h"
#include "UIObserverListItem.h"

class UIAddTaskObserver :
	public UIObserverListItem
{
public:
	UIAddTaskObserver(TaskManagerMainWindow *mainWindow);
	~UIAddTaskObserver();

	void update(QListWidgetItem *currentItem) override;
};