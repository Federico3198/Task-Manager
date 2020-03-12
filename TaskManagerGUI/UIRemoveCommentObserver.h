#pragma once
#include "UIObserver.h"
#include "TaskWidgetItem.h"
#include "CommentWidgetItem.h"
#include "UIObserverListItem.h"

class UIRemoveCommentObserver :
	public UIObserverListItem
{
public:
	UIRemoveCommentObserver(TaskManagerMainWindow *mainWindow);
	~UIRemoveCommentObserver();

	void update(QListWidgetItem *currentItem) override;
};