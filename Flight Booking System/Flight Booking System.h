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
using std::cout;
using std::cin;
using std::endl;
using std::string;

int MainMenu();
void MergeSort(Flight[], int, int);
//int SequentialSearch(string, string, int, Flight[], Flight*[]);
int findUser(Passenger[], string, string, string, int);
void PriceHighestToLowest(Flight*[], int);
//void PriceLowestToHighest(Flight*[], int);
void DurationLongestToShortest(Flight*[], int);
void DurationShortestToLongest(Flight*[], int);
void LoadData(FlightList&);
// TODO: Reference additional headers your program requires here.

#endif
