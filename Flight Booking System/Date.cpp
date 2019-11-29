// Implementation file for the Date class
#include <iostream>
#include <string>
#include "Date.h"
using std::string;
using std::cout;
using std::endl;

Date::Date(string Day, string Month, string Year) {
	_Day = Day;
	_Month = Month;
	_Year = Year;
}
Date::Date() {
	_Day = "1";
	_Month = "1";
	_Year = "2000";
}
void Date::SetDay(string Day) {
	_Day = Day;
}
void Date::SetMonth(string Month) {
	_Month = Month;
}
void Date::SetYear(string Year) {
	_Year = Year;
}
string Date::GetYear() const {
	return _Year;
}
string Date::GetDay() const {
	return _Day; 
}
string Date::GetMonth() const { 
	return _Month;
}
void Date::PrintDate() const {
	cout << GetDay() << "/" << GetMonth() << "/" << GetYear() << endl;
}