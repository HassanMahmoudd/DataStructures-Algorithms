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

void leaderElements(vector<int> matrix)
{
	if (matrix.size() == 0)
		return;
	int n = matrix.size();
	int currentLeader = matrix[n - 1];
	cout << "Leaders are: ";
	cout << currentLeader;
	for (int i = n - 2; i >= 0; i--)
	{
		if (matrix[i] > currentLeader)
		{
			currentLeader = matrix[i];
			cout << " " << currentLeader;
		}
	}
	cout << endl;
}

int main() {
	vector<int> matrix;
	matrix.push_back(98);
	matrix.push_back(23);
	matrix.push_back(54);
	matrix.push_back(12);
	matrix.push_back(20);
	matrix.push_back(7);
	matrix.push_back(27);
	leaderElements(matrix);

	return 0;
}

