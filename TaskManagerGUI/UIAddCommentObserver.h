#pragma once
#include "UIObserver.h"
#include "TaskWidgetItem.h"
#include "AddCommentDialog.h"
#include "CommentWidgetItem.h"

class UIAddCommentObserver :
	public UIObserver
{
public:
	UIAddCommentObserver(Ui_TaskManagerMainWindowClass * ui, ToDoListManager * tdManager);
	~UIAddCommentObserver();

	void update(QListWidgetItem * currentItem);
};