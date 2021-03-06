#include "pch.h"
#include "../TaskManager/Task.h"
#include "../TaskManager/Task.cpp"


TEST(Task, AddSubTask_subTask_null_Assert_subTask_not_added)
{
	Task taskTest("task");

	taskTest.AddSubTask(NULL);

	EXPECT_EQ(0, taskTest.GetSubTasks().size());
}

TEST(Task, AddSubTask_subTask_notNull_Assert_subTask_added)
{
	Task taskTest("task");
	std::shared_ptr<SubTask> sharedSubTask(new SubTask("testsubtask"));

	taskTest.AddSubTask(sharedSubTask);

	EXPECT_FALSE(taskTest.GetSubTasks().empty());
}

TEST(Task, RemoveSubTask_subTask_null_Assert_no_listChanges)
{
	Task taskTest("task");
	std::shared_ptr<SubTask> sharedSubTask(new SubTask("testsubtask"));

	taskTest.AddSubTask(sharedSubTask);
	taskTest.RemoveSubTask(NULL);

	EXPECT_FALSE(taskTest.GetSubTasks().empty());
}

TEST(Task, RemoveSubTask_subTask_notNull_Assert_subTask_isRemoved)
{
	Task taskTest("task");
	std::shared_ptr<SubTask> sharedSubTask(new SubTask("testsubtask"));

	taskTest.AddSubTask(sharedSubTask);
	taskTest.RemoveSubTask(sharedSubTask);

	EXPECT_TRUE(taskTest.GetSubTasks().empty());
}

TEST(Task, GetSubTask_index_lessThan0_Assert_no_subTask_returned)
{
	Task taskTest("task");
	auto subTask = taskTest.GetSubTask(-6);

	EXPECT_TRUE(NULL == subTask);
}

TEST(Task, GetSubTask_index_0_subTaskListSize_moreThan0_Assert_subTask_isReturned)
{
	Task taskTest("task");
	std::shared_ptr<SubTask> sharedSubTask(new SubTask("testsubtask"));

	taskTest.AddSubTask(sharedSubTask);
	auto subTask = taskTest.GetSubTask(0);

	EXPECT_EQ(sharedSubTask, subTask);
}

TEST(Task, GetSubTask_index_0_subTaskListSize_equal0_Assert_subTask_not_returned)
{
	Task taskTest("task");
	auto subTask = taskTest.GetSubTask(0);

	EXPECT_TRUE(NULL == subTask);
}

TEST(Task, GetSubTasks_subTaskListSize_equal0_Assert_empty_subTaskList)
{
	Task taskTest("task");

	EXPECT_TRUE(taskTest.GetSubTasks().empty());
}

TEST(Task, GetSubTasks_subTaskListCount_moreThan0_Assert_notEmpty_subTaskList)
{
	Task taskTest("task");
	std::shared_ptr<SubTask> sharedSubTask(new SubTask("testsubtask"));

	taskTest.AddSubTask(sharedSubTask);
	
	EXPECT_FALSE(taskTest.GetSubTasks().empty());
}

TEST(Task, Constructor_title_task_Assert_title_equal_task)
{
	Task taskTest("task");

	EXPECT_EQ("task", taskTest.title);
}

//----------------

TEST(Task, AddComment_comment_null_Assert_comment_not_added)
{
	Task taskTest("task");

	taskTest.AddComment(NULL);

	EXPECT_EQ(0, taskTest.GetComments().size());
}

TEST(Task, AddComment_comment_notNull_Assert_comment_added)
{
	Task taskTest("task");
	std::shared_ptr<Comment> sharedComment(new Comment("owner","testComment",DateTime()));

	taskTest.AddComment(sharedComment);

	EXPECT_FALSE(taskTest.GetComments().empty());
}

TEST(Task, RemoveComment_comment_null_Assert_no_listChanges)
{
	Task taskTest("task");
	std::shared_ptr<Comment> sharedComment(new Comment("owner", "testComment", DateTime()));

	taskTest.AddComment(sharedComment);
	taskTest.RemoveComment(NULL);

	EXPECT_FALSE(taskTest.GetComments().empty());
}

TEST(Task, RemoveComment_comment_notNull_Assert_comment_isRemoved)
{
	Task taskTest("task");
	std::shared_ptr<Comment> sharedComment(new Comment("owner", "testComment", DateTime()));

	taskTest.AddComment(sharedComment);
	taskTest.RemoveComment(sharedComment);

	EXPECT_TRUE(taskTest.GetComments().empty());
}

TEST(Task, GetComments_commentListSize_equal0_Assert_empty_commentList)
{
	Task taskTest("task");

	EXPECT_TRUE(taskTest.GetComments().empty());
}

TEST(Task, GetSComments_commentListCount_moreThan0_Assert_notEmpty_commentList)
{
	Task taskTest("task");
	std::shared_ptr<Comment> sharedComment(new Comment("owner", "testComment", DateTime()));

	taskTest.AddComment(sharedComment);

	EXPECT_FALSE(taskTest.GetComments().empty());
}

