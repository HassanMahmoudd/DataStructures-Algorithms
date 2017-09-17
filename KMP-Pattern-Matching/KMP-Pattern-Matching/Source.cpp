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


void findPattern(string text, string pattern, vector<int> prefixSuffixArray)
{
	int N = text.size();
	int M = pattern.size();
	int j = 0;
	int i = 0;
	while (i < N)
	{
		if ((j != M && i != N) && text[i] == pattern[j])
		{
			i++;
			j++;
		}
		if (j == M)
		{
			cout << "Pattern found at index " << i - j << endl;
			j = prefixSuffixArray[j - 1];
		}
		else if (i < N && text[i] != pattern[j])
		{
			if (j != 0)
				j = prefixSuffixArray[j - 1];
			else
				i = i + 1;
		}
	}
}

vector<int> makePrefixSuffix(string s)
{

	vector<int> p(s.size(), 0);
	for (int i = 1; i < s.size(); i++)
	{
		int j = p[i - 1];

		while (j > 0 && s[i] != s[j])
			j = p[j - 1];

		if (s[i] == s[j])
			p[i] = j + 1;
	}

	return p;

}

int main() {
	string text = "ABABDABACDABABCABAB";
	string pattern = "ABABCABAB";
	vector<int> prefixSuffixArray = makePrefixSuffix(pattern);
	findPattern(text, pattern, prefixSuffixArray);
	
	return 0;
}

