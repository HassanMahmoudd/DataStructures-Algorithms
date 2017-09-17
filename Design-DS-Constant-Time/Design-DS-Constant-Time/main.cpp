#include <vector>
#include <unordered_map>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include "bucket.h"

using namespace std;

int main() {

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