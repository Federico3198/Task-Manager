#pragma once
#include "UISubTaskObserver.h"

class UISetSubTaskCompletionObserver :
	public UISubTaskObserver
{
public:
	UISetSubTaskCompletionObserver(TaskManagerMainWindow *mainWindow);
	~UISetSubTaskCompletionObserver();

	void update(QListWidgetItem *currentTaskItem, QListWidgetItem *currentSubTaskItem, bool isCompleted);
};