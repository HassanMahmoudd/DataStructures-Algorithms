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
#include<unordered_set>
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

int encodings(char c)
{
	switch (c)
	{
	case 'A':
		return 0;
	case 'C':
		return 1;
	case 'G':
		return 2;
	case 'T':
		return 3;
	}

}

int minNumberOfCuts(string s)
{
	int n = s.size();
	vector<vector<bool>> palindrome(n, vector<bool>(n, false));

	for (int i = 0; i < n; i++)
	{
		palindrome[i][i] = true;
	}

	for (int i = 0; i < n - 1; i++)
	{
		if (s[i] == s[i + 1])
			palindrome[i][i + 1] = true;
	}

	for (int curr_len = 3; curr_len < n; curr_len++)
	{
		for (int i = 0; i < n - curr_len + 1; i++)
		{
			int j = i + curr_len - 1;
			if (s[i] == s[j] && palindrome[i + 1][j - 1])
				palindrome[i][j] = true;
		}
	}

	vector<int> cuts(n);
	
	for (int i = 0; i < n; i++)
	{
		int temp = INT_MAX;
		if (palindrome[0][i])
			cuts[i] = 0;
		else
		{
			for (int j = 0; j < i; j++)
			{
				if (palindrome[j + 1][i] && temp > cuts[j] + 1)
				{
					temp = cuts[j] + 1;
				}
			}
			cuts[i] = temp;
		}
	}

	return cuts[n - 1];
}

int main() {
	string text = "BANANA";
	cout << minNumberOfCuts(text) << endl;

	return 0;
}

