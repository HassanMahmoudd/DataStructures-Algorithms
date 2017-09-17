#include <iostream>
#include <string>
#include <vector>

using namespace std;

void findFriends(vector<vector<char>>&, vector<bool>&, int);

int main() {
	vector<vector<char>> friends;
	int n;
	cin >> n;
	char temp;
	for (int i = 0; i < n; i++) {
		friends.push_back(vector<char>());
		for (int j = 0; j < n; j++)
		{
			cin >> temp;
			(friends[i]).push_back(temp);
		}
	}
	int noOfCircles = 0;
	vector<bool> visited;
	for (int i = 0; i < n; i++)
	{
		visited.push_back(false);
	}
	for (int i = 0; i < n; i++)
	{
		if (!visited.at(i)) {
			noOfCircles++;
			visited[i] = true;
			findFriends(friends, visited, i);
		}
	}
	cout << noOfCircles << endl;
}

void findFriends(vector<vector<char>>& friends, vector<bool>& visited, int id) {
	for (int i = 0; i < friends.size(); i++)
	{
		if ((friends[id][i]) == 'Y' && !visited[i] && i != id) {
			visited[i] = true;
			findFriends(friends, visited, i);
		}
	}
}