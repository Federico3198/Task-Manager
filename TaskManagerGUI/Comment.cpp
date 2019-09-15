#include "stdafx.h"
#include "Comment.h"


DateTime Comment::GetCreationDate()
{
	return creationDate;
}

std::string Comment::GetOwner()
{
	return owner;
}

std::string Comment::GetText()
{
	return text;
}

Comment::Comment(std::string owner, std::string text, DateTime creationDate)
{
	this->owner = owner;
	this->text = text;
	this->creationDate = creationDate;
}
