#include "FLightList.h"

FlightList::FlightList() {
	Head = NULL;
	ListSize = 0;
}

void FlightList::InsertNode(Flight NewFlight) {
	FlightNode* NewNode = new FlightNode;
	NewNode->FlightData = NewFlight;
	NewNode->Next = Head;
	Head = NewNode;
	ListSize++;
}

int FlightList::GetSize() {
	return ListSize;
}

void FlightList::FindNode(string SearchKey1, string SearchKey2, FlightList Result) {
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
	FlightNode* Temp;
	int swaps;
	//Acsending Order
	for (int Pass = 1; (Pass < ListSize); Pass++) {
		swaps = 0;
		for (int x = 0; x < ListSize - Pass; x++) {
			if (CurrNode->FlightData.GetPrice() > CurrNode->Next->FlightData.GetPrice()) {
				Temp->FlightData = CurrNode->FlightData;
				CurrNode->FlightData = CurrNode->Next->FlightData;
				CurrNode->Next->FlightData = Temp->FlightData;
				swaps++;
			}
		}
		if (swaps == 0)
			break;
	}
}

bool FlightList::IsEmpty() { return (Head == NULL); }