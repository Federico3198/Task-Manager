#include "pch.h"
#include "../TaskManager/DateTime.h"
#include "../TaskManager/DateTime.cpp"

#pragma region  SetDay

TEST(DateTime,SetDay_day_5_Assert_day_5)
{
	int expectedDay = 5;
	DateTime *dt;
	dt = new DateTime();
	
	dt->SetDay(expectedDay);
	
	EXPECT_EQ(expectedDay, dt->GetDay());
}

TEST(DateTime, SetDay_day_negative1_Assert_day_1)
{
	int expectedDay = 1;
	DateTime *dt;
	dt = new DateTime();

	dt->SetDay(-1);

	EXPECT_EQ(expectedDay, dt->GetDay());
}

TEST(DateTime, SetDay_day_1000_Assert_day_31)
{
	int expectedDay = 31;
	DateTime *dt;
	dt = new DateTime();

	dt->SetDay(1000);

	EXPECT_EQ(expectedDay, dt->GetDay());
}

#pragma endregion

#pragma region SetMonth

TEST(DateTime, SetMonth_month_10_Assert_month_10)
{
	int expectedMonth = 10;
	DateTime *dt;
	dt = new DateTime();

	dt->SetMonth(expectedMonth);

	EXPECT_EQ(expectedMonth, dt->GetMonth());
}

TEST(DateTime, SetMonth_negativeMonth_Assert_month_1)
{
	int expectedMonth = 1;
	DateTime *dt;
	dt = new DateTime();

	dt->SetMonth(-3);

	EXPECT_EQ(expectedMonth, dt->GetMonth());
}

TEST(DateTime, SetMonth_month_14_Assert_month_12)
{
	int expectedMonth = 12;
	DateTime *dt;
	dt = new DateTime();

	dt->SetMonth(14);

	EXPECT_EQ(expectedMonth, dt->GetMonth());
}

#pragma endregion

#pragma region SetYear

TEST(DateTime, SetYear_year_2020_Assert_year_2020)
{
	int expectedYear = 2020;
	DateTime *dt;
	dt = new DateTime();

	dt->SetYear(expectedYear);

	EXPECT_EQ(expectedYear, dt->GetYear());
}

TEST(DateTime, SetYear_year_negative10_Assert_year_negative10)
{
	int expectedYear = -10;
	DateTime *dt;
	dt = new DateTime();

	dt->SetYear(expectedYear);

	EXPECT_EQ(expectedYear, dt->GetYear());
}

TEST(DateTime, SetYear_year_12020_Assert_year_12020)
{
	int expectedYear = 12020;
	DateTime *dt;
	dt = new DateTime();

	dt->SetYear(expectedYear);

	EXPECT_EQ(expectedYear, dt->GetYear());
}

#pragma endregion

#pragma region SetHours

TEST(DateTime, SetHours_hour_16_Assert_hour_16)
{
	int expectedHour = 16;
	DateTime *dt;
	dt = new DateTime();

	dt->SetHours(expectedHour);

	EXPECT_EQ(expectedHour, dt->GetHours());
}

TEST(DateTime, SetHours_hour_negative12_Assert_hour_12)
{
	int expectedHour = 12;
	DateTime *dt;
	dt = new DateTime();

	dt->SetHours(-12);

	EXPECT_EQ(expectedHour, dt->GetHours());
}

TEST(DateTime, SetHours_hour_27_Assert_hour_23)
{
	int expectedHour = 23;
	DateTime *dt;
	dt = new DateTime();

	dt->SetHours(27);

	EXPECT_EQ(expectedHour, dt->GetHours());
}

TEST(DateTime, SetHours_hour_negative27_Assert_hour_23)
{
	int expectedHour = 23;
	DateTime *dt;
	dt = new DateTime();

	dt->SetHours(-27);

	EXPECT_EQ(expectedHour, dt->GetHours());
}

#pragma endregion

#pragma region SetMinutes

TEST(DateTime, SetMinutes_minutes_43_Assert_minutes_43)
{
	int expectedMinutes = 43;
	DateTime *dt;
	dt = new DateTime();

	dt->SetMinutes(expectedMinutes);

	EXPECT_EQ(expectedMinutes, dt->GetMinutes());
}

TEST(DateTime, SetMinutes_minutes_negative10_Assert_minutes_negative10)
{
	int expectedMinutes = 10;
	DateTime *dt;
	dt = new DateTime();

	dt->SetMinutes(-10);

	EXPECT_EQ(expectedMinutes, dt->GetMinutes());
}

TEST(DateTime, SetMinutes_minutes_61_Assert_minutes_59)
{
	int expectedMinutes = 59;
	DateTime *dt;
	dt = new DateTime();

	dt->SetMinutes(61);

	EXPECT_EQ(expectedMinutes, dt->GetMinutes());
}

TEST(DateTime, SetMinutes_minutes_negative70_Assert_minutes_59)
{
	int expectedMinutes = 59;
	DateTime *dt;
	dt = new DateTime();

	dt->SetMinutes(-70);

	EXPECT_EQ(expectedMinutes, dt->GetMinutes());
}

#pragma endregionnbhbn 