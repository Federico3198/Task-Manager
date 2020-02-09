#include "stdafx.h"
#include "UIAddCommentObserver.h"


UIAddCommentObserver::UIAddCommentObserver(Ui_TaskManagerMainWindowClass * ui, ToDoListManager * tdManager) : UIObserver(ui,tdManager)
{
}

UIAddCommentObserver::~UIAddCommentObserver()
{
}

void UIAddCommentObserver::update(QListWidgetItem * currentItem)
{

	if (currentItem != NULL && typeid(*currentItem) == typeid(TaskWidgetItem))
	{
		AddCommentDialog dialog;
		dialog.setModal(true);
		auto taskItem = static_cast<TaskWidgetItem*>(currentItem);
		auto task = taskItem->GetTask();

		if (dialog.exec() == 1)
		{
			DateTime today = DateTime::GetToday();
			std::string  owner = dialog.GetOwnerField()->text().toStdString();
			std::string text = dialog.GetCommentText()->toPlainText().toStdString();

			std::shared_ptr<Comment> sharedComment(new Comment(owner, text, today));

			task->AddComment(sharedComment);

			ui->listWidgetComments->addItem(new CommentWidgetItem(sharedComment));

			tdManager->SaveToJson(filePath);
		}
	}
}
