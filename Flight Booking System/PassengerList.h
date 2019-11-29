#ifndef PASSENGERLIST_H
#define PASSENGERLIST_H
#include <string>
#include "Passenger.h"
using std::string;



class PassengerNode {
public:
	PassengerNode(Passenger PassengerToAdd) {
		user = PassengerToAdd;
	}
	Passenger user; // data of the node, a passenger object
	PassengerNode* next; // pointer to next node
};

class PassengerList {
public:
	PassengerList(void) { head = NULL; } // constructor
	~PassengerList(void); // destructor
	bool IsEmpty() { return head == NULL; }
	void InsertNode(Passenger PassengerToAdd);
	int FindNode(Passenger PassengerToFind);
	bool DeleteNode(Passenger PassengerToDelete);
private:
	PassengerNode* head;
};

#endif