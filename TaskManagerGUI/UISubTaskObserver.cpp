#include "stdafx.h"
#include "UISubTaskObserver.h"

UISubTaskObserver::UISubTaskObserver(Ui_TaskManagerMainWindowClass * ui, ToDoListManager * tdManager) : UIObserver(ui,tdManager)
{
}

UISubTaskObserver::~UISubTaskObserver()
{
}

void UISubTaskObserver::ShowTaskInfo(QListWidgetItem * taskListItem)
{
	auto taskItem = static_cast<TaskWidgetItem*>(taskListItem);
	auto task = taskItem->GetTask();

	ui->listWidgetTaskInfo->clear();

	ui->listWidgetTaskInfo->addItem(new QListWidgetItem(QString(task->title.c_str())));

	ui->listWidgetTaskInfo->addItem(new QListWidgetItem(QString(("Completato: " + BoolUtils::ConvertBoolToYesNoIta(task->isCompleted)).c_str())));
	ui->listWidgetTaskInfo->addItem(new QListWidgetItem(QString(("Importante: " + BoolUtils::ConvertBoolToYesNoIta(task->isImportant)).c_str())));

	if (task->expire)
	{
		std::stringstream stringStream;
		stringStream << "Scadenza: " << task->dueDate.GetDay() << "-" << task->dueDate.GetMonth() << "-" << task->dueDate.GetYear();
		std::string date = stringStream.str();
		ui->listWidgetTaskInfo->addItem(new QListWidgetItem(QString(date.c_str())));

		stringStream = std::stringstream();
		stringStream << "Ricordamelo alle: " << task->dueDate.GetHours() << ":";

		if (task->dueDate.GetMinutes() < 10)
		{
			stringStream << "0";
		}
		stringStream << task->dueDate.GetMinutes();

		std::string time = stringStream.str();
		ui->listWidgetTaskInfo->addItem(new QListWidgetItem(QString(time.c_str())));
	}

	ui->listWidgetTaskInfo->addItem(new QListWidgetItem(QString(("Ripetizione: " + RepetitionTypeUtils::ConvertEnumToIta(task->repetition)).c_str())));

	if (!task->notes.empty())
	{
		ui->listWidgetTaskInfo->addItem(new QListWidgetItem(QString(("Note: " + task->notes).c_str())));
	}

	auto subTasks = task->GetSubTasks();

	if (subTasks.size() > 0) {
		ui->listWidgetTaskInfo->addItem(new QListWidgetItem(QString("Sotto Task:")));

		for (auto subTasksIterator = subTasks.begin(); subTasksIterator != subTasks.end(); subTasksIterator++)
		{
			ui->listWidgetTaskInfo->addItem(new SubTaskWidgetItem((*subTasksIterator)));
		}
	}

	auto comments = task->GetComments();
	ui->listWidgetComments->clear();
	if (comments.size() > 0)
	{
		for (auto commentsIterator = comments.begin(); commentsIterator != comments.end(); commentsIterator++)
		{
			ui->listWidgetComments->addItem(new CommentWidgetItem((*commentsIterator)));
		}
	}
}
