// Specification file for the Plane class
#ifndef PLANE_H
#define PLANE_H
#include <string>
using std::string;

class Plane {
	private:
		string _ModelName;
		int _PassengerCapacity;

	public:
		Plane(string);
		Plane();
		void DetermineCapacity(string);
		void SetPlaneName(string);
		string GetPlaneName() const;
		void SetPassengerCapacity(int);
		int GetPassengerCapacity() const;
		~Plane();
};

#endif
