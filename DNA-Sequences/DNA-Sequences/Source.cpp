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

void findDNASequence(string s)
{
	unordered_set<string> result;
	unordered_set<int> hashes;
	int rhashes = 0;
	for (int i = 0; i < 10; i++)
	{
		rhashes += pow(2, 10 - i) * encodings(s[i]);
	}
	hashes.insert(rhashes);
	for (int i = 10; i < s.size(); i++)
	{
		rhashes -= pow(2,10) * encodings(s[i - 10]);

		rhashes = 2 * rhashes + pow(2, 1) * encodings(s[i]);
		
		
		if (hashes.find(rhashes) != hashes.end())
		{
			result.insert(s.substr(i - 9, i - (i - 9) + 1));
		}
		else 
		{
			hashes.insert(rhashes);

		}
		
	}
	for (auto itr = result.begin(); itr != result.end(); ++itr) {
		cout << *itr << endl;
	}

}

int main() {
	string text = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	findDNASequence(text);

	return 0;
}

