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

int peakElement(vector<int> matrix)
{
	int start = 0;
	int n = matrix.size();
	int end = n - 1;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if ((mid == 0 || matrix[mid - 1] <= matrix[mid]) && (mid == n - 1 || matrix[mid + 1] <= matrix[mid]))
		{
			return matrix[mid];
		}
		else if (mid > 0 && matrix[mid - 1] > matrix[mid])
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
	return NULL;
}

int main() {
	vector<int> matrix;
	matrix.push_back(5);
	matrix.push_back(10);
	matrix.push_back(15);
	matrix.push_back(25);
	matrix.push_back(30);
	matrix.push_back(45);
	matrix.push_back(65);
	matrix.push_back(50);
	matrix.push_back(35);
	matrix.push_back(1);
	cout << peakElement(matrix) << endl;

	return 0;
}

