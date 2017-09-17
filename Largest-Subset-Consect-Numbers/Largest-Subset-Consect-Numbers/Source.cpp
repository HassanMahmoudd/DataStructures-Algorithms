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

int findLargestConsectiveSubset(vector<int> matrix)
{
	unordered_map<int, int> hashMap;
	for (int i = 0; i < matrix.size(); i++)
		hashMap.insert(make_pair(matrix[i], 0));

	int largestConsectSubset = 0;
	for (int i = 0; i < matrix.size(); i++)
	{
		if (hashMap.find(matrix[i] - 1) == hashMap.end())
		{
			int temp = matrix[i];
			while (hashMap.find(temp) != hashMap.end())
				temp++;
			if ((temp - matrix[i]) > largestConsectSubset)
				largestConsectSubset = temp - matrix[i];
		}
	}
	return largestConsectSubset;
}

int main() {
	vector<int> matrix = { 1, 3, 8, 14, 4, 10, 2, 11 };
	cout << findLargestConsectiveSubset(matrix) << endl;

	return 0;
}

