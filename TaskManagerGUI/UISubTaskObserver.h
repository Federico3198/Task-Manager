#pragma once
#include "UIObserver.h"
#include "TaskWidgetItem.h"
#include "SubTaskWidgetItem.h"
#include "CommentWidgetItem.h"

class UISubTaskObserver :
	public UIObserver
{
public:
	UISubTaskObserver(TaskManagerMainWindow *mainWindow);
	~UISubTaskObserver();
};