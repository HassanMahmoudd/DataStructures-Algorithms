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

void LPS(string s1)
{
	int n = s1.size();
	int palindromBeginsAt = 0;
	int max_len = 0;
	vector<vector<bool>> lps(n, vector<bool>(n, false));
	for (int i = 0; i < n; i++)
	{
		lps[i][i] = true;
	}
	for (int i = 0; i < n - 1; i++)
	{
		if (s1[i] == s1[i + 1]) {
			lps[i][i + 1] = true;
			palindromBeginsAt = i;
			max_len = 2;
		}
	}
	for (int cur_len = 3; cur_len <= n; cur_len++)
	{
		for (int i = 0; i < n - cur_len + 1; i++)
		{
			int j = i + cur_len - 1;
			if (s1[i] == s1[j] && lps[i+1][j-1]) {
				lps[i][j] = true;
				palindromBeginsAt = i;
				max_len = cur_len;
			}
		}
	}
	string result = s1.substr(palindromBeginsAt, max_len);
	cout << result << endl;
}

int main() {
	string s1 = "BANANA";
	LPS(s1);
	return 0;
}

