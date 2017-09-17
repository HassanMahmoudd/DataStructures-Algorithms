#pragma once
#ifndef INCLUDE_OBJECT_HPP
#define INCLUDE_OBJECT_HPP
#define MAX_SIZE 101

struct Node
{
	int data;
	int min;
	Node* next;
};

class Stack {
private:
	Node* top;
public:
	Stack();

	void push(int n);

	void pop();

	int Top();

	int IsEmpty();

	int min();

	void print();
};
#endif
