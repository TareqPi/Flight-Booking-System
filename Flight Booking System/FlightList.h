// Specification file for the List class
#ifndef FLIGHTLIST_H
#define FLIGHTLIST_H

#include "FlightNode.h"

class FlightList {
	private:
		FlightNode* Head;
		int ListSize;
	public:
		FlightList();
//		~FlightList();

		bool IsEmpty();
		FlightNode* InsertNode(Flight);
		int GetSize();

		FlightList FindNode(string, string, FlightList);
		void PriceLowestToHighest();
//		int DeleteNode(double x);
//		void DisplayList(void);
};

#endif
