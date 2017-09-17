#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<fstream>
#include<iterator>
#include<algorithm>
#include<numeric>
#include<utility>
#include<functional>
#include<stdio.h>
#include<assert.h>
#include<memory.h>
#include<bitset>
using namespace std;

#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lp(i, n)		for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)

typedef long long         ll;
const ll OO = 1e8;

const double EPS = (1e-7);
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

#define pb					push_back
#define MP					make_pair
#define P(x)				cout<<#x<<" = { "<<x<<" }\n"
typedef long double   	  ld;
typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;

struct Node {
	int data;
	Node* next;
};

Node* insertAtEnd(Node* head, int data) {
	Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;
	if (head == NULL) {
		temp->next = head;
		head = temp;
		return head;
	}
	Node* temp2 = head;
	while (temp2->next != NULL) {
		temp2 = temp2->next;
	}
	temp2->next = temp;
	return head;
}

Node* reverse(Node* current, Node* head)
{
	if (current == NULL)
		return NULL;
	if (current->next == NULL) {
		head = current;
		return head;
	}
	head = reverse(current->next, head);
	current->next->next = current;
	current->next = NULL;
	return head;
}

void print(Node* head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

Node* segregate(Node* root)
{
	Node* current = root;
	Node* evenHead = NULL;
	Node* lastEven = NULL;
	Node* oddHead = NULL;
	Node* lastOdd = NULL;

	while (current != NULL)
	{
		if (current->data % 2 == 0)
		{
			if (evenHead == NULL)
			{
				evenHead = current;
				lastEven = current;
			}
			else
			{
				lastEven->next = current;
				lastEven = current;
			}
		}
		else
		{
			if (oddHead == NULL)
			{
				oddHead = current;
				lastOdd = current;
			}
			else
			{
				lastOdd->next = current;
				lastOdd = current;
			}
		}
		current = current->next;
	}

	if (evenHead != NULL)
	{
		root = evenHead;
	}

	if (lastEven != NULL)
	{
		lastEven->next = oddHead;
	}

	if (lastOdd != NULL)
	{
		lastOdd->next = NULL;
	}

	return root;
}

void findLargestOnRight(Node* head, vector<int>& output, int& index)
{
	int maxElement = -1;
	while (head != NULL)
	{
		output[index++] = maxElement;
		if (head->data > maxElement)
			maxElement = head->data;
		head = head->next;
	}
}

int main() {
	Node* head1 = NULL;
	head1 = insertAtEnd(head1, 6);
	head1 = insertAtEnd(head1, 5);
	head1 = insertAtEnd(head1, 2);
	head1 = insertAtEnd(head1, 3);
	head1 = insertAtEnd(head1, 1);
	head1 = reverse(head1, head1);
	vector<int> output(5);
	int index = 0;
	findLargestOnRight(head1, output, index);
	reverse(output.begin(), output.end());
	head1 = reverse(head1, head1);
	for (int i = 0; i < output.size(); i++)
		cout << output[i] << " ";
	cout << endl;
	print(head1);
	return 0;
}

