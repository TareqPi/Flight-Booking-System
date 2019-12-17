#ifndef ACTIVITYSTACK_H
#define ACTIVITYSTACK_H
#include <iostream>
using std::string;
class nodeStack{
	public:
		string data;
		nodeStack* next;
};

class ActivityStack {
public:
	nodeStack* top;
	void createStack();
	void push(string);
	void pop();
	string stackTop();
	bool isEmpty();
};

#endif
