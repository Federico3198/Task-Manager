#pragma once
#include <ctime>
class DateTime
{

private:
	int day, month, year;
	int hours, minutes;

public:
	void SetDay(int day);
	void SetMonth(int month);
	void SetYear(int year);
	void SetHours(int hours);
	void SetMinutes(int minutes);
	int GetDay();
	int GetMonth();
	int GetYear();
	int GetHours();
	int GetMinutes();
	
	DateTime(time_t time);
	DateTime();
};

