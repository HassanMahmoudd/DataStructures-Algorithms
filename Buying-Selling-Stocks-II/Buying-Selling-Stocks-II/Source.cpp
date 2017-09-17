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

int maximumProfit(vector<int> matrix)
{
	int currentProfit = 0;
	int totalProfit = 0;
	for (int i = 1; i < matrix.size(); i++)
	{
		currentProfit = matrix[i] - matrix[i-1];
		if (currentProfit > 0)
			totalProfit += currentProfit;
	}
	return totalProfit;
}

int main() {
	vector<int> matrix;
	matrix.push_back(100);
	matrix.push_back(80);
	matrix.push_back(120);
	matrix.push_back(130);
	matrix.push_back(70);
	matrix.push_back(60);
	matrix.push_back(100);
	matrix.push_back(125);
	cout << maximumProfit(matrix) << endl;

	return 0;
}

