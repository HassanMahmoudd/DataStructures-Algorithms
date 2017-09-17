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

int countUniqueBST(int n, vector<int> solutions)
{
	if (n < 0) return -1;
	if (n == 0 | n == 1)
		return 1;
	int possibilities = 0;
	for (int i = 0; i < n; i++)
	{
		if (solutions[i] == -1)
			solutions[i] = countUniqueBST(i, solutions);
		if (solutions[n - i - 1] == -1)
			solutions[n - i - 1] = countUniqueBST(n - i - 1, solutions);
		possibilities += solutions[i] * solutions[n - i - 1];
	}
	return possibilities;
}

int main() {
	vector<int> solutions(3, -1);
	cout << countUniqueBST(3, solutions) << endl;

	return 0;
}

