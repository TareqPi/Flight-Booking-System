// Specification file for the Node class
#ifndef FLIGHTNODE_H
#define FLIGHTNODE_H
#include "Flight.h"

class FlightNode {
	public:
		Flight FlightData;
		FlightNode* Next;
};

#endif 
