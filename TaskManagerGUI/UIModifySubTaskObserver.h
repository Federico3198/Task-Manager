#pragma once
#include "UIObserverEmpty.h"
#include "CreateSubTaskDialog.h"

class UIModifySubTaskObserver :
	public UIObserverEmpty
{
public:
	UIModifySubTaskObserver(TaskManagerMainWindow *mainWindow);
	~UIModifySubTaskObserver();

	void update() override;
};