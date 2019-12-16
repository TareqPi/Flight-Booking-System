// Implementation file for the Passenger class
#include "Passenger.h"
#include <iostream>
#include <string>
using std::cout;
using std::string;
using std::endl;

Passenger::Passenger() {
	NumOfFlights = 0;
	_FirstName = "";
	_LastName = "";
	_PassportNumber = "";
}

Passenger::Passenger(string FirstName, string LastName, string PassportNumber, string Password) {
	NumOfFlights = 0;
	_FirstName = FirstName;
	_LastName = LastName;
	_PassportNumber = PassportNumber;
	_Password = Password;
}

void Passenger::SetFirstName(string FirstName) {
	_FirstName = FirstName;
}
void Passenger::SetLastName(string LastName) {
	_LastName = LastName;
}

void Passenger::SetPassPortNumber(string PassNum) {
	_PassportNumber = PassNum;
}

void Passenger::SetPassword(string Password) {
	_Password = Password;
}

string Passenger::GetPassword() const {
	return _Password;
}

string Passenger::GetFirstName() const {
	return _FirstName;
}

string Passenger::GetLastName() const {
	return _LastName;
}

string Passenger::GetPassportNumber() const {
	return _PassportNumber;
}

bool Passenger::ViewBookedFlights() {
	if (NumOfFlights == 0) {
		return false;
	}
	BookedFlights.DisplayList();
	return true;
}

void Passenger::BookFlight(Flight MyFlight) {
	BookedFlights.InsertNode(MyFlight);
	NumOfFlights++;
	cout << GetFirstName() << " " << GetLastName() << " have successfully booked flight " << MyFlight.GetFlightID()
		 << " from " << MyFlight.GetSource() << " to " << MyFlight.GetDestination() << endl << endl;
}

void Passenger::CancelFlight(string FlightNumber) {
	if (BookedFlights.DeleteNode(FlightNumber)) {
		cout << "Flight " << FlightNumber << " is cancelled" << endl << endl;
		NumOfFlights--;
		return;
	}
	else
		cout << "Not Found" << endl;
}

Passenger::~Passenger() {
	cout << _FirstName << " " << _LastName << " has been deleted" << endl;
}