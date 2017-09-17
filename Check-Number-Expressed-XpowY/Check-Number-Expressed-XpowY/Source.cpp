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

bool checkAvailable(int n)
{
	if (n == 1)
		return true;
	
	int factor = 2;
	while (factor <= sqrt(n))
	{
		int number = n;
		while (number % factor == 0)
			number = number / factor;
		if (number == 1)
			return true;
		
		factor++;
	}
	return false;

}

bool checkAvailable2nd(int n)
{
	if (n == 1)
		return true;
	for (int i = 2; i <= sqrt(n); i++)
	{
		double value = log(n) / log(i);
		if (value - (int)value < 0.000000001)
			return true;
	}
	return false;
}


int main() {
	cout << checkAvailable(624) << endl;
	cout << checkAvailable2nd(624) << endl;

	return 0;
}

