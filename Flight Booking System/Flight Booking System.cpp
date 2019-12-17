// Flight Booking System.cpp : Defines the entry point for the application.
#include "Flight Booking System.h"
#include <conio.h>
int main() {
	
	FlightList Flights;
	LoadData(Flights);

	string Searching = "Searched for flights";
	string Booking = "Booked a flight";
	string Cancelling = "Cancelled a flight";
	string LoggingIn = "Logged in";
	string Viewing = "Viewed booked flights";
	
	PassengerList Users;
	Users.InsertNode(Passenger("Abdullah", "AlSolaiman", "135789", "password123"));
	Users.InsertNode(Passenger("Irfan", "Azim", "246810", "password321"));
	Users.InsertNode(Passenger("Tareq", "Al-Ahdal", "1234567", "myPassword"));
	

	// right now we have a Linked List of Passenger called "List"
	// we go on with performing actions on it using the function findUser in Searching cpp.
	
	Passenger Temp;  // declaring temp object, to use it late in the List::FindNode(Passenger PanssengrToFind) method.

	Art("Welcome to");
	Art("Fligh MS");
	cout << endl << endl;
	
SignUp:
	string SignFName, SignLName, SignPassport, SignPassword;
	cout << "WELCOME TO INFINITE LEPAK AIRLINE MANAGEMENT SYSTEM" << endl;
	cout << "DO you want to sign up or login?" << endl;
	cout << "1.Sign up" << endl;
	cout << "2.Log-in" << endl;
	cout << "3.Exit the program" << endl;
	cout << " Input: ";
	int StartInput;
	cin >> StartInput;
	if (StartInput == 1) {
		cout << "Please fill in your personal info" << endl;
		cout << "First Name:";
		cin.clear();
		cin.ignore(256, '\n');
		getline(cin, SignFName);
		cout << "Last Name:";
		getline(cin, SignLName);
		cout << "Passport Number:";
		getline(cin, SignPassport);
		cout << "Password:";
		getline(cin, SignPassword);
		Passenger SignIn(SignFName, SignLName, SignPassport, SignPassword);
		Users.InsertNode(SignIn);
		cout << "Your account is successfully created" << endl;
		goto SignUp;
	}
	else if (StartInput == 2)
		goto Login;
	else {
		return 0;
	}

Login:
	cin.clear();
	cin.ignore(256, '\n');
	cout << "First Name: ";
	string FName;
	getline(cin, FName);
	Temp.SetFirstName(FName);


	cout << "Last Name: ";
	string LName;
	getline(cin, LName);
	Temp.SetLastName(LName);


	cout << "Password: ";
	string Pass;
	//getline(cin, Pass);
	char temp = getch();

	while (temp != '\r')
	{
		if ((temp == 8 || temp == 127) && !Pass.empty())
		{
			cout << "\b \b";
			Pass.erase(Pass.size() - 1);

		}
		else {
			std::cout << '*';
			Pass += temp;
			temp = getch();
		}
	}
	Temp.SetPassword(Pass);
	cout << endl;
	
	PassengerNode* theUser = Users.FindNode(Temp);    
	if (!(theUser)) {
		cout << "Not Found" << endl;
		goto Login;
	}
	
	theUser->PassengerData.RecordActivity(LoggingIn);
	TryAgain:
	int Choice = MainMenu();
	
	switch (Choice) {
		case 1: {
			SearchAgain:
			cin.ignore();
			cout << endl;
			theUser->PassengerData.RecordActivity(Searching);
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
				else if (2 == Choice)
					Result.PriceHighestToLowest();
			}
			else if ('d' == POrD) {
				cout << "By Duration:" << endl
					<< "----------------------------------" << endl
					<< "[1] Shortest to Longest" << endl
					<< "[2] Longest to Shortest" << endl
					<< "Choice: ";
				cin >> Choice;
				if (1 == Choice)
					Result.DurationShortestToLongest();
				if (2 == Choice)
					Result.DurationLongestToShortest();
			}

			Result.DisplayList();
	
			cout << "Choice: ";
			cin >> Choice;
			theUser->PassengerData.RecordActivity(Booking);
			theUser->PassengerData.BookFlight(Result.SearchNode(Choice));
			goto TryAgain;
		}
		case 2: {
			theUser->PassengerData.RecordActivity(Viewing);
			if (theUser->PassengerData.ViewBookedFlights())
				goto TryAgain;
			else {
				cout << "No booked flights" << endl << endl;
				goto TryAgain;
			}
		}
		case 3: {
			if (theUser->PassengerData.ViewBookedFlights()) {
				cout << "Enter the flight ID that you wish to cancel: ";
				string CancelNum;
				cin.ignore();
				getline(cin, CancelNum);
				theUser->PassengerData.CancelFlight(CancelNum);
				theUser->PassengerData.RecordActivity(Cancelling);
				goto TryAgain;
			}
			else {
				cout << "No booked flights" << endl << endl;
				goto TryAgain;
			}
		}
		case 4: {
			theUser->PassengerData.ShowActivities();
			goto TryAgain;
		}
		case 5: {
			cout << "Logged out" << endl;
			cin.ignore();
			goto SignUp;
		}
		case 6: {
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
