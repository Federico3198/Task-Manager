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

