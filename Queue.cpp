#include<iostream>
using namespace std;
#define MAX_SIZE 101

struct Node {
	int data;
	Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void enqueueLinkedList(int n) {
	Node* temp = new Node;
	temp->data = n;
	temp->next = NULL;
	if (front == NULL && rear == NULL) {
		front = temp;
		rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
}

void dequeueLinkedList() {
	Node* temp = front;
	if (front == NULL) {
		cout << "Queue is empty" << endl;
		return;
	}
	if (front == rear) {
		front = NULL;
		rear = NULL;
	}
	else {
		front = front->next;
	}
	free(temp);
}

int frontLinkedList() {
	if (front == NULL) {
		cout << "Queue is empty" << endl;
		return -1;
	}
	return front->data;
}

void printLinkedList() {
	Node* temp = front;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

class Queue
{
private:
	int A[MAX_SIZE];
	int front, rear;
public:
	Queue() {
		front = -1;
		rear = -1;
	}

	bool isFull() {
		if ((rear + 1) % MAX_SIZE == front)
			return true;
		return false;
	}

	bool isEmpty() {
		if (rear == -1 && front == -1)
			return true;
		return false;
	}

	void enqueue(int n) {
		if (isFull()) {
			cout << "Queue is full" << endl;
			return;
		}
		if (isEmpty()) {
			rear = 0;
			front = 0;
		}
		else {
			rear = (rear + 1) % MAX_SIZE;
		}
		A[rear] = n;

	}

	void dequeue() {
		if (isEmpty()) {
			cout << "Queue is empty" << endl;
			return;
		}
		else if (front == rear){
			rear = -1;
			front = -1;
		}
		else {
			front = (front + 1) % MAX_SIZE;
		}
	}

	int Front()
	{
		if (front == -1)
		{
			cout << "Queue is empty" << endl;
			return -1;
		}
		return A[front];
	}

	void print() {
		int count = (rear + MAX_SIZE - front) % MAX_SIZE + 1;
		for (int i = 0; i < count; i++)
		{
			int index = (i + front) % MAX_SIZE;
			cout << A[index] << " ";
		}
		cout << endl;
	}
};

int main() {
	enqueueLinkedList(2);
	enqueueLinkedList(4);
	enqueueLinkedList(6);
	dequeueLinkedList();
	enqueueLinkedList(8);
	printLinkedList();
	Queue Q;
	Q.enqueue(2);  
	Q.enqueue(4);  
	Q.enqueue(6);
	Q.dequeue();	  
	Q.enqueue(8);  
	Q.print();
}