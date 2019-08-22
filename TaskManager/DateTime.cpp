#include "pch.h"
#include "DateTime.h"


void DateTime::SetDay(int day)
{
	if (day <= 0)
	{
		day = 1;
	}
	else if (day > 31)
	{
		day = 31;
	}

	this->day = day;
}

void DateTime::SetMonth(int month)
{
	if (month <= 0)
	{
		month = 1;
	}
	else if (month > 12)
	{
		month = 12;
	}
	this->month = month;
}

void DateTime::SetYear(int year)
{
	this->year = year;
}

void DateTime::SetHours(int hours)
{
	if (hours < 0)
	{
		hours *= -1;
	}

	if (hours > 23)
	{
		hours = 23;
	}

	this->hours = hours;
}

void DateTime::SetMinutes(int minutes)
{
	if (minutes < 0)
	{
		minutes *= -1;
	}

	if (minutes > 59)
	{
		minutes = 59;
	}
	this->minutes = minutes;
}

int DateTime::GetDay()
{
	return day;
}

int DateTime::GetMonth()
{
	return month;
}

int DateTime::GetYear()
{
	return year;
}

int DateTime::GetHours()
{
	return hours;
}

int DateTime::GetMinutes()
{
	return minutes;
}

bool DateTime::operator>(const DateTime & other)
{
	return secondsSince1970 > other.secondsSince1970;
}

bool DateTime::operator<(const DateTime & other)
{
	return secondsSince1970 < other.secondsSince1970;
}

bool DateTime::operator<=(const DateTime & other)
{
	return secondsSince1970 <= other.secondsSince1970;
}

DateTime::DateTime(time_t timeInSeconds)
{
	struct tm timeData;
	timeData = *localtime(&timeInSeconds);

	secondsSince1970 = timeInSeconds;

	SetYear(timeData.tm_year + 1900);
	SetMonth(timeData.tm_mon + 1);
	SetDay(timeData.tm_mday);

	SetHours(timeData.tm_hour);
	SetMinutes(timeData.tm_min);
}

DateTime::DateTime()
{
	secondsSince1970 = 0;
	day = 1;
	month = 1;
	year = 1970;
	hours = 0;
	minutes = 0;
}
