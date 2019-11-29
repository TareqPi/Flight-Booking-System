// Implementation file for the PasengerList class
#include "PassengerList.h"
#include "Passenger.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;



void PassengerList::InsertNode(Passenger PassengerToAdd) {

	PassengerNode* CurrentNode = head; // simply to keep track.
	// if our list is empty, make the new element the head; 
	if (IsEmpty()) {
		head = new PassengerNode(PassengerToAdd);
	}
	/*Keep Looping through the list until you arrive to the latest element, break afterthat.*/
	while (CurrentNode->next != NULL) {
		CurrentNode = CurrentNode->next;       //  update the current node                         
	}
	// now that we are the last element, append our ->next to the new node with the new element.
	CurrentNode->next = new PassengerNode(PassengerToAdd);

	return;
}

int PassengerList::FindNode(Passenger PassengerToFind) {
	if (IsEmpty()) {
		cout << "List is Empty" << endl;
		return -1;  // -1 is the key that indicates the list is empty
	}
	int CurrentNodeIndex = 0;
	PassengerNode* CurrentNode = head;
	while ((CurrentNode->next != NULL)
		&& (CurrentNode->user.GetFirstName() != PassengerToFind.GetFirstName())
		&& (CurrentNode->user.GetLastName() != PassengerToFind.GetLastName())
		&& (CurrentNode->user.GetPassword() != PassengerToFind.GetPassword())) {

		CurrentNode = CurrentNode->next;
		++CurrentNodeIndex;
	}
	return CurrentNodeIndex;

}

bool PassengerList::DeleteNode(Passenger PassengerToDelete) {
	// 3 cases to consider
	// 1st case: no data at all in list
	if (IsEmpty()) {
		return false;
	}
	//2nd case: if the deleted one is actually the first element of the list;
	if ((head->user.GetFirstName() == PassengerToDelete.GetFirstName())
		&& (head->user.GetLastName() == PassengerToDelete.GetLastName())) {

		head = head->next;
		return true;
	}

	//3rd case: if the deleted is within the linked list.
	PassengerNode* CurrentNode = head;
	while (CurrentNode->next != NULL) {
		if ((CurrentNode->next->user.GetFirstName() == PassengerToDelete.GetFirstName())
			&& (CurrentNode->next->user.GetLastName() == PassengerToDelete.GetLastName())) {

			CurrentNode->next = CurrentNode->next->next;
			return true;
		}

		CurrentNode = CurrentNode->next;
	}
	// reaching here means it got through all the list and it doesn't exist;
	return false;
}