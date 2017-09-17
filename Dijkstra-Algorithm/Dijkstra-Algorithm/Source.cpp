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
#include<algorithm>
#include<numeric>
#include<utility>
#include<functional>
#include<stdio.h>
#include<assert.h>
#include<memory.h>
#include<bitset>
using namespace std;

#define all(v)              ((v).begin()), ((v).end())
#define sz(v)               ((int)((v).size()))
#define clr(v, d)           memset(v, d, sizeof(v))
#define rep(i, v)       for(int i=0;i<sz(v);++i)
#define lp(i, n)        for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)    for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)    for(int i=(j);i>=(int)(n);--i)

typedef long long         ll;
const ll OO = 1e8;

const double EPS = (1e-7);
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

#define pb                  push_back
#define MP                  make_pair
#define P(x)                cout<<#x<<" = { "<<x<<" }\n"
typedef long double       ld;
typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;

vector<int> dijkstra(vector<vector<pair<int, int>>> graph, int source)
{
	int size = graph.size();
	vector<int> dist(size, INT_MAX);
	vector<int> prev(size, -1);
	vector<bool> visited(size);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
	dist[source] = 0;
	Q.push(make_pair(0, source));
	while (!Q.empty())
	{
		pair<int, int> curr = Q.top();
		Q.pop();
		int currNode = curr.second;
		visited[currNode] = true;
		for (int i = 0; i < graph[currNode].size(); i++)
		{
			int neighborNode = graph[currNode][i].first;
			if (!visited[neighborNode])
			{
				int alt = dist[currNode] + graph[currNode][i].second;
				if (alt < dist[neighborNode])
				{
					dist[neighborNode] = alt;
					prev[neighborNode] = currNode;
					Q.push(make_pair(alt, neighborNode));
				}
			}
		}
	}
	return dist;
}


int main() {
	vector<vector<pair<int, int>>> adjList2; // weight relation (node, cost)
	int n;
	/*
	3
	2	 1 13    2 4
	1    2 9     3 -4
	2    0 -7    1 8
	*/
	cin >> n;
	adjList2 = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(n));
	lp(i, n) {
		int cnt;
		cin >> cnt;
		lp(j, cnt) {
			int to, cost;
			cin >> to >> cost;
			adjList2[i].push_back(make_pair(to, cost));
		}
	}

	vector<int> dist = dijkstra(adjList2, 0);
	for (int i = 0; i < dist.size(); i++)
	{
		cout << dist[i] << " ";
	}
	cout << endl;
	return 0;
}