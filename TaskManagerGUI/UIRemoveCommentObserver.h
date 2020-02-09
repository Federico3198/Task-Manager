#pragma once
#include "UIObserver.h"
#include "TaskWidgetItem.h"
#include "CommentWidgetItem.h"

class UIRemoveCommentObserver :
	public UIObserver
{
public:
	UIRemoveCommentObserver(Ui_TaskManagerMainWindowClass * ui, ToDoListManager * tdManager);
	~UIRemoveCommentObserver();

	void update(QListWidgetItem *currentItem);
};

