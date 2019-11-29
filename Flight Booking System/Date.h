// Specification file for the Date class
#ifndef DATE_H
#define DATE_H
#include <string>
using std::string;

class Date {
	private:
		string _Month, _Day, _Year;
	public:
		Date(string, string, string);
		Date();
		void SetDay(string);
		string GetDay() const;
		void SetMonth(string);
		string GetMonth() const;
		void SetYear(string);
		string GetYear() const;
		void PrintDate() const;
};

#endif
