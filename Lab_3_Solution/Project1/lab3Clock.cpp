/*
* File Name: lab3Clock.cpp
* Lab #3
* Completed by: Ziad Chemali
* Submission Date: October 9,2020

*/

#include<iostream>
#include <iomanip>
# include "lab3Clock.h"

Clock::Clock() : hour(0), minute(0), second(0) {}

Clock::Clock(int s) {
	if (s < 0) {
		hour = 0;
		minute = 0;
		second = 0;
	}
	else {
		sec_to_hms(s);
	}
}

Clock::Clock(int h, int m, int s) {
	if ((h >= 0 && h <= 23) && (m >= 0 && m <= 60) && (s >= 0 && s <= 60)) {
		this->hour = h;
		this->minute = m;
		this->second = s;

	}
	else
	{
		hour = 0;
		minute = 0;
		second = 0;
	}


}
int Clock::get_hour() const {
	return this->hour;
}

int Clock::get_minute() const {
	return this->minute;
}

int Clock::get_second() const {
	return this->second;
}

void Clock::set_hour(int h) {
	if (h >= 0 && h <= 23)
		this->hour = h;

}

void Clock::set_minute(int m) {
	if (m >= 0 && m <= 60)
		this->minute = m;
}

void Clock::set_second(int s) {
	if (s >= 0 && s <= 60)
		this->second = s;
}

void Clock::increment() {
	if (this->second < 59)
		this->second++;
	else if (this->second == 59)
	{
		this->second = 0;
		if (this->minute < 59)
		
			this->minute++;
		else if (this->minute == 59)
		{
			this-> minute = 0;
			if (this->hour < 23)
				this->hour++;
			else if (hour == 23)
			{
				hour = 0;
			

			}
		}

	}
}
void Clock::decrement() {
	if (this->second >0)
		this->second--;
	else if (this->second == 0)
	{
		this->second = 59;
		if (this->minute >0)

			this->minute--;
		else if (this->minute == 0)
		{
			this->minute = 59;
			if (this->hour >0)
				this->hour--;
			else if (hour == 0)
			{
				hour = 23;


			}
		}

	}


}
void Clock::add_seconds(int s) {
	if (s >= 0)
	{
		int local = hms_to_sec();
		local += s;

		sec_to_hms(local);
	}

}
void Clock::sec_to_hms(int s) {
	
	

		double local = double(s) / (24.0 * 60 * 60);
		int day = local;
		
		double h = local - day;
		
		h *= 24;

		this->hour = h;
		double min = h - int(h);
		


		min *= 60;
		
		this->minute = min;
		long double sec = min - int(min);
		
		
		
		second = sec*60;
		
		

	
	
}
int Clock::hms_to_sec() {
	std::cout << "hms to sec  " <<  (this->second) << " \n";
	
	return (second+60*minute+hour*3600);
}