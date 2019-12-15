#pragma once
#include <qlistwidget.h>
#include "Comment.h"

class CommentWidgetItem :
	public QListWidgetItem
{
public:
	CommentWidgetItem(std::shared_ptr<Comment> comment);
	~CommentWidgetItem();
	std::shared_ptr<Comment> GetComment();

private:
	std::shared_ptr<Comment> comment;
};

