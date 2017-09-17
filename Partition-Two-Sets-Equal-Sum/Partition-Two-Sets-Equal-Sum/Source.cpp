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

bool checkCanBePartitionedDP(vector<int> matrix, int n, int currentSum, int totalSum, vector<vector<int>> mem)
{
	if (n == 0)
	{
		if ((totalSum - currentSum) == currentSum)
			return true;
		else
			return false;
	}
	if (mem[n - 1][currentSum + matrix[n]] == -1)
		mem[n - 1][currentSum + matrix[n]] = checkCanBePartitionedDP(matrix, n - 1, currentSum + matrix[n], totalSum, mem);
	
	bool resultIfCurrentItemIncluded = mem[n - 1][currentSum + matrix[n]];

	if (mem[n - 1][currentSum] == -1)
		mem[n - 1][currentSum] = checkCanBePartitionedDP(matrix, n - 1, currentSum, totalSum, mem);
	
	bool resultIfCurrentItemNotIncluded = mem[n - 1][currentSum];

	return resultIfCurrentItemIncluded || resultIfCurrentItemNotIncluded;
}

bool checkCanBePartitioned(vector<int> matrix, int n, int currentSum, int totalSum)
{
	if (n == 0)
	{
		if ((totalSum - currentSum) == currentSum)
			return true;
		else
			return false;
	}
	bool resultIfCurrentItemIncluded = checkCanBePartitioned(matrix, n - 1, currentSum + matrix[n], totalSum);
	bool resultIfCurrentItemNotIncluded = checkCanBePartitioned(matrix, n - 1, currentSum, totalSum);
	
	return resultIfCurrentItemIncluded || resultIfCurrentItemNotIncluded;
}


int main() {
	vector<int> matrix = { 1, 5, 11, 5};
	int totalSum = 0;
	int currentSum = 0;
	for (int i = 0; i < matrix.size(); i++)
	{
		totalSum += matrix[i];
	}
	int n = matrix.size() - 1;
	cout << checkCanBePartitioned(matrix, n, currentSum, totalSum) << endl;

	// Memoization
	vector<vector<int>> mem(n + 1, vector<int>(totalSum + 1, -1));
	cout << checkCanBePartitionedDP(matrix, n, currentSum, totalSum, mem) << endl;
	return 0;
}

