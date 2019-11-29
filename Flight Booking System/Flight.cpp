// Implementation file for the Flight class
#include <iostream>
#include <iomanip>
#include "Flight.h"
using std::cout;
using std::endl;
using std::string;

Flight::Flight(string Airline, string FlightType, string Source, string Destination, string FlightID,
	 float Price, float Duration, string FlightPlane) {
	_Airline = Airline;
	_FlightID = FlightID;
	_FlightType = FlightType;
	_Source = Source;
	_Destination = Destination;
	_Price = Price;
	_Duration = Duration;
	_FlightPlane.SetPlaneName(FlightPlane);
}

Flight::Flight() {
	_Airline = _FlightType = _Source = _FlightID = _Destination;
	_Duration = _Price = 0.0;
}

void Flight::SetDate(string Day, string Month, string Year) {
	_DepartureDate.SetDay(Day);
	_DepartureDate.SetMonth(Month);
	_DepartureDate.SetYear(Year);
}

Date Flight::GetDate() const {
	return _DepartureDate;
}

void Flight::SetAirline(string Airline) {
	_Airline = Airline;
}

string Flight::GetAirline() const {
	return _Airline;
}

void Flight::SetFlightID(string FlightID) {
	_FlightID = FlightID;
}

string Flight::GetFlightID() const {
	return _FlightID;
}

void Flight::SetFlightType(string FlightType) {
	_FlightType = FlightType;
}

string Flight::GetFlightType() const {
	return _FlightType;
}

void Flight::SetSource(string Source) {
	_Source = Source;
}

string Flight::GetSource() const {
	return _Source;
}

void Flight::SetDestination(string Destination) {
	_Destination = Destination;
}

string Flight::GetDestination() const {
	return _Destination;
}

void Flight::SetPrice(float amount) {
	_Price = amount;
}

float Flight::GetPrice() const {
	return _Price;
}

void Flight::SetPlane(string plane) {
	_FlightPlane.SetPlaneName(plane);
}

Plane Flight::GetPlane() {
	return _FlightPlane;
}

void Flight::SetDuration(float hours) {
	_Duration = hours;
}

float Flight::GetDuration() const {
	return _Duration;
}

void Flight::PrintDetails() {
	cout << "\tAirline: " << GetAirline() << endl;
	cout << "\tFlight ID: " << GetFlightID() << endl;
	cout << "\tFlight Model: " << _FlightPlane.GetPlaneName() << endl;
	cout << "\tFlight Capacity: " << _FlightPlane.GetPassengerCapacity() << endl;
	cout << "\tFlight Type: " << GetFlightType() << endl;
	cout << "\tSource: " << GetSource() << endl;
	cout << "\tDestination: " << GetDestination() << endl;
	cout << "\tPrice: " << GetPrice() << endl;
	cout << "\tDuration: " << GetDuration() << " hrs" << endl;
	cout << "\tDeparture Date: ";
	_DepartureDate.PrintDate();
}

Flight::~Flight() {}
