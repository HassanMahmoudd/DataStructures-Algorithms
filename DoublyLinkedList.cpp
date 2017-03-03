// hello-cout.cpp by Bill Weinman <http://bw.org/>
#include <iostream>
#include <cstdio>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node* prev;
};

Node* head;
void insertAtBeginning(int data);
void insertAtEnd(int data);
void print();
void printReverse();

int main(int argc, char ** argv)
{
	cout << "Hello, World!" << endl;
	head = NULL;
	insertAtEnd(2);
	insertAtEnd(3);
	insertAtEnd(5);
	insertAtEnd(4);
	insertAtBeginning(9);
	print();
	printReverse();
	return 0;
}

void insertAtBeginning(int data) {
	Node* temp = new(Node);
	temp->data = data;
	temp->next = NULL;
	temp->prev = NULL;
	if (head == NULL) {
		head = temp;
		return;
	}
	head->prev = temp;
	temp->next = head;
	head = temp;
}

void insertAtEnd(int data) {
	Node* temp = new(Node);
	temp->data = data;
	temp->next = NULL;
	temp->prev = NULL;
	if (head == NULL) {
		head = temp;
		return;
	}
	Node* temp2 = head;
	while (temp2->next != NULL) {
		temp2 = temp2->next;
	}
	temp2->next = temp;
	temp->prev = temp2;
}

void print() {
	Node* temp = head;
	cout << "List is ";
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

void printReverse() {
	Node* temp = head;
	if (temp == NULL) 
		return;
	cout << "List is ";
	while (temp->next != NULL) {
		temp = temp->next;
	}
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->prev;
	}
	cout << endl;
}
