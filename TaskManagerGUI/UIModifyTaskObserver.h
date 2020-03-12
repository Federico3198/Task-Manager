#pragma once
#include "UIObserverEmpty.h"
#include "createtaskdialog.h"
#include "UISubTaskObserver.h"

class UIModifyTaskObserver :
	public UIObserverEmpty
{
public:
	UIModifyTaskObserver(TaskManagerMainWindow *mainWindow);
	~UIModifyTaskObserver();

	void update() override;
};