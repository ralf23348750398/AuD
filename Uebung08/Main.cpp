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

void insertion_sort(unsigned int* arr, int length, unsigned int* comparisons) {
	for (int i = 1; i < length; i++) {
		int cache = arr[i];
		int j = i;

		while (cache < arr[j - 1] && j > 0) {
			arr[j] = arr[j - 1];
			j--;
			*comparisons += 1;
		}

		arr[j] = cache;

		printArray(arr, length);
	}
}

void insertion_sort(unsigned int* arr1, int length) {
	unsigned int count = 0;
	cout << "Unsorted array:" << endl;
	printArray(arr1, length);

	cout << endl << "Single steps inside the for loop: " << endl;
	insertion_sort(arr1, length, &count);

	cout << endl << "Sorted array:" << endl;
	printArray(arr1, length);

	cout << endl << "Number of comparisons: " << count << endl;
}

void selection_sort(unsigned int* arr, int length, unsigned int* comparisons) {
	unsigned int min = 0, cache = 0;
	for (int i = 0; i < length-1; i++) {
		min = i;
		for (int j = i+1; j < length; j++) {
			arr[j] < arr[min] ? min = j : 0;
			*comparisons += 1;
		}
		cache = arr[min];
		arr[min] = arr[i];
		arr[i] = cache;

		printArray(arr, length);
	}
}

void selection_sort(unsigned int* arr1, int length) {
	unsigned int count = 0;

	cout << "Unsorted array:" << endl;
	printArray(arr1, length);

	cout << endl << "Single steps inside the for loop: " << endl;
	selection_sort(arr1, length, &count);

	cout << endl << "Sorted array:" << endl;
	printArray(arr1, length);

	cout << endl << "Number of comparisons: " << count << endl;
}

void bubblesort(unsigned int* arr, int length, unsigned int* comparisons) {
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
			*comparisons += 1;
		}
		printArray(arr, length);
	}
}

void bubblesort(unsigned int* arr1, int length) {
	unsigned int count = 0;

	cout << "Unsorted array:" << endl;
	printArray(arr1, length);

	cout << endl << "Single steps inside the for loop: " << endl;
	bubblesort(arr1, length, &count);

	cout << endl << "Sorted array:" << endl;
	printArray(arr1, length);

	cout << endl << "Number of comparisons: " << count << endl;
}


int main() {
	srand(static_cast<unsigned int>(time(nullptr)));

	int length = 9;
	unsigned int* arr1 = getRandomIntArrayOfSize(length);
	unsigned int arr2[] = {0,10,20,1,11,21,2,12,22};

	/*cout << "Insertion sort:" << endl;
	insertion_sort(arr2, length);*/
	//9 comparisons
	/*cout << endl << "Selection sort:" << endl;
	selection_sort(arr2, length);*/
	//36 comparisons
	cout << endl << "Bubblesort / Exchange sort:" << endl;
	bubblesort(arr2, length);
	//36 comparisons

	delete[] arr1;

	return 0;
}