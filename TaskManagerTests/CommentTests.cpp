#include "pch.h"
#include "../TaskManager/Comment.h"
#include "../TaskManager/Comment.cpp"
#include <string>

TEST(Comment, Constructor_owner_text_creationDate_Assert_equal_constructor_parameters)
{
	std::string expectedOwner="Mario";
	std::string expectedText = "farelaspesa";
	DateTime expectedCreationDate(100);
	
	Comment comment(expectedOwner,expectedText,expectedCreationDate);
	
	EXPECT_EQ(expectedOwner, comment.GetOwner());
	EXPECT_EQ(expectedText, comment.GetText());
	EXPECT_EQ(expectedCreationDate, comment.GetCreationDate());
}

bool operator==(const DateTime& left, const DateTime& right)
{
	DateTime dt1 = left;
	DateTime dt2 = right;
	return dt1.GetSecondsSince1970() == dt2.GetSecondsSince1970();
}