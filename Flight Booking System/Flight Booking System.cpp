// Flight Booking System.cpp : Defines the entry point for the application.
//
#include "Flight Booking System.h"

int main() {
	const int Size = 27;
	//Flight* Flights = new Flight[Size];

	//MergeSort(Flights, 0, Size - 1); //Order all the flights alphabetically
	
	FlightList Flights;
	LoadData(Flights);

	const int NumOfUsers = 3;
	Passenger Users[NumOfUsers] = { Passenger("Abdullah", "AlSolaiman", "135789", "password123"), 
				Passenger("Irfan", "Azim", "246810", "password321"),
				Passenger("Tareq", "Al-Ahdal", "1234567", "myPassword") };
	
	Login:
	cout << "First Name: ";
	string FName;
	getline(cin, FName);
	cout << "Last Name: ";
	string LName;
	getline(cin, LName);
	cout << "Password: ";
	string Pass;
	getline(cin, Pass);
	
	int ID = findUser(Users, FName, LName, Pass, NumOfUsers);
	if (ID == -1) {
		cout << "Not Found" << endl;
		goto Login;
	}

	TryAgain:
	int Choice = MainMenu();
	
	switch (Choice) {
		case 1: {
			SearchAgain:
			cin.ignore();
			cout << endl;
			cout << "Source: ";
			string Source;
			getline(cin, Source);
			cout << "Destination: ";
			string Destination;
			getline(cin, Destination);
			cout << endl;

			FlightList Result;
			Flights.FindNode(Source, Destination, Result);
			if (Result.IsEmpty()) {
				cout << "No Flights Found" << endl;
				goto SearchAgain;
			}

			cout << "Sort it based on price or duration? (p/d): ";
			char POrD;
			cin >> POrD;
			if ('p' == POrD) {
				cout << "By Price:" << endl
					<< "----------------------------------" << endl
					<< "[1] Lowest to highest" << endl
					<< "[2] Highest to lowest" << endl
					<< "Choice: ";
				cin >> Choice;
				if (1 == Choice)
					Result.PriceLowestToHighest();
				//PriceLowestToHighest(Result, ResultArraySize);
				else if (2 == Choice)
					cout << "still" << endl;
				//PriceHighestToLowest(Result, ResultArraySize);
			}
			else if ('d' == POrD) {
				cout << "By Duration:" << endl
					<< "----------------------------------" << endl
					<< "[1] Shortest to Longest" << endl
					<< "[2] Longest to Shortest" << endl
					<< "Choice: ";
				cin >> Choice;
				if (1 == Choice)
					cout << "still" << endl;
				//	DurationShortestToLongest(Result, ResultArraySize);
				if (2 == Choice)
					cout << "still" << endl;
				//	DurationLongestToShortest(Result, ResultArraySize);
			}

			Result.DisplayList();

			//for (int i = 0; i < ResultArraySize; i++) {
			//		cout << 1 + i << ")";
			//	Result[i]->PrintDetails();
			//	cout << "----------------------------------" << endl;
			//}
			//cout << "Choice: ";
			//cin >> Choice;
			//Users[ID].BookFlight(*Result[Choice - 1]);
			//goto TryAgain;
		}
		case 2: {
			if (Users[ID].ViewBookedFlights())
				goto TryAgain;
			else {
				cout << "No booked flights" << endl << endl;
				goto TryAgain;
			}
		}
		case 3: {
			if (Users[ID].ViewBookedFlights()) {
				cout << "Enter the flight ID that you wish to cancel: ";
				string CancelNum;
				cin.ignore();
				getline(cin, CancelNum);
				Users[ID].CancelFlight(CancelNum);
				goto TryAgain;
			}
			else {
				cout << "No booked flights" << endl << endl;
				goto TryAgain;
			}
		}
		case 4: {
			cout << "Logged out" << endl;
			cin.ignore();
			goto Login;
		}
		case 5: {
			cout << "Logged out" << endl;
			break;
		}
		default: {
			cout << "Try again" << endl << endl;
			goto TryAgain;
		}
	}
	return 0;
}