// Implementation file for the Stack class
#include "Stack.h"

void Stack::createStack() {
	top = NULL;
}

void Stack::push(char newitem) {
	nodeStack* newNode;
	newNode = new (nodeStack);

	if (newNode == NULL)
		cout << "Cannot allocate memory\n";
	else {
		newNode->data = newitem;
		newNode->next = top;
		top = newNode;
	}
}

void Stack::pop() {
	nodeStack* tempNode;
	if (isEmpty())
		cout << "Sorry, cannot pop item from stack. Stack is still empty!\n";
	else {
		tempNode = top;
		top = tempNode->next;
		delete(tempNode);
	}
}

char Stack::stackTop() {
	if (isEmpty())
		cout << "Sorry, stack is still empty!\n";
	else
		return top->data;
}

bool Stack::isEmpty() {
	return (top == NULL);
}
