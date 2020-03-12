#pragma once
#include "UIObserver.h"
#include "TaskWidgetItem.h"
#include "AddCommentDialog.h"
#include "CommentWidgetItem.h"
#include "UIObserverListItem.h"

class UIAddCommentObserver :
	public UIObserverListItem
{
public:
	UIAddCommentObserver(TaskManagerMainWindow *mainWindow);
	~UIAddCommentObserver();

	void update(QListWidgetItem * currentItem) override;
};