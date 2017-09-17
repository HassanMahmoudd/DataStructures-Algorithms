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

int min(int i, int j, int k) {
	
	return i <= j && i <= k ? i : (j <= i && j <= k ? j : k);
	
}

int maxSizeSquare(vector<vector<int>> matrix)
{
	int maxSize = 0;
	int rows = matrix.size();
	int cols = matrix[0].size();
	vector<vector<int>> table(7, vector<int>(6));
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (i == 0 || j == 0)
			{
				table[i][j] = matrix[i][j];
				if (table[i][j] > maxSize)
					maxSize = table[i][j];
			}
			else if (matrix[i][j] == 0)
				table[i][j] = 0;
			else
			{
				table[i][j] = min(table[i - 1][j - 1], table[i - 1][j], table[i][j - 1]) + 1;
				if (table[i][j] > maxSize)
					maxSize = table[i][j];
			}
		}
	}
	return maxSize;
}


int main() {
	vector<vector<int>> matrix(7, vector<int>(6));
	matrix = {
		{ 1, 1, 0, 0, 1, 1 },
		{ 0, 0, 1, 0, 1, 1 },
		{ 1, 1, 1, 1, 1, 0 },
		{ 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1 },
		{ 0, 1, 1, 1, 1, 1 },
		{ 1, 0, 0, 0, 1, 1 }
	};
	cout << maxSizeSquare(matrix) << endl;
	return 0;
}

