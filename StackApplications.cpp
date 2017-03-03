#include <iostream>
#include "Stack.h"
#include <stack>
#include <string>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* top = NULL;
void push(int n);
void pop();
void print();
void reverseLinkedList();
void reverseString(char*, int);
bool areParanthesesBalanced(string);
bool arePair(char, char);

int main()
{ 
	Stack S;
	S.push(2);
	S.push(5);
	S.push(10);
	S.print();
	S.pop();
	S.push(12);
	S.print();
	push(2);
	push(5);
	push(10);
	print();
	pop();
	push(12);
	print();
	reverseLinkedList();
	print();
	char C[101] = "Hello";
	reverseString(C, strlen(C));
	cout << C << endl;
	string expression = "{()}";
	if (areParanthesesBalanced(expression))
		cout << "Balanced" << endl;
	else
		cout << "Not Balanced" << endl;
}

void push(int n) {
	Node* temp = new Node;
	temp->data = n;
	temp->next = top;
	top = temp;
}

void pop() {
	if (top == NULL)
		return;
	Node* temp = top;
	top = top->next;
	delete temp;
}

void print() {
	Node* temp = top;
	cout << "Stack is: ";
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

void reverseLinkedList() {
	Node* temp = top;
	if (temp == NULL)
		return;
	stack<Node*> S;
	while (temp != NULL) {
		S.push(temp);
		temp = temp->next;
	}
	temp = S.top();
	top = temp;
	S.pop();
	while (!S.empty()) {
		temp->next = S.top();
		S.pop();
		temp = temp->next;
	}
	temp->next = NULL;
}

void reverseString(char* C, int n) {
	stack<char> S;
	for (int i = 0; i < n; i++) {
		S.push(C[i]);
	}
	for (int i = 0; i < n; i++) {
		C[i] = S.top();
		S.pop();
	}
}

bool areParanthesesBalanced(string exp) {
	stack<char> S;
	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			S.push(exp[i]);
		else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if (S.empty() || !arePair(S.top(), exp[i]))
				return false;
			else
				S.pop();
		}
	}
	return S.empty() ? true : false;
}

bool arePair(char first, char second) {
	if (first == '(' && second == ')') 
		return true;
	else if (first == '{' && second == '}') 
		return true;
	else if (first == '[' && second == ']') 
		return true;
	return false;
}