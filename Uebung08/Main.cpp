#include <algorithm>
#include <iostream>

using namespace std;

unsigned int* getRandomIntArrayOfSize(int size) {
	unsigned int* a = new unsigned int[size];
	for (int i = 0; i < size; i++) {
		a[i] = rand() & 0b1111;
	}
	return a;
}

void printArray(unsigned int* a, int size) {
	cout << "------------------------------------------------------" << endl;
	cout << "[";
	for (int i = 0; i < size; i++) {
		cout << a[i];
		if (i < size - 1) cout << ", ";
	}
	cout << "]" << endl;
}

void insertion_sort(unsigned int* arr, unsigned int length, unsigned int* comparisons) {
	for (int i = 1; i < length; i++) {
		int cache = arr[i];
		int j = i;

		while (arr[j] < arr[j - 1] && j > 0) {
			arr[j] = arr[j - 1];
			j--;
			*comparisons += 1;
		}

		arr[j] = cache;

		printArray(arr, length);
	}
}

void insertion_sort() {
	int length = 10;
	unsigned int count = 0;
	unsigned int* arr1 = getRandomIntArrayOfSize(length);

	cout << "Unsorted array:" << endl;
	printArray(arr1, length);

	cout << endl << "Single steps inside the for loop: " << endl;
	insertion_sort(arr1, length, &count);

	cout << endl << "Sorted array:" << endl;
	printArray(arr1, length);

	cout << endl << "Number of comparisons: " << count << endl;
}

void selection_sort(unsigned int* arr, unsigned int length, unsigned int* comparisons) {

}

int main() {
	srand(static_cast<unsigned int>(time(nullptr)));

	insertion_sort();
	

	return 0;
}