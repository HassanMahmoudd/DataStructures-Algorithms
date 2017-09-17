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

vector<string> LCS(string s1, string s2)
{
	int n = s1.size();
	int m = s2.size();
	int max = INT_MIN;
	vector<vector<int>> lcs(n, vector<int>(m));
	vector<string> result;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (s1[i] == s2[j])
			{
				if (i == 0 || j == 0)
					lcs[i][j] = 1;
				else
					lcs[i][j] = lcs[i - 1][j - 1] + 1;
				if (lcs[i][j] > max) {
					max = lcs[i][j];
					result.clear();
					result.push_back(s1.substr(i - max + 1, i + 1));
				}
				else if(lcs[i][j] == max)
					result.push_back(s1.substr(i - max + 1, i + 1));
			}
			else
			{
				lcs[i][j] = 0;
			}
		}
	}
	return result;
}

int main() {
	string s1 = "LCLC";
	string s2 = "CLCL";
	vector<string> result;
	result = LCS(s1, s2);
	for (string s : result) {
		cout << s << endl;
	}
	return 0;
}

