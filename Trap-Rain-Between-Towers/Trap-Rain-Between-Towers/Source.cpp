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

int countWaterTrapped(vector<int> matrix)
{
	vector<int> maxSeenRight(matrix.size());
	int maxSeenSoFar = 0;
	int maxSeenLeft = 0;
	int rainWater = 0;
	for (int i = matrix.size() - 1; i >= 0; i--)
	{
		if (matrix[i] > maxSeenSoFar)
		{
			maxSeenSoFar = matrix[i];
			maxSeenRight[i] = maxSeenSoFar;
		}
		else
			maxSeenRight[i] = maxSeenSoFar;
	}
	for (int i = 0; i < matrix.size(); i++)
	{
		rainWater += max(min(maxSeenRight[i], maxSeenLeft) - matrix[i], 0);
		if (matrix[i] > maxSeenLeft)
			maxSeenLeft = matrix[i];
	}
	return rainWater;
}

int main() {
	vector<int> matrix;
	matrix.push_back(1);
	matrix.push_back(5);
	matrix.push_back(2);
	matrix.push_back(3);
	matrix.push_back(1);
	matrix.push_back(7);
	matrix.push_back(2);
	matrix.push_back(4);
	cout << countWaterTrapped(matrix) << endl;

	return 0;
}

