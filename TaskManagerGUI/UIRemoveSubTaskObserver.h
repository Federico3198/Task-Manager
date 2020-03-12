#pragma once
#include "UIObserverEmpty.h"

class UIRemoveSubTaskObserver :
	public UIObserverEmpty
{
public:
	UIRemoveSubTaskObserver(TaskManagerMainWindow *mainWindow);
	~UIRemoveSubTaskObserver();

	void update() override;

};