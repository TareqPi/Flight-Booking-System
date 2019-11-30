// Implementation file for the PasengerList class
#include "PassengerList.h"
#include "Passenger.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

PassengerList::PassengerList() {
	Head = NULL;
	ListSize = 0;
}

void PassengerList::InsertNode(Passenger NewPassenger) {
	PassengerNode* NewNode = new PassengerNode;
	NewNode->PassengerData = NewPassenger;

	if (IsEmpty()) {
		NewNode->Next = NULL;
	}
	else {
		NewNode->Next = Head;
	}
	Head = NewNode;
	ListSize++;
}

bool PassengerList::IsEmpty() { 
	return Head == NULL; 
}

PassengerNode* PassengerList::FindNode(Passenger PassengerToFind) {
	if (IsEmpty()) {
		cout << "List is Empty" << endl;
		return NULL;  // key that indicates the list is empty
	}
	int CurrentNodeIndex = 0;
	PassengerNode* CurrentNode = Head;
	cout << Head->PassengerData.GetFirstName() << endl;
	while (CurrentNode) {
		if (CurrentNode->PassengerData.GetFirstName() == PassengerToFind.GetFirstName() &&
			CurrentNode->PassengerData.GetLastName() == PassengerToFind.GetLastName() &&
			CurrentNode->PassengerData.GetPassword() == PassengerToFind.GetPassword())
			return CurrentNode;
		CurrentNode = CurrentNode->Next;
		++CurrentNodeIndex;
	}
	return NULL; // if not found
}

int PassengerList::GetSize() const {
	return ListSize;
}
bool PassengerList::DeleteNode(Passenger PassengerToDelete) {
	// 3 cases to consider
	// 1st case: no data at all in list
	if (IsEmpty()) {
		return false;
	}
	//2nd case: if the deleted one is actually the first element of the list;
	if ((Head->PassengerData.GetFirstName() == PassengerToDelete.GetFirstName())
		&& (Head->PassengerData.GetLastName() == PassengerToDelete.GetLastName())) {

		Head = Head->Next;
		return true;
	}

	//3rd case: if the deleted is within the linked list.
	PassengerNode* CurrentNode = Head;
	while (CurrentNode->Next != NULL) {
		if ((CurrentNode->Next->PassengerData.GetFirstName() == PassengerToDelete.GetFirstName())
			&& (CurrentNode->Next->PassengerData.GetLastName() == PassengerToDelete.GetLastName())) {

			CurrentNode->Next = CurrentNode->Next->Next;
			return true;
		}
		CurrentNode = CurrentNode->Next;
	}
	// reaching here means it got through all the list and it doesn't exist;
	return false;
}
