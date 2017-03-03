#include "Stack.h"
#include <iostream>
using namespace std;
#define MAX_SIZE 101

Stack::Stack() {
	top = -1;
}

void Stack::push(int n) {
	if (top == MAX_SIZE - 1) {
		cout << "Overflow!" << endl;
		return;
	}
	A[++top] = n;
}

void Stack::pop() {
	if (top == -1) {
		cout << "Stack is empty" << endl;
		return;
	}
	--top;
}

int Stack::Top() {
	return A[top];
}

int Stack::IsEmpty()
{
	if (top == -1)
		return 1;
	return 0;
}

void Stack::print() {
	cout << "Stack is: ";
	for (int i = 0; i <= top; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}