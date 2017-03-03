#include <iostream>
#include <cstdio>
using namespace std;

void quickSort(int A[], int start, int end);
int partition(int A[], int start, int end);

int main(int argc, char ** argv)
{
	cout << "Hello, World!" << endl;
	int A[] = { 3, 2, 1, 5, 6, 9, 7 };
	quickSort(A, 0, 6);
	for (int i = 0; i < 7; i++) {
		cout << A[i] << " ";
	}
	return 0;
}

void quickSort(int A[], int start, int end) {
	if (start < end) {
		int partitionIndex = partition(A, start, end);
		quickSort(A, start, partitionIndex-1);
		quickSort(A, partitionIndex + 1, end);
	}
}

int partition(int A[], int start, int end) {
	int pivot = A[end];
	int partitionIndex = start;
	for (int i = start; i < end; i++) {
		if (A[i] <= pivot) {
			int temp = A[partitionIndex];
			A[partitionIndex] = A[i];
			A[i] = temp;
			partitionIndex++;
		}
	}
	int temp = A[partitionIndex];
	A[partitionIndex] = A[end];
	A[end] = temp;
	return partitionIndex;
}