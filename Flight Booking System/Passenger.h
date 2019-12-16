// Specification file for the Passenger class
#ifndef PASSENGER_H
#define PASSENGER_H
#include "Date.h"
#include "FlightList.h"
#include <string>
using std::string;

class Passenger {
	private:
		string _FirstName;
		string _LastName;
		Date _DateOfBirth;     // object that has int day, int month, int year
		string _PassportNumber;
		string _Password;
		FlightList BookedFlights;
		int NumOfFlights;
	public:
		Passenger();
		Passenger(string, string, string, string);
		void SetFirstName(string);
		void SetLastName(string);
		void SetPassPortNumber(string);
		void SetPassword(string);

		string GetPassword() const;
		string GetFirstName() const;
		string GetLastName() const;
		string GetPassportNumber() const;

		bool ViewBookedFlights();
		void BookFlight(Flight);
		void CancelFlight(string);
		~Passenger();
};
#endif
