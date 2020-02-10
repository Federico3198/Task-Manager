#include "stdafx.h"
#include "UIRemoveCommentObserver.h"

UIRemoveCommentObserver::UIRemoveCommentObserver(Ui_TaskManagerMainWindowClass * ui, ToDoListManager * tdManager) :  UIObserver(ui,tdManager)
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

			tdManager->SaveToJson(filePath);
		}
	}
}
