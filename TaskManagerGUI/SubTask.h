#pragma once
#include <string>
class SubTask
{
public:
	void SetText(std::string text);
	void SetIsCompleted(bool isCompleted);
	std::string GetText();
	bool GetIsCompleted();
	SubTask(std::string text);
	~SubTask();

private:
	std::string text;
	bool isCompleted;
};

