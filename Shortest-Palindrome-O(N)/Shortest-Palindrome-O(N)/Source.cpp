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

string makePalindrome(string s)
{
	string rev_s = s;
	reverse(rev_s.begin(), rev_s.end());
	string l = s + rev_s;
	vector<int> p(l.size(), 0);
	for (int i = 1; i < l.size(); i++)
	{
		int j = p[i - 1];

		while (j > 0 && l[i] != l[j])
			j = p[j - 1];

		if (l[i] == l[j])
			p[i] = j + 1;
	}

	return (rev_s.substr(0, s.size() - p[l.size() - 1]) + s);

}

int main() {
	string s = "acdfc";
	cout << makePalindrome(s) << endl;

	return 0;
}

