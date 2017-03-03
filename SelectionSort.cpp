#include <iostream>
#include <cstdio>
using namespace std;

void selectionSort(int A[], int n);

int main(int argc, char ** argv)
{
	cout << "Hello, World!" << endl;
	int A[] = { 3, 2, 1, 5, 6, 9, 7 };
	selectionSort(A, 7);
	for (int i = 0; i < 7; i++) {
		cout << A[i] << " ";
	}
	return 0;
}

void selectionSort(int A[], int n) {
	int iMin;
	for (int i = 0; i < n - 1; i++) {
		iMin = i;
		for (int j = i; j < n; j++) {
			if (A[j] < A[i]) {
				iMin = j;
			}
		}
		int temp = A[i];
		A[i] = A[iMin];
		A[iMin] = temp;
	}
}