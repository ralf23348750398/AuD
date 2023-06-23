#include <iostream>

using namespace std;


unsigned int* create_array(unsigned int length) {
	unsigned int* a = new unsigned int[length];
	for (int i = 0; i < length; i++) {
		a[i] = (i / 3) + (i % 3) * 10;
	}
	return a;
}

template <class T>
void printArray(T* a, int size) {
	cout << "------------------------------------------------------" << endl;
	cout << "[";
	for (int i = 0; i < size; i++) {
		cout << a[i];
		if (i < size - 1) cout << ", ";
	}
	cout << "]" << endl;
}

template <class T>
int merge(int l, int m, int r, T* a) {
	int i = l, j = m + 1, k = 0, comp = 0;
	T* b = new T[r - l + 1];
	while (i <= m && j <= r) {
		comp++;
		if (a[i] <= a[j]) {
			b[k] = a[i++];
		}
		else {
			b[k] = a[j++];
		}
		k++;
	}
	comp++;
	if (i > m) {
		for (; j <= r; j++) {
			b[k++] = a[j];
		}
	}
	else {
		for (; i <= m; i++) {
			b[k++] = a[i];
		}
	}
	k = 0;
	for (i = l; i <= r; i++) {
		a[i] = b[k++];
	}
	delete[] b;
	return comp;
}

template <class T>
int mergesort(int l, int r, T* a) {
	int m, comp = 0;
	if (r > l) {
		m = (l + r) / 2;
		mergesort(l, m, a);
		mergesort(m + 1, r, a);
		comp += merge(l, m, r, a);
	}
	return comp;
}

int main() {
	int l = 0, r = 7, comparisons = 0;
	//unsigned int* a = create_array(r + 1);
	int a[] = {1,4,5,7,2,3,8,9};

	printArray(a, r + 1);
	comparisons = mergesort(l, r, a);
	printArray(a, r + 1);
	cout << endl << "Comparisons: " << comparisons << endl;

	return 0;
}