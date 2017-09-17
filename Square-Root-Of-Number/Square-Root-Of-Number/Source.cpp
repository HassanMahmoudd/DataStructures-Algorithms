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

string squareRoot(int number)
{
	bool isNegative = false;
	if (number < 0)
	{
		number = number * -1;
		isNegative = true;
	}
	stringstream convert;
	convert << number;
	if (number == 1)
	{
		if (isNegative)
			return convert.str() + "i";
		return convert.str();
	}
	double start = 0;
	double end = number;
	double mid = (start + end) / 2;
	double prevMid = 0;
	double diff = mid - prevMid;
	while (((mid*mid) != number) && (diff > 0.0005))
	{
		if (mid*mid > number)
		{
			end = mid;
		}
		else
			start = mid;
		prevMid = mid;
		mid = (start + end) / 2;
		diff = abs(mid - prevMid);
	}
	convert.str("");
	convert << mid;
	if (isNegative)
		return convert.str() + "i";
	return convert.str();
	
}

int main() {
	int number = 2;
	cout << squareRoot(number) << endl;

	return 0;
}

