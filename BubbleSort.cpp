#include <iostream>
#include <cstdio>
using namespace std;

void bubbleSort(int A[], int n);

int main(int argc, char ** argv)
{
	cout << "Hello, World!" << endl;
	int A[] = { 3, 2, 1, 5, 6, 9, 7 };
	bubbleSort(A, 7);
	for (int i = 0; i < 7; i++) {
		cout << A[i] << " ";
	}
	return 0;
}

void bubbleSort(int A[], int n) {
	bool flag;
	for (int i = 0; i < n - 1; i++) {
		flag = false;
		for (int j = 0; j < n - 1 - i; j++) {
			if (A[j+1] < A[j]) {
				int temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
				flag = true;
			}
		}
		if (!flag)
			break;
	}
}