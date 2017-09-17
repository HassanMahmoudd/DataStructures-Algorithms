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

void insertAtEnd(int data);

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

Node* detectLoop(Node* root)
{
	Node* p1 = root;
	Node* p2 = root;
	do
	{
		if (p1 == NULL || p2 == NULL || p2->next == NULL) {
			return NULL;
		}
		p1 = p1->next;
		p2 = p2->next->next;
	} while (p1 != p2);
	p1 = root;
	while (p1 != p2)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	
	return p1;
}

int main() {
	Node* head1 = NULL;
	Node* head2 = NULL;
	head1 = insertAtEnd(head1, 1);
	head1 = insertAtEnd(head1, 2);
	head1 = insertAtEnd(head1, 3);
	head1 = insertAtEnd(head1, 4);
	head1 = insertAtEnd(head1, 8);
	head1 = insertAtEnd(head1, 9);
	head1 = insertAtEnd(head1, 10);
	
	Node* temp2 = head1;
	for (int i = 0; i < 4; i++)
	{
		temp2 = temp2->next;
	}
	Node* temp1 = head1;
	while (temp1->next != NULL)
	{
		temp1 = temp1->next;
	}
	temp1->next = temp2;
	Node* result = detectLoop(head1);
	cout << result->data << endl;
	return 0;
}

