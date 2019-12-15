#include "stdafx.h"
#include "CommentWidgetItem.h"
#include <sstream>

CommentWidgetItem::CommentWidgetItem(std::shared_ptr<Comment> comment)
{
	this->comment = comment;
	std::stringstream stringStream;
	stringStream << comment->GetOwner() << " | ";
	DateTime creation = comment->GetCreationDate();
	stringStream << creation.GetDay() << "/"<< creation.GetMonth()<<"/"<<creation.GetYear()<< " - ";
	stringStream << creation.GetHours() << ":" << creation.GetMinutes() << std::endl;
	stringStream << comment->GetText();
	setText(stringStream.str().c_str());
}

CommentWidgetItem::~CommentWidgetItem()
{
}

std::shared_ptr<Comment> CommentWidgetItem::GetComment()
{
	return comment;
}
