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

int indexMaxAvgSum(vector<int> matrix, int k)
{
	int n = matrix.size();
	if (k > n)
		return -1;
	if (k == n)
		return 0;
	int sum = 0;
	for (int i = 0; i < k; i++)
	{
		sum += matrix[i];
	}
	int maxSum = sum;
	int indexMaxSum = 0;
	for (int i = k; i < n; i++)
	{
		sum = sum - matrix[i - k] + matrix[i];
		if (sum > maxSum)
		{
			maxSum = sum;
			indexMaxSum = i - k + 1;
		}
	}
	return indexMaxSum;
}

int maxAvgSum(vector<int> matrix, int k)
{
	int index = indexMaxAvgSum(matrix, k);
	if (index == -1)
		return -1;
	int avg = 0;
	for (int i = 0; i < k; i++)
		avg += matrix[index++];
	return avg;
}

int main() {
	vector<int> matrix;
	matrix.push_back(11);
	matrix.push_back(-8);
	matrix.push_back(16);
	matrix.push_back(-7);
	matrix.push_back(24);
	matrix.push_back(-2);
	matrix.push_back(3);
	int k = 3;
	cout << maxAvgSum(matrix, k) << endl;

	return 0;
}

