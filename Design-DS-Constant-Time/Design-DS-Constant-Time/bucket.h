#ifndef INCLUDE_OBJECT_HPP
#define INCLUDE_OBJECT_HPP

template <typename T> 
class bucket {
private:
	int size;
	std::vector<T> v;
	std::unordered_map<T, int> m;
public:
	bucket();

	void insert(T data);

	void remove(T data);

	bool search(T data);

	T random();

	void print();
};

#include "bucket.cpp"
#endif
