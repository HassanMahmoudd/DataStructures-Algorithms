#include <iostream>
#include <cstdio>
using namespace std;

void mergeSort(int A[], int n);
void merge(int A[], int L[], int LCount, int R[], int RCount);

int main(int argc, char ** argv)
{
	cout << "Hello, World!" << endl;
	int A[] = { 3, 2, 1, 5, 6, 9, 7 };
	mergeSort(A, 7);
	for (int i = 0; i < 7; i++) {
		cout << A[i] << " ";
	}
	return 0;
}

void mergeSort(int A[], int n) {
	if (n < 2)
		return;
	int mid = n / 2;
	int* L = new int[mid];
	int* R = new int[n - mid];
	for (int i = 0; i < mid; i++) {
		L[i] = A[i];
	}
	for (int i = mid; i < n; i++) {
		R[i - mid] = A[i];
	}
	mergeSort(L, mid);
	mergeSort(R, n - mid);
	merge(A, L, mid, R, n - mid);
	delete L;
	delete R;
}

void merge(int A[], int L[], int LCount, int R[], int RCount) {
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < LCount && j < RCount) {
		if (L[i] < R[j]) {
			A[k] = L[i];
			i++;
		}
		else {
			A[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < LCount) {
		A[k] = L[i];
		k++;
		i++;
	}
	while (j < RCount) {
		A[k] = R[j];
		k++;
		j++;
	}
}