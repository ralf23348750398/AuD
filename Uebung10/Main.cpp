#include <algorithm>
#include <iostream>
#include <random>
#include <chrono>


using namespace std;

unsigned int* create_array(unsigned int length) {
	unsigned int* a = new unsigned int[length];
	for (int i = 0; i < length; i++) {
		a[i] = (i / 3) + (i % 3) * 10;
	}
	return a;
}

unsigned int* create_array_a(unsigned int length) {
	unsigned int* a = new unsigned int[length];
	unsigned int value = 2;

	for (int i = 0; i < length; i++) {
		if (i == 0) {
			a[i] = value;
		}
		else if (i % 2 == 0 && i>0) {
			value += 3;
			a[i] = value;
		}
		else {
			a[i] = --value;
		}
	}
	return a;
}

unsigned int* create_array_b(unsigned int length) {
	unsigned int* a = new unsigned int[length];
	unsigned int value = 6;
	int j = 0;

	for (int i = 0; i < length; i++) {
		while (i < length && j < 5) {
			a[i] = --value;
			j++;
			i++;
		}
		i--;
		j = 0;
		value += 10;
	}
	return a;
}

unsigned int* create_array_c(unsigned int length) {
	unsigned int* a = new unsigned int[length];
	unsigned int k = 7;
	unsigned int value = k;
	int h = 0;
	int j = 1;

	for (int i = 0; i < length; i++) {
		while (value > (j-1)*k+1 && i<length) {
			value = j * k - h;
			a[i] = value;
			i++;
			h++;
		}
		i--;
		j++;
		h = 0;
		value = j * k;
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

void Mean_a(int l, int r, unsigned int* a){
	int m = (l + r) / 2; // zunächst einfach(fast) mittleres Element
	swap(a[m], a[r]);// setze Pivotelement an das Tabellenende
}

void Mean_b(int l, int r, unsigned int* a) {
	random_device r1;	//RNG using underlying sources such as hardware-events to generate a number r1 
	mt19937 gen(r1());	//RNG with a period of 2^19937 - 1 creating a random number between 0 and 2^32 -1 based on r1
	uniform_int_distribution<> dis(l, r);	//used to convert the random number created by mt19937 to a number in the desired range
	int m = dis(gen);
	swap(a[m], a[r]);// setze Pivotelement an das Tabellenende
}

void Mean_c(int l, int r, unsigned int* a) {
	if (a[(l + r) / 2] < a[l] < a[r]) {
		swap(a[l], a[(l + r) / 2]);
	}
	else if (a[r] < a[(l + r) / 2] < a[l]) {
		swap(a[r], a[l]);
	}
	else if (a[r] < a[l] < a[(l + r) / 2]) {
		swap(a[l], a[(l + r) / 2]);
		swap(a[r], a[l]);
	}
	swap(a[(l + r) / 2], a[r]);// setze Pivotelement an das Tabellenende
}

int Partition(int l, int r, unsigned int* a, unsigned int* comparisons)
{
	int i = l - 1, j = r;
	Mean_c(l, r, a);
	while (i < j)
	{
		while (a[++i] <= a[r]) {
			if (i == r) break;
			(*comparisons)++;
		}
		while (a[--j] > a[r]) {
			if (j == l) break;
			(*comparisons)++;
		}
		if (i < j) {
			swap(a[i], a[j]);
		}
	};
	swap(a[r], a[i]);
	return i;
}

void QuicksortTable(int l, int r, unsigned int* a, unsigned int* comparisons)
{
	int m;
	m = Partition(l, r, a, comparisons);
	if (l < m - 1) QuicksortTable(l, m - 1, a, comparisons);
	if (m + 1 < r) QuicksortTable(m + 1, r, a, comparisons);
}

void insertion_sort(unsigned int* arr, int length, unsigned int* comparisons) {
	for (int i = 1; i < length; i++) {
		int cache = arr[i];
		int j = i;

		while (cache < arr[j - 1] && j > 0) {
			arr[j] = arr[j - 1];
			j--;
			if (j != i) {
				(*comparisons)++;
			}
		}

		arr[j] = cache;
		(*comparisons)++;
	}
}

int main() {
	int length = 1000;
	unsigned int* arr1 = create_array_c(length);
	unsigned int* arr2 = create_array_c(length);
	unsigned int comparisons_quicksort = 0;
	unsigned int comparisons_insertionsort = 0;

	// Start the clock
	auto start = chrono::high_resolution_clock::now();

	cout << "Quicksort: " << endl;
	//printArray(arr1, length);
	QuicksortTable(0, length, arr1, &comparisons_quicksort);
	//printArray(arr1, length);
	cout << endl << "Comparisons: " << comparisons_quicksort << endl;

	// Stop the clock
	auto end = chrono::high_resolution_clock::now();

	// Calculate the elapsed time
	chrono::duration<double> elapsed = end - start;

	// Print the elapsed time
	cout << "Quicksort took " << elapsed.count() << " seconds" << endl;

	// Reset the clock
	start = chrono::high_resolution_clock::now();

	cout << endl << "Insertionsort: " << endl;
	//printArray(arr2, length);
	insertion_sort(arr2, length, &comparisons_insertionsort);
	//printArray(arr2, length);
	cout << endl << "Comparisons: " << comparisons_insertionsort << endl;

	// Stop the clock
	end = chrono::high_resolution_clock::now();

	// Calculate the elapsed time
	elapsed = end - start;

	// Print the elapsed time
	cout << "Insertionsort took " << elapsed.count() << " seconds" << endl;

	


	delete[] arr1;
	delete[] arr2;
	return 0;
}
