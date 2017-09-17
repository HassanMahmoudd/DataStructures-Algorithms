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

void checkPairHashMap(vector<int> matrix, int sum)
{
	unordered_map<int, int> HashMap;
	for (int i = 0; i < matrix.size(); i++)
	{
		if (HashMap.find(sum - matrix[i]) != HashMap.end())
		{
			cout << "Pair is " << matrix[i] << ", " << sum - matrix[i] << endl;
			return;
		}
		HashMap.emplace(matrix[i], 0);
	}

}

void checkPairSorting(vector<int> matrix, int sum)
{
	sort(matrix.begin(), matrix.end());
	int l = 0;
	int r = matrix.size() - 1;
	while (l < r)
	{
		if (matrix[l] + matrix[r] > sum)
			r--;
		else if(matrix[l] + matrix[r] < sum)
			l++;
		else
		{
			cout << "Pair is " << matrix[l] << ", " << matrix[r] << endl;
			return;
		}
	}
	cout << "Pair is not found " << endl;
}


int main() {
	vector<int> matrix = { 1, 4, 45, 6, 10, 8 };
	int k = 16;
	checkPairSorting(matrix, k);
	checkPairHashMap(matrix, k);
	return 0;
}

