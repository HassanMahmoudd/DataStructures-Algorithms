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

int knapsack(int i, int w, vector<int> weights, vector<int> benefits, vector<vector<int>> mem)
{
	if (mem[i][w] != -1)
		return mem[i][w];
	if (i == weights.size() || w == 0)
		return 0;
	if (weights[i] > w)
		return mem[i][w] = knapsack(i + 1, w, weights, benefits, mem);
	int x = knapsack(i + 1, w, weights, benefits, mem);
	int y = (knapsack(i + 1, w - weights[i], weights, benefits, mem)) + benefits[i];
	return mem[i][w] = max(x, y);
}

int main() {
	vector<int> weights;
	weights.push_back(2);
	weights.push_back(2);
	weights.push_back(4);
	weights.push_back(5);
	vector<int> benefits;
	benefits.push_back(3);
	benefits.push_back(7);
	benefits.push_back(2);
	benefits.push_back(9);
	vector<vector<int>> mem(5, vector<int>(11, -1));
	cout << knapsack(0, 10, weights, benefits, mem) << endl;
	return 0;
}

