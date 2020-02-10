#include "stdafx.h"
#include "SubTask.h"

void SubTask::SetText(std::string text)
{
	this->text = text;
}

void SubTask::SetIsCompleted(bool isCompleted)
{
	this->isCompleted = isCompleted;
}

std::string SubTask::GetText()
{
	return text;
}

bool SubTask::GetIsCompleted()
{
	return isCompleted;
}

SubTask::SubTask(std::string text)
{
	this->text = text;
	this->isCompleted = false;
}

SubTask::~SubTask()
{
}
