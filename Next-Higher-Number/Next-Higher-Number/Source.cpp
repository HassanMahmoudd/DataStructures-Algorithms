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

void nextHigherNumber(int number)
{
	vector<int> digits;
	int n = number;
	while (n > 0)
	{
		int digit = n % 10;
		n = n / 10;
		digits.push_back(digit);
	}
	int j = 0;
	int i = j + 1;
	if (digits.size() > 1)
	{
		while (i < digits.size() && digits[j] < digits[i])
		{
			j++;
			i++;
		}
		if (i >= digits.size())
		{
			cout << "None" << endl;
			return;
		}
		j = 0;
		while (digits[j] < digits[i])
		{
			j++;
		}
		int temp = digits[i];
		digits[i] = digits[j];
		digits[j] = temp;
	}
	else
	{
		cout << "None" << endl;
		return;
	}
	vector<int>::const_iterator first = digits.begin();
	vector<int>::const_iterator last = digits.begin() + i;
	vector<int> sublist(first, last);
	sort(sublist.begin(), sublist.end());

	int m = digits.size() - 1;
	while (m >= i)
	{
		cout << digits[m];
		m--;
	}
	m = 0;
	while (m < sublist.size())
	{
		cout << sublist[m];
		m++;
	}
	cout << endl;
}

int main() {
	
	nextHigherNumber(12543);
	nextHigherNumber(4132);
	nextHigherNumber(1234);
	nextHigherNumber(32841);
	nextHigherNumber(30102);
	nextHigherNumber(98765);

	return 0;
}

