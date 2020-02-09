#include "stdafx.h"
#include "UITaskObserver.h"


UITaskObserver::UITaskObserver(Ui_TaskManagerMainWindowClass *ui, ToDoListManager *tdManager) : UIObserver(ui,tdManager)
{
}


UITaskObserver::~UITaskObserver()
{
}
//
//void UITaskObserver::RefreshImportantList(std::shared_ptr<Task>& task, QListWidget * listWidget, QListWidgetItem * taskListItem)
//{
//	/*if (tdManager->GetImportantTasks().size() > 0)
//	{
//		if (ui->listWidgetLists->item(0)->text().compare(important) != 0)
//		{
//			auto listItem = new ToDoListWidgetItem(QString(important), -1);
//			ui->listWidgetLists->insertItem(0, listItem);
//		}
//		else if (ui->listWidgetLists->currentRow() == 0 && !task->isImportant)
//		{
//			delete listWidget->takeItem(listWidget->row(taskListItem));
//			ui->listWidgetTaskInfo->clear();
//		}
//	}
//	else if (ui->listWidgetLists->item(0)->text().compare(important) == 0)
//	{
//		delete ui->listWidgetLists->takeItem(0);
//	}*/
//}
