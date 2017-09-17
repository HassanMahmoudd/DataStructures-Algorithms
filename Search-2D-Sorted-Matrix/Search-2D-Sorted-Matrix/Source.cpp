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

bool searchElement(vector<vector<int>> matrix, int n)
{
	if (n < matrix[0][0] || n > matrix[3][3])
		return false;
	int row = 0;
	int col = 3;
	while (row <= 3 && col >= 0)
	{
		if (n > matrix[row][col])
			row++;
		else if (n < matrix[row][col])
			col--;
		else
			return true;
	}
	return false;
}

int main() {
	vector<vector<int>> matrix(4, vector<int>(4));
	matrix[0][0] = 2;
	matrix[0][1] = 6;
	matrix[0][2] = 7;
	matrix[0][3] = 11;
	matrix[1][0] = 3;
	matrix[1][1] = 8;
	matrix[1][2] = 10;
	matrix[1][3] = 12;
	matrix[2][0] = 4;
	matrix[2][1] = 9;
	matrix[2][2] = 11;
	matrix[2][3] = 13;
	matrix[3][0] = 5;
	matrix[3][1] = 15;
	matrix[3][2] = 16;
	matrix[3][3] = 18;
	
	cout << searchElement(matrix, 9) << endl;

	return 0;
}

