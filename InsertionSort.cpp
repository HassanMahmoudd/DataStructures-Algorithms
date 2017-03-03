#include <iostream>
#include <cstdio>
using namespace std;

void insertionSort(int A[], int n);

int main(int argc, char ** argv)
{
	cout << "Hello, World!" << endl;
	int A[] = { 3, 2, 1, 5, 6, 9, 7 };
	insertionSort(A, 7);
	for (int i = 0; i < 7; i++) {
		cout << A[i] << " ";
	}
	return 0;
}

void insertionSort(int A[], int n) {
	int hole, value;
	for (int i = 1; i < n; i++) {
		value = A[i];
		hole = i;
		while (hole > 0 && A[hole - 1] > value) {
			A[hole] = A[hole - 1];
			--hole;
		}
		A[hole] = value;
	}
}