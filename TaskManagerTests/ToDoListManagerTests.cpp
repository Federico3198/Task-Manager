#include "pch.h"
#include "../TaskManager/ToDoListManager.cpp"
#include "../TaskManager/ToDoListManager.h"
#include "../TaskManager/TimeUtils.h"
#include "../TaskManager/TimeUtils.cpp"


TEST(ToDoListManager, AddTask_task_notNull_id_0_noLists_Assert_false)
{
	ToDoListManager tdManager;
	std::shared_ptr<Task> sharedTask(new Task(""));

	bool result = tdManager.AddTask(sharedTask, 0);

	EXPECT_FALSE(result);
}

TEST(ToDoListManager, AddTask_task_Null_id_0_noLists_Assert_false)
{
	ToDoListManager tdManager;

	bool result = tdManager.AddTask(NULL, 0);

	EXPECT_FALSE(result);
}

TEST(ToDoListManager, AddTask_task_notNull_id_valid_Assert_true)
{

	ToDoListManager tdManager;
	std::shared_ptr<ToDoList> sharedTdList(new ToDoList(""));
	tdManager.AddList(sharedTdList);
	std::shared_ptr<Task> sharedTask(new Task(""));
	int validID = sharedTdList->GetId();

	bool result = tdManager.AddTask(sharedTask, validID);

	EXPECT_TRUE(result);
}

TEST(ToDoListManager, AddTask_task_Null_id_valid_Assert_false)
{
	ToDoListManager tdManager;
	std::shared_ptr<ToDoList> sharedTdList(new ToDoList(""));
	tdManager.AddList(sharedTdList);
	int validID = sharedTdList->GetId();

	bool result = tdManager.AddTask(NULL, validID);

	EXPECT_FALSE(result);
}



TEST(ToDoListManager, RemoveTask_task_notNull_id_0_noLists_Assert_false)
{
	ToDoListManager tdManager;
	std::shared_ptr<Task> sharedTask(new Task(""));

	bool result = tdManager.RemoveTask(sharedTask, 0);

	EXPECT_FALSE(result);
}

TEST(ToDoListManager, RemoveTask_task_Null_id_0_noLists_Assert_false)
{
	ToDoListManager tdManager;

	bool result = tdManager.RemoveTask(NULL, 0);

	EXPECT_FALSE(result);
}

TEST(ToDoListManager, RemoveTask_task_notNull_id_valid_Assert_true)
{
	ToDoListManager tdManager;
	std::shared_ptr<ToDoList> sharedTdList(new ToDoList(""));
	tdManager.AddList(sharedTdList);
	std::shared_ptr<Task> sharedTask(new Task(""));
	int validID = sharedTdList->GetId();

	tdManager.AddTask(sharedTask, validID);
	bool result = tdManager.RemoveTask(sharedTask, validID);

	EXPECT_TRUE(result);
}

TEST(ToDoListManager, RemoveTask_task_Null_id_valid_Assert_false)
{
	ToDoListManager tdManager;
	std::shared_ptr<ToDoList> sharedTdList(new ToDoList(""));
	tdManager.AddList(sharedTdList);
	int validID = sharedTdList->GetId();

	bool result = tdManager.RemoveTask(NULL, validID);

	EXPECT_FALSE(result);
}


TEST(ToDoListManager, AddList_tdlist_Null_emptyList_Assert_listIsEmpty)
{

	ToDoListManager tdManager;

	tdManager.AddList(NULL);

	EXPECT_TRUE(tdManager.GetToDoLists().empty());
}

TEST(ToDoListManager, AddList_tdlist_notNull_emptyList_Assert_listIsNotEmpty)
{
	ToDoListManager tdManager;
	std::shared_ptr<ToDoList> sharedTdList(new ToDoList(""));

	tdManager.AddList(sharedTdList);

	EXPECT_FALSE(tdManager.GetToDoLists().empty());
}


TEST(ToDoListManager, RemoveList_tdlist_idInvalid_notEmptyList_Assert_listUnchanged)
{
	ToDoListManager tdManager;
	std::shared_ptr<ToDoList> sharedTdList(new ToDoList(""));
	tdManager.AddList(sharedTdList);
	int expectedSize = tdManager.GetToDoLists().size();

	tdManager.RemoveList(-1);

	EXPECT_EQ(expectedSize, tdManager.GetToDoLists().size());
}

TEST(ToDoListManager, RemoveList_tdlist_id_valid_notEmptyList_Assert_tdListRemoved)
{
	ToDoListManager tdManager;
	std::shared_ptr<ToDoList> sharedTdList1(new ToDoList(""));
	std::shared_ptr<ToDoList> sharedTdList2(new ToDoList(""));
	tdManager.AddList(sharedTdList1);
	tdManager.AddList(sharedTdList2);
	int validID = sharedTdList1->GetId();

	tdManager.RemoveList(validID);

	EXPECT_EQ(1, tdManager.GetToDoLists().size());
}


TEST(ToDoListManager, GetListByID_id_notValid_notEmptyList_Assert_null)
{
	ToDoListManager tdManager;
	std::shared_ptr<ToDoList> sharedTdList1(new ToDoList(""));
	std::shared_ptr<ToDoList> sharedTdList2(new ToDoList(""));
	tdManager.AddList(sharedTdList1);
	tdManager.AddList(sharedTdList2);

	auto result = tdManager.GetListByID(-1);

	EXPECT_TRUE(NULL ==  result);
}

TEST(ToDoListManager, GetListByID_id_valid_notEmptyList_Assert_same_id_tdList)
{
	ToDoListManager tdManager;
	std::shared_ptr<ToDoList> sharedTdList1(new ToDoList(""));
	std::shared_ptr<ToDoList> sharedTdList2(new ToDoList(""));
	tdManager.AddList(sharedTdList1);
	tdManager.AddList(sharedTdList2);
	int validID = sharedTdList1->GetId();

	auto result = tdManager.GetListByID(validID);

	EXPECT_EQ(sharedTdList1, result);
}

TEST(ToDoListManager, GetToDoLists_tdListsSize_equal0_Assert_empty_tdLists)
{
	ToDoListManager tdManager;

	EXPECT_TRUE(tdManager.GetToDoLists().empty());
}

TEST(ToDoListManager, GetToDoLists_tdListsCount_moreThan0_Assert_notEmpty_tdLists)
{
	ToDoListManager tdManager;
	std::shared_ptr<ToDoList> sharedTdList(new ToDoList(""));
	tdManager.AddList(sharedTdList);

	EXPECT_FALSE(tdManager.GetToDoLists().empty());
}

TEST(ToDoListManager, ContructorEmpty_Assert_emptyList)
{
	ToDoListManager tdManager;

	EXPECT_TRUE(tdManager.GetToDoLists().empty());
}

TEST(ToDoListManager, ContructorToDoList_tdLists_notNull_with_moreThan0_lists_Assert_notEmptyList)
{
	std::list<std::shared_ptr<ToDoList> > toDoLists;
	toDoLists.push_back(std::shared_ptr<ToDoList>(new ToDoList("")));
	ToDoListManager tdManager(toDoLists);

	EXPECT_FALSE(tdManager.GetToDoLists().empty());
}