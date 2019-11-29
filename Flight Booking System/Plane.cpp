// Implementation file for the Plane class
#include "Plane.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

Plane::Plane(string ModelName) {
	_ModelName = ModelName;
	this->DetermineCapacity(ModelName);
}

Plane::Plane() {
	_ModelName = "N\\A";
	_PassengerCapacity = 0;
}

void Plane::DetermineCapacity(string ModelName) {
	if (ModelName == "Airbus A320")
		_PassengerCapacity = 180;
	else if (ModelName == "Airbus A380")
		_PassengerCapacity = 868;
	else if (ModelName == "Boeing 777")
		_PassengerCapacity = 396;
	else if (ModelName == "Boeing 737-700")
		_PassengerCapacity = 126;
	else if (ModelName == "Boeing 737-800")
		_PassengerCapacity = 189;
	else
		_PassengerCapacity = -1;
}

void Plane::SetPlaneName(string Name) {
	_ModelName = Name;
	this->DetermineCapacity(Name);
}

string Plane::GetPlaneName() const {
	return _ModelName;
}

void Plane::SetPassengerCapacity(int PassengerCapacity) {
	_PassengerCapacity = PassengerCapacity;
}
int Plane::GetPassengerCapacity() const {
	return _PassengerCapacity;
}

Plane::~Plane() {}
