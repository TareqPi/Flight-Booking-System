# CMakeList.txt : CMake project for Flight Booking System, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
Project("Flight Booking System")
# Add source to this project's executable.
add_executable (CMakeTarget "Flight Booking System.cpp" "Flight Booking System.h" "Passenger.h" "Passenger.cpp" 
"Flight.h" "Flight.cpp" "Plane.h" "Plane.cpp" "Date.h" "Date.cpp" "MainMenu.cpp"  "LoadData.cpp" "FlightList.h" 
"FlightList.cpp" "FlightNode.h" "PassengerList.h" "PassengerList.cpp" "ActivityStack.h" "ActivityStack.cpp")
# TODO: Add tests and install targets if needed.