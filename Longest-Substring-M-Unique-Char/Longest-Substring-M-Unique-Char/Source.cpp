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
#include<unordered_map>
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

bool lessThanM(unordered_map<char, int> hashMap, int M)
{
	int count = 0;
	for (auto itr = hashMap.begin(); itr != hashMap.end(); itr++)
	{
		if (itr->second != 0)
			count++;
	}
	if (count > M)
		return false;
}

string longestSubstringMUnique(string text, int M)
{
	int start = 0, end = 0, windowSize = 1, windowStart = 0;
	unordered_map<char, int> hashMap;
	hashMap.insert(make_pair(text[0], 1));
	for (int i = 1; i < text.size(); i++)
	{
		if (hashMap.find(text[i]) == hashMap.end())
			hashMap.insert(make_pair(text[i], 1));
		else
		{
			int value = hashMap.find(text[i])->second;
			hashMap.find(text[i])->second = ++value;
		}
		end++;
		while (!lessThanM(hashMap, M)) 
		{
			int value = hashMap.find(text[start])->second;
			hashMap.find(text[start])->second = --value;
			start++;
		}
		if (end - start + 1 > windowSize)
		{
			windowSize = end - start + 1;
			windowStart = start;
		}
	}
	return text.substr(windowStart, windowSize);
}

int main() {
	string text = "karappa";
	cout << longestSubstringMUnique(text, 2) << endl;

	return 0;
}

