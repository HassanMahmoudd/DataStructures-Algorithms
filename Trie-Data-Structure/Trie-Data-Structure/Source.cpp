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

struct TrieNode
{
	int value;
	TrieNode* children[26];
	bool isLeafNode;
};

TrieNode* getNewTrieNode() {
	TrieNode* temp = new TrieNode();
	temp->isLeafNode = false;
	temp->value = -1;
	return temp;
}

int search(TrieNode* root, string key) {
	if (root == NULL)
	{
		return -1;
	}
	TrieNode* currentNode = root;
	int charIndex = 0;
	while ((currentNode != NULL) && (charIndex < key.size()))
	{
		int childIndex = key[charIndex] - 'a';
		
		currentNode = currentNode->children[childIndex];
		charIndex++;
	}
	if (currentNode != NULL)
	{
		return currentNode->value;
	}
	return -1;
}

TrieNode* insert(TrieNode* root, string key, int value) {
	if (root == NULL)
	{
		root = getNewTrieNode();
	}
	TrieNode* currentNode = root;
	int charIndex = 0;
	while (charIndex < key.size())
	{
		int childIndex = key[charIndex] - 'a';
		if (currentNode->children[childIndex] == NULL)
		{
			currentNode->children[childIndex] = getNewTrieNode();
		}
		currentNode = currentNode->children[childIndex];
		charIndex++;
	}
	currentNode->value = value;
	currentNode->isLeafNode = true;
	return root;
}

int main() {
	TrieNode* root = NULL;
	root = insert(root, "abb", 2);
	root = insert(root, "abbb", 3);
	cout << search(root, "abb") << endl;
	return 0;
}

