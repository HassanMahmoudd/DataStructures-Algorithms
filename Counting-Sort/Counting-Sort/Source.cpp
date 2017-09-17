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

bool correctlyPlaced(int index, int value)
{
	if (value == index + 1)
		return true;
	return false;
}

void countingSort(vector<int> matrix)
{
	int maxElement = *max_element(matrix.begin(), matrix.end());
	int minElement = *min_element(matrix.begin(), matrix.end());
	vector<int> count(maxElement + 1, 0);
	for (int i = 0; i < matrix.size(); i++)
	{
		count[matrix[i]]++;
	}
	for (int i = 1; i < maxElement + 1; i++)
	{
		count[i] += count[i - 1];
	}
	vector<int> output(matrix.size());
	for (int i = 0; i < matrix.size(); i++)
	{
		output[count[matrix[i]] - 1] = matrix[i];
		count[matrix[i]]--;
	}
	for (int i = 0; i < output.size(); i++)
	{
		cout << output[i] << " ";
	}
	cout << endl;

}

int main() {
	vector<int> matrix;
	matrix.push_back(9);
	matrix.push_back(4);
	matrix.push_back(10);
	matrix.push_back(8);
	matrix.push_back(2);
	matrix.push_back(4);
	countingSort(matrix);

	return 0;
}

