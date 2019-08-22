#pragma once
#include <ctime>
class DateTime
{

private:
	int day, month, year;
	int hours, minutes;
	time_t secondsSince1970;

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
	
	bool operator >(const DateTime &other);
	bool operator <(const DateTime &other);
	bool operator <=(const DateTime &other);
	
	DateTime(time_t timeInSeconds);
	DateTime();
};

