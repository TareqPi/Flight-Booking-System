#ifndef STACK_H
#define STACK_H

class nodeStack{
	public:
		char data;
		nodeStack* next;
};

class Stack {
private:
	nodeStack* top;
public:
	void createStack();
	void push(char);
	void pop();
	char stackTop();
	bool isEmpty();
};

#endif // !STACK_H
