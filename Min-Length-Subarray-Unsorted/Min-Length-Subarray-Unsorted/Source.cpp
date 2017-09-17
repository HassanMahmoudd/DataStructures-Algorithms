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


void minLengthSubarray(vector<int> matrix)
{
	int startIndex, endIndex;
	for (int i = 0; i < matrix.size() - 1; i++)
	{
		if (matrix[i] > matrix[i + 1])
		{
			startIndex = i;
			break;
		}
	}
	for (int j = matrix.size() - 1; j >= 1; j--)
	{
		if (matrix[j] < matrix[j - 1])
		{
			endIndex = j;
			break;
		}
	}

	auto maxElement = max_element(matrix.begin() + startIndex, matrix.begin() + endIndex);
	auto minElement = min_element(matrix.begin() + startIndex, matrix.begin() + endIndex);

	for (int i = 0; i < startIndex; i++)
	{
		if (matrix[i] > *minElement)
		{
			startIndex = i;
			break;
		}
	}

	for (int j = matrix.size() - 1; j > endIndex; j--)
	{
		if (matrix[j] < *maxElement)
		{
			endIndex = j;
			break;
		}
	}
	cout << startIndex << " to " << endIndex << endl;

}


int main() {
	vector<int> matrix(10);
	matrix = { 1, 4, 7, 3, 10, 48, 17, 26, 30, 45, 50, 62};
	minLengthSubarray(matrix);
	return 0;
}

