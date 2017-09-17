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

int getMinDepth(Node* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 0;
	int leftDepth, rightDepth;
	if (root->left == NULL)
	{
		leftDepth = INT_MAX;
	}
	else
	{
		leftDepth = getMinDepth(root->left);

	}
	if (root->right == NULL)
	{
		rightDepth = INT_MAX;
	}
	else 
	{
		rightDepth = getMinDepth(root->right);
	}
	return 1 + min(leftDepth, rightDepth);
}

int main() {
	Node* root = NULL;
	root = insert(root, 8);
	root = insert(root, 10);
	root = insert(root, 4);
	root = insert(root, 12);
	root = insert(root, 2);
	root = insert(root, 5);
	int minDepth = getMinDepth(root);
	cout << minDepth << endl;
	return 0;
}

