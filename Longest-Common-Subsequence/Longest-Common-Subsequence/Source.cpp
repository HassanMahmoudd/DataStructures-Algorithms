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

void LCS(string s1, string s2)
{
	int n = s1.size();
	int m = s2.size();
	int pick_s1_s2 = 0;
	int pick_s1 = 1;
	int pick_s2 = 2;
	vector<vector<int>> lcs(n, vector<int>(m));
	vector<vector<int>> pointer(n, vector<int>(m));
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
				pointer[i][j] = pick_s1_s2;
			}
			else
			{
				if (i > 0 && j > 0) {
					if (lcs[i - 1][j] >= lcs[i][j - 1]) {
						lcs[i][j] = lcs[i - 1][j];
						pointer[i][j] = pick_s2;
					}
					else {
						lcs[i][j] = lcs[i][j - 1];
						pointer[i][j] = pick_s1;
					}
				}
				else if (i > 0 && j == 0) {
					lcs[i][j] = lcs[i - 1][j];
					pointer[i][j] = pick_s2;
				}
				else if (j > 0 && i == 0) {
					lcs[i][j] = lcs[i][j - 1];
					pointer[i][j] = pick_s1;
				}
				else {
					lcs[i][j] = 0;
					pointer[i][j] = pick_s1;
				}
			}
		}
	}
	int i = n - 1;
	int j = m - 1;
	string result = "";
	while (i >= 0 && j >= 0) {
		if (pointer[i][j] == pick_s1_s2) {
			result += s1[i];
			i--, j--;
		}
		else if (pointer[i][j] == pick_s1) {
			j--;
		}
		else
			i--;
	}
	reverse(result.begin(), result.end());
	cout << result << endl;
}

int main() {
	string s1 = "BDCBEA";
	string s2 = "ADCA";
	LCS(s1, s2);
	return 0;
}

