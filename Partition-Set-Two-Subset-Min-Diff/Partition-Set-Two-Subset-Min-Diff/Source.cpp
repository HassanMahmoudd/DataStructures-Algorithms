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

int finMinDifferenceBetTwoSubsetsDP(vector<int> matrix, int n, int currentSum, int totalSum, vector<vector<int>> mem)
{
	if (n == 0)
	{
		return abs(currentSum - (totalSum - currentSum));
	}
	if (mem[n - 1][currentSum + matrix[n]] == -1)
		mem[n - 1][currentSum + matrix[n]] = finMinDifferenceBetTwoSubsetsDP(matrix, n - 1, currentSum + matrix[n], totalSum, mem);

	int resultIfCurrentItemIncluded = mem[n - 1][currentSum + matrix[n]];

	if (mem[n - 1][currentSum] == -1)
		mem[n - 1][currentSum] = finMinDifferenceBetTwoSubsetsDP(matrix, n - 1, currentSum, totalSum, mem);

	int resultIfCurrentItemNotIncluded = mem[n - 1][currentSum];

	return min(resultIfCurrentItemIncluded, resultIfCurrentItemNotIncluded);
}

int finMinDifferenceBetTwoSubsets(vector<int> matrix, int n, int currentSum, int totalSum)
{
	if (n == 0)
	{
		return abs(currentSum - (totalSum - currentSum));
	}
	int resultIfCurrentItemIncluded = finMinDifferenceBetTwoSubsets(matrix, n - 1, currentSum + matrix[n], totalSum);
	int resultIfCurrentItemNotIncluded = finMinDifferenceBetTwoSubsets(matrix, n - 1, currentSum, totalSum);

	return min(resultIfCurrentItemIncluded, resultIfCurrentItemNotIncluded);
}


int main() {
	vector<int> matrix = { 1, 3, 11, 5 };
	int totalSum = 0;
	int currentSum = 0;
	for (int i = 0; i < matrix.size(); i++)
	{
		totalSum += matrix[i];
	}
	int n = matrix.size() - 1;
	cout << finMinDifferenceBetTwoSubsets(matrix, n, currentSum, totalSum) << endl;

	// Memoization
	vector<vector<int>> mem(n + 1, vector<int>(totalSum + 1, -1));
	cout << finMinDifferenceBetTwoSubsetsDP(matrix, n, currentSum, totalSum, mem) << endl;

	string str_hex = "4013";
	int i_hex = std::stoi(str_hex);
	cout << i_hex << endl;

	char buf[33];
	int i = 127;
	itoa(i, buf, 16);
	string buffer(buf);
	cout << buf << endl;

	char tab2[1024];
	strcpy(tab2, buffer.c_str());
	return 0;
}

