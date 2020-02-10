#pragma once
#include "UIObserver.h"
#include "ToDoListWidgetItem.h"
#include "CreateListDialog.h"

class UIModifyListObserver :
	public UIObserver
{
public:
	UIModifyListObserver(Ui_TaskManagerMainWindowClass *ui, ToDoListManager *tdManager);

	void update(QListWidgetItem * currentItem);

	~UIModifyListObserver();
};