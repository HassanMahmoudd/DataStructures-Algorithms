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

int printMaxNoA(int n, vector<int> mem)
{
	if (n < 0)
		return -1;
	if (n <= 6)
		return n;
	int maxSoFar = 0;
	int maxAsWithI = 0;
	int multiplier = 2;
	for (int i = n - 3; i >= 1; i--)
	{
		if (mem[i] == -1)
			mem[i] = printMaxNoA(i, mem);

		maxAsWithI = multiplier * mem[i];

		if (maxAsWithI > maxSoFar)
			maxSoFar = maxAsWithI;

		multiplier++;
	}
	return maxSoFar;
}

int main() {
	vector<int> mem(8, -1);
	
	cout << printMaxNoA(7, mem) << endl;
	return 0;
}

