#include "pch.h"
#include "../TaskManager/ToDoListManager.cpp"
#include "../TaskManager/ToDoListManager.h"
#include "../TaskManager/TimeUtils.h"
#include "../TaskManager/TimeUtils.cpp"


TEST(ToDoListManager, AddTask_task_notNull_id_0_noLists_Assert_false)
{

	FAIL();
}

TEST(ToDoListManager, AddTask_task_Null_id_0_noLists_Assert_false)
{
	FAIL();
}

TEST(ToDoListManager, AddTask_task_notNull_id_0_id0List_Assert_true)
{
	FAIL();
}

TEST(ToDoListManager, AddTask_task_Null_id_0_id0List_Assert_false)
{
	FAIL();
}



TEST(ToDoListManager, RemoveTask_task_notNull_id_0_noLists_Assert_false)
{
	FAIL();
}

TEST(ToDoListManager, RemoveTask_task_Null_id_0_noLists_Assert_false)
{
	FAIL();
}

TEST(ToDoListManager, RemoveTask_task_notNull_id_0_id0List_Assert_true)
{
	FAIL();
}

TEST(ToDoListManager, RemoveTask_task_Null_id_0_id0List_Assert_false)
{
	FAIL();
}


TEST(ToDoListManager, AddList_tdlist_Null_emptyList_Assert_listIsEmpty)
{
	FAIL();
}

TEST(ToDoListManager, AddList_tdlist_notNull_emptyList_Assert_listIsNotEmpty)
{
	FAIL();
}


TEST(ToDoListManager, RemoveList_tdlist_Null_notEmptyList_Assert_listUnchanged)
{
	FAIL();
}

TEST(ToDoListManager, RemoveList_tdlist_notNull_notEmptyList_Assert_tdListRemoved)
{
	FAIL();
}


TEST(ToDoListManager, GetListByID_id_notValid_notEmptyList_Assert_null)
{
	FAIL();
}

TEST(ToDoListManager, GetListByID_id_valid_notEmptyList_Assert_same_id_tdList)
{
	FAIL();
}

TEST(ToDoListManager, GetToDoLists_tdListsSize_equal0_Assert_empty_tdLists)
{
	FAIL();
}

TEST(ToDoListManager, GetToDoLists_tdListsCount_moreThan0_Assert_notEmpty_tdLists)
{
	FAIL();
}

TEST(ToDoListManager, ContructorEmpty_Assert_emptyList)
{
	FAIL();
}

TEST(ToDoListManager, ContructorToDoList_tdLists_null_Assert_emptyList)
{
	FAIL();
}

TEST(ToDoListManager, ContructorToDoList_tdLists_notNull_with_moreThan0_lists_Assert_notEmptyList)
{
	FAIL();
}