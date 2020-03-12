#include "stdafx.h"
#include "UIModifyTaskObserver.h"
#include "TaskManagerMainWindow.h"

UIModifyTaskObserver::UIModifyTaskObserver(TaskManagerMainWindow *mainWindow) : UITaskObserver(mainWindow)
{
}

UIModifyTaskObserver::~UIModifyTaskObserver()
{
}

void UIModifyTaskObserver::update(QListWidgetItem * currentItem, QListWidget *currentList)
{
	if (currentItem != NULL && typeid(*currentItem) == typeid(TaskWidgetItem))
	{
		CreateTaskDialog createTaskDialog;
		createTaskDialog.setModal(true);

		auto taskItem = static_cast<TaskWidgetItem*>(currentItem);
		auto task = taskItem->GetTask();

		createTaskDialog.SetName(QString(task->title.c_str()));
		createTaskDialog.SetCheckIsImportant(task->isImportant);
		createTaskDialog.SetCheckExpire(task->expire);
		createTaskDialog.SetRepetition(task->repetition);
		createTaskDialog.SetNotes(QString(task->notes.c_str()));
		createTaskDialog.SetDueDate(task->dueDate);

		int result = createTaskDialog.exec();

		if (result == 1)
		{
			auto fieldTaskName = createTaskDialog.GetName();
			auto taskName = fieldTaskName->text();
			task->title = taskName.toStdString();

			task->isImportant = createTaskDialog.GetCheckIsImportant()->checkState();
			task->expire = createTaskDialog.GetCheckExpire()->checkState();
			task->repetition = RepetitionTypeUtils::ConvertItaToEnum(createTaskDialog.GetRepetition()->currentText().toStdString());
			task->notes = createTaskDialog.GetNotes()->toPlainText().toStdString();
			task->dueDate = DateTime(createTaskDialog.GetDueDate()->dateTime().toTime_t());

			currentItem->setText(taskName);
			mainWindow->ShowTaskInfo(currentItem);
			mainWindow->RefreshImportantList(task, currentList, currentItem);

			tdManager->SaveToJson(mainWindow->filePath);
		}
	}
}
