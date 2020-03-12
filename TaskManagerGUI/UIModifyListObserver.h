#pragma once
#include "UIObserver.h"
#include "ToDoListWidgetItem.h"
#include "CreateListDialog.h"
#include "UIObserverListItem.h"

class UIModifyListObserver :
	public UIObserverListItem
{
public:
	UIModifyListObserver(TaskManagerMainWindow *mainWindow);

	void update(QListWidgetItem * currentItem) override;

	~UIModifyListObserver();
};