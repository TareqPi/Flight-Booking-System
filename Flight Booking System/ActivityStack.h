#ifndef ACTIVIYSTACK_H
#define ACTIVITYSTACK_H
#include <string>
class nodeStack{
	public:
		string data;
		nodeStack* next;
};

class Stack {
private:
	nodeStack* top;
public:
	void createStack();
	void push(string);
	void pop();
	string stackTop();
	bool isEmpty();
};

#endif
