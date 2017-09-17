#include "Stack.h"
#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<fstream>
#include<iterator>
#include<algorithm>
#include<numeric>
#include<utility>
#include<functional>
#include<stdio.h>
#include<assert.h>
#include<memory.h>
#include<bitset>
using namespace std;
using namespace std;
#define MAX_SIZE 101

Stack::Stack() {
	top = NULL;
}

void Stack::push(int n) {
	if (top == NULL) {
		top = new Node;
		top->data = n;
		top->min = n;
		top->next = NULL;
	}
	else
	{
		Node* temp = new Node;
		temp->data = n;
		temp->next = top;
		temp->min = std::min(top->min, n);
		top = temp;
	}
}

void Stack::pop() {
	if (top == NULL)
	{
		return;
	}

	top = top->next;
}

int Stack::Top() {
	if (top == NULL)
	{
		return -1;
	}

	return top->data;
}

int Stack::IsEmpty()
{
	if (top == NULL)
		return 1;
	return 0;
}

int Stack::min()
{
	if (top == NULL)
	{
		return -1;
	}

	return top->min;

}

void Stack::print() {
	cout << "Stack is: ";
	Node* temp = top;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}