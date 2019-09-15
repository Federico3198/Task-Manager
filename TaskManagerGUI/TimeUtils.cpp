#include "stdafx.h"
#include "TimeUtils.h"

time_t TimeUtils::GetEndOfToday()
{
	time_t todayTime;
	time(&todayTime);

	struct tm timeData = struct  tm();
	localtime_s(&timeData, &todayTime);

	timeData.tm_sec = 59;
	timeData.tm_hour = 23;
	timeData.tm_min = 59;

	return mktime(&timeData);
}

time_t TimeUtils::GetEndOfWeek()
{
	time_t todayTime;
	time(&todayTime);

	//advances time by 6 days
	todayTime += 60 * 60 * 24 * 6;

	struct tm timeData = struct  tm();
	localtime_s(&timeData, &todayTime);

	timeData.tm_sec = 59;
	timeData.tm_hour = 23;
	timeData.tm_min = 59;

	return mktime(&timeData);
}
