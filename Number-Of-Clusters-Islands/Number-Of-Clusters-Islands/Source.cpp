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

vector<int> offsets = { -1, 0, 1 };

bool checkAvaialble(vector<vector<int>> matrix, int i, int j)
{
	if ((i >= 0 && i < matrix.size()) && (j >= 0 && j < matrix[0].size()))
	{
		if (matrix[i][j] == 1)
			return true;
	}
	return false;
}

void doDFS(vector<vector<int>> matrix, int i, int j, vector<vector<bool>>& visited)
{
	if (visited[i][j])
		return;
	visited[i][j] = true;
	int xOffset, yOffset;
	for (int l = 0; l < offsets.size(); l++)
	{
		xOffset = offsets[l];
		for (int m = 0; m < offsets.size(); m++)
		{
			yOffset = offsets[m];
			if (xOffset == 0 && yOffset == 0)
				continue;
			if (checkAvaialble(matrix, i + xOffset, j + yOffset))
			{
				doDFS(matrix, i + xOffset, j + yOffset, visited);
			}
		}
	}
}

int getNumberOfClusters(vector<vector<int>> matrix)
{
	vector<vector<bool>> visited(3, vector<bool>(5, false));
	int count = 0;
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[0].size(); j++)
		{
			if (matrix[i][j] == 1 && visited[i][j] == false)
			{
				count++;
				doDFS(matrix, i, j, visited);
			}
		}
	}
	return count;
}

int main() {
	vector<vector<int>> matrix(3, vector<int>(5));
	matrix = {
				{1, 0, 1, 0, 1},
		        {1, 1, 0, 0, 0},
		        {0, 1, 0, 1, 1},
		 };
	cout << getNumberOfClusters(matrix) << endl;

	return 0;
}

