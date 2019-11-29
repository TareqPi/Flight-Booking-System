#include "Flight Booking System.h"

int SequentialSearch(string SearchKey1, string SearchKey2, int ArraySize, Flight Array[], Flight* matches[]) {
	int j = 0;
	for (int i = 0; i < ArraySize; i++) {
		if (Array[i].GetSource() == SearchKey1)
			if (Array[i].GetDestination() == SearchKey2)
				matches[j++] = &Array[i]; //matches stored in an array
	}
	return j; //total number of matches
}

