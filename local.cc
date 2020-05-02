#include <bits/stdc++.h>
using namespace std;

struct heap {
	int size;
	int capacity;
	int *harr;
	heap(int c) {
		size = 0;
		capacity = c;
		harr = new int[c];
	}
	void increaseCapacity();
};

void heap::increaseCapacity() {
	capacity++;
}

int main() {
	heap *h = new heap(5);
	cout << "size: " << h->size << endl;
	h->increaseCapacity();
	cout << "capacity: " << h->capacity << endl;
}
