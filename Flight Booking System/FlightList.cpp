#include "FLightList.h"
#include <iostream>

using std::cout;
using std::endl;

FlightList::FlightList() {
	Head = NULL;
	ListSize = 0;
}

void FlightList::InsertNode(Flight NewFlight) {
	FlightNode* NewNode = new FlightNode;
	NewNode->FlightData = NewFlight;
	if (IsEmpty()) {
		NewNode->Next = NULL;
	}
	else {
		NewNode->Next = Head;
	}
	Head = NewNode;
	ListSize++;
}

int FlightList::GetSize() const {
	return ListSize;
}

void FlightList::FindNode(string SearchKey1, string SearchKey2, FlightList& Result) {
	FlightNode* CurrNode = Head;
	while (CurrNode) {
		if (SearchKey1 == CurrNode->FlightData.GetSource()) {
			if (SearchKey2 == CurrNode->FlightData.GetDestination()) {
				Result.InsertNode(CurrNode->FlightData);
			}
		}
		CurrNode = CurrNode->Next;
	}
}

void FlightList::PriceLowestToHighest() {
	FlightNode* CurrNode = Head;
	FlightNode Temp;
	int swaps;
	//Ascending Order
	for (int Pass = 1; (Pass < ListSize); Pass++) {
		swaps = 0;
		CurrNode = Head;
		for (int x = 0; x < ListSize - Pass; x++) {
			if (CurrNode->FlightData.GetPrice() > CurrNode->Next->FlightData.GetPrice()) {
				Temp.FlightData = CurrNode->FlightData;
				CurrNode->FlightData = CurrNode->Next->FlightData;
				CurrNode->Next->FlightData = Temp.FlightData;
				swaps++;
			}
			CurrNode = CurrNode->Next;
		}
		if (swaps == 0)
			break;
	}
}

void FlightList::PriceHighestToLowest() {
	FlightNode* CurrNode = Head;
	FlightNode Temp;
	int swaps;
	//Descending Order
	for (int Pass = 1; (Pass < ListSize); Pass++) {
		swaps = 0;
		CurrNode = Head;
		for (int x = 0; x < ListSize - Pass; x++) {
			if (CurrNode->FlightData.GetPrice() < CurrNode->Next->FlightData.GetPrice()) {
				Temp.FlightData = CurrNode->FlightData;
				CurrNode->FlightData = CurrNode->Next->FlightData;
				CurrNode->Next->FlightData = Temp.FlightData;
				swaps++;
			}
			CurrNode = CurrNode->Next;
		}
		if (swaps == 0)
			break;
	}
}

void FlightList::DurationShortestToLongest() {
	FlightNode* CurrNode = Head;
	FlightNode Temp;
	int swaps;
	//Acsending Order
	for (int Pass = 1; (Pass < ListSize); Pass++) {
		swaps = 0;
		CurrNode = Head;
		for (int x = 0; x < ListSize - Pass; x++) {
			if (CurrNode->FlightData.GetDuration() > CurrNode->Next->FlightData.GetDuration()) {
				Temp.FlightData = CurrNode->FlightData;
				CurrNode->FlightData = CurrNode->Next->FlightData;
				CurrNode->Next->FlightData = Temp.FlightData;
				swaps++;
			}
			CurrNode = CurrNode->Next;
		}
		if (swaps == 0)
			break;
	}
}

void FlightList::DurationLongestToShortest() {
	FlightNode* CurrNode = Head;
	FlightNode Temp;
	int swaps;
	//Descending Order
	for (int Pass = 1; (Pass < ListSize); Pass++) {
		swaps = 0;
		CurrNode = Head;
		for (int x = 0; x < ListSize - Pass; x++) {
			if (CurrNode->FlightData.GetDuration() < CurrNode->Next->FlightData.GetDuration()) {
				Temp.FlightData = CurrNode->FlightData;
				CurrNode->FlightData = CurrNode->Next->FlightData;
				CurrNode->Next->FlightData = Temp.FlightData;
				swaps++;
			}
			CurrNode = CurrNode->Next;
		}
		if (swaps == 0)
			break;
	}
}

bool FlightList::IsEmpty() { 
	return Head == NULL;
}

void FlightList::DisplayList() {
	FlightNode* CurrNode = Head;
	int i = 0;
	while (CurrNode) {
		cout << ++i << ")";
		CurrNode->FlightData.PrintDetails();
		cout << "----------------------------------" << endl;
		CurrNode = CurrNode->Next;
	}
}

bool FlightList::DeleteNode(string CancelNum) {
	// 3 cases to consider
	// 1st case: no data at all in list
	if (IsEmpty()) {
		return false;
	}
	//2nd case: if the deleted one is actually the first element of the list;
	if ((Head->FlightData.GetFlightID() == CancelNum)) {
		Head = Head->Next;
		return true;
	}

	//3rd case: if the deleted is within the linked list.
	FlightNode* CurrentNode = Head;
	while (CurrentNode) {                                                                                ///
		if ((CurrentNode->Next->FlightData.GetFlightID() == CancelNum)) {
			CurrentNode->Next = CurrentNode->Next->Next;
			return true;
		}
		CurrentNode = CurrentNode->Next;
	}
	return false;
}

Flight FlightList::SearchNode(int index) {
	FlightNode* CurrentNode = Head;
	for (int i = 0; i < index-1; i++) {
		CurrentNode = CurrentNode->Next;
	}
	return CurrentNode->FlightData;
}
