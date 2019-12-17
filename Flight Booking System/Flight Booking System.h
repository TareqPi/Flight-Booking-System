// Flight Booking System.h : Include file for standard system include files,
// or project specific include files.
#ifndef FLIGHT_BOOKING_SYSTEM_H
#define FLIGHT_BOOKING_SYSTEM_H

#include <iostream>
#include <string>
#include "Passenger.h"
#include "Flight.h"
#include "Date.h"
#include "FlightList.h"
#include "PassengerList.h"
#include "ActivityStack.h"
#include "Art.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;

int MainMenu();
void LoadData(FlightList&);
// TODO: Reference additional headers your program requires here.

#endif
