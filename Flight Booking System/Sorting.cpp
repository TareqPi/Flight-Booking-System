//Used Algorithms: Merge Sort, Improved Bubble Sort
#include "Flight.h"
#include "FlightList.h"

void Merge(Flight[], int, int, int);

void MergeSort(Flight Array[], int First, int Last) {
	if (First < Last) {
		int Mid = (First + Last) / 2;
		// sort left half Array
		MergeSort(Array, First, Mid);
		// sort right half Array
		MergeSort(Array, Mid + 1, Last);
		// merge the two halves
		Merge(Array, First, Mid, Last);
	}
}

void Merge(Flight Array[], int First, int Mid, int Last) {
	Flight* TempArray = new Flight[Last + 1];
	int First1 = First; // start of first subarray
	int Last1 = Mid; // end of first subarray
	int First2 = Mid + 1; // start of second subarray
	int Last2 = Last; // end of second subarray
	int Index = First1; // next available location in tempArray
	for (; (First1 <= Last1) && (First2 <= Last2); Index++) {
		if (Array[First1].GetSource() < Array[First2].GetSource()) {
			TempArray[Index] = Array[First1];
			First1++;
		}
		else {
			TempArray[Index] = Array[First2];
			First2++;
		}
	}

	for (; First1 <= Last1; First1++, Index++)
		TempArray[Index] = Array[First1];
	for (; First2 <= Last2; First2++, Index++)
		TempArray[Index] = Array[First2];

	for (Index = First; Index <= Last; ++Index)
		Array[Index] = TempArray[Index];

	delete [] TempArray;
}

//void PriceLowestToHighest(FlightList Flights, int ArraySize) {
//	bool Unsorted = true;
//	Flight* Temp;
	//Acsending Order
//	for (int Pass = 1; (Pass < ArraySize) && Unsorted; Pass++) {
//		Unsorted = false;
//		for (int x = 0; x < ArraySize - Pass; x++) {
//			if (Array[x]->GetPrice() > Array[x + 1]->GetPrice()) {
//				Temp = Array[x];
//				Array[x] = Array[x + 1];
//				Array[x + 1] = Temp;
//				Unsorted = true;
//			}
//		}
//	}
//}

void PriceHighestToLowest(Flight* Array[], int ArraySize) {
	bool Unsorted = true;
	Flight* Temp;
	//Descending Order
	for (int Pass = 1; (Pass < ArraySize) && Unsorted; Pass++) {
		Unsorted = false;
		for (int x = 0; x < ArraySize - Pass; x++) {
			if (Array[x]->GetPrice() < Array[x + 1]->GetPrice()) {
				Temp = Array[x];
				Array[x] = Array[x + 1];
				Array[x + 1] = Temp;
				Unsorted = true;
			}
		}
	}
}

void DurationShortestToLongest(Flight* Array[], int ArraySize) {
	bool Unsorted = true;
	Flight* Temp;
	//Acscending Order
	for (int Pass = 1; (Pass < ArraySize) && Unsorted; Pass++) {
		Unsorted = false;
		for (int x = 0; x < ArraySize - Pass; x++) {
			if (Array[x]->GetDuration() > Array[x + 1]->GetDuration()) {
				Temp = Array[x];
				Array[x] = Array[x + 1];
				Array[x + 1] = Temp;
				Unsorted = true;
			}
		}
	}
}

void DurationLongestToShortest(Flight* Array[], int ArraySize) {
	bool Unsorted = true;
	Flight* Temp;
	//Descending Order 
	for (int Pass = 1; (Pass < ArraySize) && Unsorted; Pass++) {
		Unsorted = false;
		for (int x = 0; x < ArraySize - Pass; x++) {
			if (Array[x]->GetDuration() < Array[x + 1]->GetDuration()) {
				Temp = Array[x];
				Array[x] = Array[x + 1];
				Array[x + 1] = Temp;
				Unsorted = true;
			}
		}
	}
}
