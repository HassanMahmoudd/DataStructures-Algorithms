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

void findShortestRange(vector<vector<int>> lists)
{
	vector<int> pointers(lists.size(), 0);
	int minRange = INT_MAX;
	int min = INT_MAX;
	int max = INT_MIN;
	int finalMin = INT_MAX;
	int finalMax = INT_MIN;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
	for (int i = 0; i < lists.size(); i++)
	{
		if (lists[i].size() > 0)
		{
			Q.push(make_pair(lists[i][0], i));
			if (lists[i][0] > max)
				max = lists[i][0];
		}
		else
		{
			cout << "Error one of the lists is empty" << endl;
			return;
		}
		
	}
	while (true)
	{
		int minListIndex = Q.top().second;
		min = Q.top().first;
		Q.pop();

		if ((max - min) < minRange)
		{
			finalMax = max;
			finalMin = min;
			minRange = max - min;
		}

		if (pointers[minListIndex] + 1 < lists[minListIndex].size())
		{
			pointers[minListIndex]++;
			if (lists[minListIndex][pointers[minListIndex]] > max)
				max = lists[minListIndex][pointers[minListIndex]];
			Q.push(make_pair(lists[minListIndex][pointers[minListIndex]], minListIndex));
		}

		else
		{
			cout << "{" << finalMin << "," << finalMax << "}" << endl;
			return;
		}
	}
}

int main() {
	vector<vector<int>>	lists = 
	{ { 4, 10, 15, 24, 26},
	{ 0, 9, 12, 20 },
	{ 5, 18, 22, 30 } };
	
	findShortestRange(lists);

	return 0;
}

