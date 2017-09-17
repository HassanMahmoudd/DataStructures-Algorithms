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

void printMatrixDiagonally(vector<vector<int>> matrix)
{
	int row, col;
	int rowCount = 4;
	int colCount = 5;
	for (int k = 0; k < rowCount; k++)
	{
		for (row = k, col = 0; row >= 0 && col < colCount; row--, col++)
		{
			cout << matrix[row][col] << " ";
		}
		cout << endl;
	}
	for (int k = 1; k < colCount; k++)
	{
		for (col = k, row = rowCount - 1; row >= 0 && col < colCount; row--, col++)
		{
			cout << matrix[row][col] << " ";
		}
		cout << endl;
	}
}

int main() {
	int row = 4, col = 5;
	vector<vector<int>> matrix(4, vector<int>(5));
	int k = 1;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			matrix[i][j] = k++;
		}
	}
	stringstream result;
	
	for (int i = 0; i < row; i++)
	{
		copy(matrix[i].begin(), matrix[i].end(), ostream_iterator<int>(result, " "));
		cout << result.str() << endl;
		result.str("");
	}
	cout << "Print Matrix Diagonally" << endl;
	printMatrixDiagonally(matrix);
	return 0;
}

