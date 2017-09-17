#include <iostream>
#include "Stack.h"
#include <stack>
#include <string>
using namespace std;



int main()
{
	Stack S;
	S.push(7);
	S.push(8);
	S.push(5);
	// S.print();
	S.push(9);
	S.push(5);
	S.push(2);
	S.pop();
	S.pop();
	S.print();
	cout << S.min() << endl;
	
}