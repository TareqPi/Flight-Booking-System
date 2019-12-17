#include <fstream>
#include <string>
#include <iostream>
#include "Flight.h"
#include "FlightList.h"
using std::endl;

void LoadData(FlightList& Flights) {
	std::fstream Read("C:\\Users\\Psychoapth\\Source\\Repos\\Flight-Booking-System\\Flight Booking System\\4NovSnapshot.csv", std::ios::in);
	if (Read.fail()) {
		std::cout << "Error loading data" << std::endl;
		exit(-1);
	}
	int Num = 0;
	string Day, Month, Year, Airline, FlightID, FlightType, Source, Destination, PlaneName, Price, Duration;
	Flight TempObj;
	while (getline(Read, Day, '/') && getline(Read, Month, '/') && getline(Read, Year, ',') && getline(Read, Airline, ',') && 
		getline(Read, FlightID, ',') && getline(Read, FlightType, ',') && getline(Read, Source, ',') && getline(Read, Destination, ',')
		&& getline(Read, PlaneName, ',') && getline(Read, Price, ',') && getline(Read, Duration)) {
		TempObj.SetAirline(Airline);
		TempObj.SetFlightID(FlightID);
		TempObj.SetFlightType(FlightType);
		TempObj.SetSource(Source);
		TempObj.SetDestination(Destination);
		TempObj.SetPrice(std::stof(Price));
		TempObj.SetDuration(std::stof(Duration));
		TempObj.SetPlane(PlaneName);
		TempObj.SetDate(Day, Month, Year);
		Flights.InsertNode(TempObj);
	}
	Read.close();
}
