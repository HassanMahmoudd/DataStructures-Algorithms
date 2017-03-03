#include <iostream>
#include <string>

using namespace std;

struct Node {
	int data;
	Node* next;
};

void insertAtBeginning(int data);
void insertAtPosition(int data, int n);
void insertAtEnd(int data);
void deleteAtPosition(int n);
void reverseIterative();
void reverseRecursive(Node* p);
void printRecursive(Node* p);
void printBackwardRecursive(Node* p);
void print();

Node* head;

int main(int argc, char ** argv)
{
	head = NULL;
	insertAtBeginning(5);
	insertAtBeginning(6);
	insertAtBeginning(2);
	insertAtBeginning(3);
	insertAtPosition(8, 2);
	insertAtPosition(9, 4);
	print();
	deleteAtPosition(3);
	print();
	insertAtEnd(7);
	print();
	reverseIterative();
	print();
	reverseRecursive(head);
	print();
	printRecursive(head);
	printBackwardRecursive(head);
	return 0;
}

void insertAtBeginning(int data) {
	Node* temp = new Node;
	temp->data = data;
	temp->next = head;
	head = temp;
}

void insertAtPosition(int data, int n) {
	Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;
	if (n == 1) {
		temp->next = head;
		head = temp;
		return;
	}
	Node* temp2 = head;
	for (int i = 0; i < n - 2; i++) {
		temp2 = temp2->next;
	}
	temp->next = temp2->next;
	temp2->next = temp;
}

void insertAtEnd(int data) {
	Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;
	if (head == NULL) {
		temp->next = head;
		head = temp;
		return;
	}
	Node* temp2 = head;
	while (temp2->next != NULL) {
		temp2 = temp2->next;
	}
	temp2->next = temp;
}

void deleteAtPosition(int n) {
	Node* temp = head;
	if (n == 1) {
		head = temp->next;
		delete temp;
		return;
	}
	for (int i = 0; i < n - 2; i++) {
		temp = temp->next;
	}
	Node* temp2 = temp->next;
	temp->next = temp2->next;
	delete temp2;
}

void reverseIterative() {
	Node* current = head;
	Node* prev = NULL;
	Node* next;
	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}

void reverseRecursive(Node* p) {
	if (p->next == NULL) {
		head = p;
		return;
	}
	reverseRecursive(p->next);
	Node* q = p->next;
	q->next = p;
	p->next = NULL;
}

void printRecursive(Node* p) {
	if (p == NULL) {
		cout << endl;
		return;
	}
	cout << p->data << " ";
	printRecursive(p->next);
}

void printBackwardRecursive(Node* p) {
	if (p == NULL) {
		return;
	}
	printBackwardRecursive(p->next);
	cout << p->data << " ";
}

void print() {
	Node* temp = head;
	cout << "List is: ";
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
