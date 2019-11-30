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
		void InsertNode(Flight);
		int GetSize() const;

		void FindNode(string, string, FlightList&);
		void PriceLowestToHighest();
		void PriceHighestToLowest();
		void DurationShortestToLongest();
		void DurationLongestToShortest();
		Flight SearchNode(int);
		bool DeleteNode(string);
		void DisplayList();
};

#endif
