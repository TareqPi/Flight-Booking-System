#ifndef PASSENGERLIST_H
#define PASSENGERLIST_H
#include <string>
#include "Passenger.h"
using std::string;

class PassengerNode {
public:
	Passenger PassengerData; // data of the node, a passenger object
	PassengerNode* Next; // pointer to next node
};

class PassengerList {
private:
	PassengerNode* Head;
	int ListSize;
public:
	PassengerList();
	~PassengerList(); 
	bool IsEmpty();
	void InsertNode(Passenger);
	int GetSize() const;
	PassengerNode* FindNode(Passenger);
	bool DeleteNode(Passenger);
};

#endif
