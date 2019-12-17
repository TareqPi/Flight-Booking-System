// Implementation file for the Stack class
#include "ActivityStack.h"
#include <iostream>
using std::cout;
using std::string;

void ActivityStack::createStack() {
	top = NULL;
}

void ActivityStack::push(string newitem) {
	nodeStack* newNode;
	newNode = new nodeStack;

	if (newNode == NULL)
		cout << "Cannot allocate memory\n";
	else {
		newNode->data = newitem;
		newNode->next = top;
		top = newNode;
	}
}

void ActivityStack::pop() {
	nodeStack* tempNode;
	if (isEmpty())
		cout << "Sorry, cannot pop item from stack. Stack is still empty!\n";
	else {
		tempNode = top;
		top = tempNode->next;
		delete tempNode;
	}
}

string ActivityStack::stackTop() {
	if (isEmpty())
		cout << "Sorry, stack is still empty!\n";
	else
		return top->data;
}

bool ActivityStack::isEmpty() {
	return (top == NULL);
}
