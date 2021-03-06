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

struct Node
{
	int data;
	Node* left;
	Node* right;
};

Node* firstNode = NULL;
Node* lastNode = NULL;
Node* prevNode = NULL;

Node* getNewNode(int data) {
	Node* temp = new Node();
	temp->data = data;
	temp->right = NULL;
	temp->left = NULL;
	return temp;
}

Node* insert(Node* root, int data) {
	if (root == NULL) {
		Node* temp = getNewNode(data);
		root = temp;
	}
	else if (data < root->data) {
		root->left = insert(root->left, data);
	}
	else {
		root->right = insert(root->right, data);
	}
	return root;
}

void inOrder(Node* root)
{
	if (root == NULL)
		return;
	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
}

Node* findNthLargest(Node* root, int n, vector<int>& count)
{
	if (root == NULL)
		return NULL;
	Node* nth_largest = NULL;
	nth_largest = findNthLargest(root->right, n, count);
	if (nth_largest == NULL)
	{
		count[0]++;
		if (count[0] == n)
		{
			nth_largest = root;
		}
	}

	if (nth_largest == NULL)
		nth_largest = findNthLargest(root->left, n, count);
	return nth_largest;
}

int main() {
	Node* root = NULL;
	root = insert(root, 10);
	root = insert(root, 5);
	root = insert(root, 15);
	root = insert(root, 4);
	root = insert(root, 7);
	root = insert(root, 14);
	root = insert(root, 17);
	//int count[1];
	//count[0] = 0;
	vector<int> count = { 0 };
	Node* result = findNthLargest(root, 3, count);
	cout << result->data << endl;
	return 0;
}

