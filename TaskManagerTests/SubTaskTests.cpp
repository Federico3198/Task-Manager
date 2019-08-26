#include "pch.h"
#include "../TaskManager/SubTask.h"
#include "../TaskManager/SubTask.cpp"

TEST(SubTask, Constructor_text_Assert_equal_text_isCompleted_false)
{
	std::string expectedText = "questaeunasubtask";

	SubTask subTask(expectedText);

	EXPECT_EQ(expectedText, subTask.GetText());
	EXPECT_FALSE(subTask.GetIsCompleted());
}

TEST(SubTask, SetText_questaeunasubtask_Assert_text_questaeunasubtask)
{
	std::string expectedText = "questaeunasubtask";
	SubTask subTask("");

	subTask.SetText(expectedText);

	EXPECT_EQ(expectedText, subTask.GetText());
}