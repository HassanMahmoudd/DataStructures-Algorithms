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

string toExcelString(int number)
{
	string ans = "";
	ans += (char)('A' + number % 26);
	number = number / 26;
	while (number > 0)
	{
		ans = (char)('A' + (number - 1) % 26) + ans;
		number = (number - 1) / 26;
	}
	return ans;
}

int toExcelNumber(string s)
{
	double sum = 0;
	int index = 0;
	for (int i = s.size() - 1; i >= 0; i--)
	{
		sum += (s[i] - 'A')*pow(26, index) + pow(26, i);
		index++;
	}
	return sum - 1;
}

int main() {
	int number = 700;
	cout << toExcelString(number) << endl;
	string s = "ABC";
	cout << toExcelNumber(s) << endl;
	return 0;
}

