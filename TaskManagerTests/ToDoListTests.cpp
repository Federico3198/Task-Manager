#include "pch.h"
#include "../TaskManager/ToDoList.cpp"
#include "../TaskManager/ToDoList.h"

TEST(ToDoList, GetId_from_multiple_lists_Assert_id_is_unique)
{
	ToDoList list1("");
	ToDoList list2("");
	ToDoList list3("");
	int id1 = list1.GetId();
	int id2 = list2.GetId();
	int id3 = list3.GetId();
	EXPECT_FALSE(id1 == id2);
	EXPECT_FALSE(id1 == id3);
	EXPECT_FALSE(id2 == id3);
}

TEST(ToDoList, AddTask_task_null_Assert_task_not_added)
{
	ToDoList list("");
	list.AddTask(NULL);

	EXPECT_EQ(0, list.GetAllTasks().size());
}

TEST(ToDoList, AddTask_task_notNull_Assert_task_added)
{
	ToDoList list("");
	std::shared_ptr<Task> task(new Task(""));
	list.AddTask(task);

	EXPECT_FALSE(list.GetAllTasks().empty());
}

TEST(ToDoList, RemoveTask_task_null_Assert_no_listChanges)
{
	ToDoList list("");
	std::shared_ptr<Task> task(new Task(""));
	list.AddTask(task);
	list.RemoveTask(NULL);

	EXPECT_FALSE(list.GetAllTasks().empty());
}

TEST(ToDoList, RemoveTask_task_notNull_Assert_task_isRemoved)
{
	ToDoList list("");
	std::shared_ptr<Task> task(new Task(""));
	list.AddTask(task);
	list.RemoveTask(task);

	EXPECT_TRUE(list.GetAllTasks().empty());
}

TEST(ToDoList, GetUncompletedTaskCount_empty_list_Assert_0) 
{
	ToDoList list("");

	int count = list.GetUncompletedTaskCount();

	EXPECT_EQ(0, count);
}

TEST(ToDoList, GetUncompletedTaskCount_2_uncompleted_1_completed_Assert_2) 
{
	ToDoList list("");
	std::shared_ptr<Task> tasku1(new Task(""));
	tasku1->isCompleted = false;
	list.AddTask(tasku1);
	std::shared_ptr<Task> tasku2(new Task(""));
	tasku2->isCompleted = false;
	list.AddTask(tasku2);
	std::shared_ptr<Task> taskc1(new Task(""));
	taskc1->isCompleted = true;
	list.AddTask(taskc1);

	int count = list.GetUncompletedTaskCount();
	
	EXPECT_EQ(2, count);
}

TEST(ToDoList, GetCompletedTaskCount_empty_list_Assert_0)
{
	ToDoList list("");
	int count = list.GetCompletedTaskCount();
	EXPECT_EQ(0, count);
}

TEST(ToDoList, GetCompletedTaskCount_2_uncompleted_1_completed_Assert_1)
{
	ToDoList list("");
	std::shared_ptr<Task> tasku1(new Task(""));
	tasku1->isCompleted = false;
	list.AddTask(tasku1);
	std::shared_ptr<Task> tasku2(new Task(""));
	tasku2->isCompleted = false;
	list.AddTask(tasku2);
	std::shared_ptr<Task> taskc1(new Task(""));
	taskc1->isCompleted = true;
	list.AddTask(taskc1);

	int count = list.GetCompletedTaskCount();

	EXPECT_EQ(1, count);
}


TEST(ToDoList, GetUncompletedTask_index_any_uncompletedTaskSize_0_Assert_null)
{
	ToDoList list("");
	
	auto task = list.GetUncompletedTask(6);

	EXPECT_TRUE(NULL == task);
}

TEST(ToDoList, GetUncompletedTask_index_0_uncompletedTaskSize_moreThan0_Assert_taskIsReturned)
{
	ToDoList list("");
	std::shared_ptr<Task> tasku1(new Task(""));
	tasku1->isCompleted = false;
	list.AddTask(tasku1);
	std::shared_ptr<Task> tasku2(new Task(""));
	tasku2->isCompleted = false;
	list.AddTask(tasku2);

	auto task = list.GetUncompletedTask(0);

	EXPECT_EQ(tasku1, task);
}

TEST(ToDoList, GetUncompletedTask_index_lessThan0_uncompletedTaskSize_moreThan0_Assert_null)
{
	ToDoList list("");
	std::shared_ptr<Task> tasku1(new Task(""));
	tasku1->isCompleted = false;
	list.AddTask(tasku1);
	std::shared_ptr<Task> tasku2(new Task(""));
	tasku2->isCompleted = false;
	list.AddTask(tasku2);

	auto task = list.GetUncompletedTask(-3);

	EXPECT_TRUE(NULL == task);
}

TEST(ToDoList, GetCompletedTask_index_any_completedTaskSize_0_Assert_null)
{
	ToDoList list("");

	auto task = list.GetCompletedTask(6);

	EXPECT_TRUE(NULL == task);
}

TEST(ToDoList, GetCompletedTask_index_0_completedTaskSize_moreThan0_Assert_taskIsReturned)
{
	ToDoList list("");
	std::shared_ptr<Task> taskc1(new Task(""));
	taskc1->isCompleted = true;
	list.AddTask(taskc1);
	std::shared_ptr<Task> taskc2(new Task(""));
	taskc2->isCompleted = true;
	list.AddTask(taskc2);

	auto task = list.GetCompletedTask(0);

	EXPECT_EQ(taskc1, task);
}

TEST(ToDoList, GetCompletedTask_index_lessThan0_completedTaskSize_moreThan0_Assert_null)
{
	ToDoList list("");
	std::shared_ptr<Task> taskc1(new Task(""));
	taskc1->isCompleted = true;
	list.AddTask(taskc1);
	std::shared_ptr<Task> taskc2(new Task(""));
	taskc2->isCompleted = true;
	list.AddTask(taskc2);

	auto task = list.GetCompletedTask(-5);

	EXPECT_TRUE(NULL == task);
}


TEST(ToDoList, GetUncompletedTasks_2_uncompleted_1_completed_Assert_2)
{
	ToDoList list("");
	std::shared_ptr<Task> tasku1(new Task(""));
	tasku1->isCompleted = false;
	list.AddTask(tasku1);
	std::shared_ptr<Task> tasku2(new Task(""));
	tasku2->isCompleted = false;
	list.AddTask(tasku2);
	std::shared_ptr<Task> taskc1(new Task(""));
	taskc1->isCompleted = true;
	list.AddTask(taskc1);

	auto taskList = list.GetUncompletedTasks();

	EXPECT_EQ(2, taskList.size());
}

TEST(ToDoList, GetCompletedTasks_2_uncompleted_1_completed_Assert_1)
{
	ToDoList list("");
	std::shared_ptr<Task> tasku1(new Task(""));
	tasku1->isCompleted = false;
	list.AddTask(tasku1);
	std::shared_ptr<Task> tasku2(new Task(""));
	tasku2->isCompleted = false;
	list.AddTask(tasku2);
	std::shared_ptr<Task> taskc1(new Task(""));
	taskc1->isCompleted = true;
	list.AddTask(taskc1);

	auto taskList = list.GetCompletedTasks();

	EXPECT_EQ(1, taskList.size());
}

TEST(ToDoList, GetAllTasks_taskListSize_equal0_Assert_empty_taskList)
{
	ToDoList tdList("list");

	EXPECT_TRUE(tdList.GetAllTasks().empty());
}

TEST(ToDoList, GetAllTasks_taskListCount_moreThan0_Assert_notEmpty_taskList)
{
	ToDoList tdList("list");
	std::shared_ptr<Task> sharedTask(new Task("testTask"));

	tdList.AddTask(sharedTask);

	EXPECT_FALSE(tdList.GetAllTasks().empty());
}

TEST(ToDoList, Constructor_title_list_Assert_title_equal_list)
{
	ToDoList list("list");

	EXPECT_EQ("list", list.listName);
}