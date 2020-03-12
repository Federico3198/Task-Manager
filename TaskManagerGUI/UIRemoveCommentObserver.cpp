#include "stdafx.h"
#include "UIRemoveCommentObserver.h"
#include "TaskManagerMainWindow.h"

UIRemoveCommentObserver::UIRemoveCommentObserver(TaskManagerMainWindow *mainWindow) : UIObserverListItem(mainWindow)
{
}

UIRemoveCommentObserver::~UIRemoveCommentObserver()
{
}

void UIRemoveCommentObserver::update(QListWidgetItem * currentItem)
{
	if (currentItem != NULL && typeid(*currentItem) == typeid(TaskWidgetItem))
	{
		auto commentListItem = ui->listWidgetComments->item(ui->listWidgetComments->currentRow());

		if (commentListItem != NULL)
		{
			commentListItem = ui->listWidgetComments->takeItem(ui->listWidgetComments->currentRow());
			auto commentItem = static_cast<CommentWidgetItem*>(commentListItem);

			auto taskItem = static_cast<TaskWidgetItem*>(currentItem);
			auto task = taskItem->GetTask();

			task->RemoveComment(commentItem->GetComment());

			tdManager->SaveToJson(mainWindow->filePath);
		}
	}
}
