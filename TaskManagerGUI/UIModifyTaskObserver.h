#pragma once
#include "UITaskObserver.h"
#include "createtaskdialog.h"
#include "UISubTaskObserver.h"

class UIModifyTaskObserver :
	public UITaskObserver
{
public:
	UIModifyTaskObserver(TaskManagerMainWindow *mainWindow);
	~UIModifyTaskObserver();

	void update(QListWidgetItem *currentItem, QListWidget *currentList);
};