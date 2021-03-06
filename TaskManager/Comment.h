#pragma once
#include <string>
#include "DateTime.h"
class Comment
{
public:
	DateTime GetCreationDate();
	std::string GetOwner();
	std::string GetText();
	Comment(std::string owner, std::string text, DateTime creationDate);

private:
	std::string owner;
	std::string text;
	DateTime creationDate;
};

