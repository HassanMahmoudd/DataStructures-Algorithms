#include <vector>
#include <unordered_map>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
class bucket {
	int size;
	vector<T> v;
	unordered_map<T, int> m;
public:

	bucket() {
		size = 0;
		//v = new vector<T>();
		//m = new unordered_map<T, int>();
	}

	void insert(T data);
	
	void remove(T data);

	bool search(T data);
	
	T random();
	
	void print();
	
};

template <typename T>
void bucket<T>::insert(T data)
{
	if (m.find(data) != m.end())
		return;
	v.push_back(data);
	m.emplace(data, size++);
}

template <typename T>
void bucket<T>::remove(T data)
{
	if (m.find(data) == m.end())
		return;
	int index = m[data];
	int n = v.size();
	swap(v[index], v[n - 1]);
	v.pop_back();
	m[v[index]] = index;
	size--;
}

template <typename T>
bool bucket<T>::search(T data)
{
	if (m.find(data) != m.end())
		return true;
	return false;
}

template <typename T>
T bucket<T>::random()
{
	int idx = rand() % size;
	return v[idx];
}

template <typename T>
void bucket<T>::print() {
	for (auto it = v.begin(); it != v.end(); it++) {
		std::cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	bucket<char>* b = new bucket<char>();
	b->insert('d');
	b->insert('k');
	b->insert('l');
	b->insert('h');
	b->insert('j');
	b->insert('z');
	b->insert('p');

	cout << b->random() << endl;
	b->print();
	b->remove('h');
	b->print();
	return 0;
}