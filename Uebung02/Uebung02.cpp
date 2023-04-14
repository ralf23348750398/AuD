#include <iostream>
#include <string>

using namespace std;

int factorial_recursive(int n) {
	//Base case:
	if (n == 1) {
		return 1;
	}
	//Inductive step:
	return n * factorial_recursive(n - 1);
}

int factorial_iterative(int n) {
	int rvalue = 1;
	//Iterative loop:
	while (n > 1) {
		rvalue *= n;
		n--;
	}
	//Return value:
	return rvalue;
}

int a04_recursive(int n) {
	//Base case:
	if (n <= 2) {
		return 1;
	}
	//Inductive step:
	return n * a04_recursive(n - 1) - a04_recursive(n - 2);
}

int a04_iterative(int n) {
	int h1 = 1, h2 = 1, rvalue = 1;
	//Iterative loop:
	if (n > 2) {
		for (int i = 3; i <= n; i++) {
			rvalue = i * h1 - h2;
			h2 = h1;
			h1 = rvalue;
		}
	}
	//Return value:
	return rvalue;
}

int a05_recursive(int n) {
	if (n <= 2) {
		return 1;
	}
	return n + a05_recursive(n - 2);
}

int a05_iterative(int n) {
	int h1 = 1, h2 = 1, rvalue = 1;
	if (n > 2) {
		for (int i = 3; i <= n; i++) {
			rvalue = i + h2;
			h2 = h1;
			h1 = rvalue;
		}
	}
	return rvalue;
}

void a06_hanoi(int n, string start, string cache, string end, int* count) {
	if (n == 1) {
		cout << "Move disk from " << start << " to " << end << endl;
		*count += 1;
	}
	else {
		a06_hanoi(n - 1, start, end, cache, count);
		cout << "Move disk from " << start << " to " << end << endl;
		*count += 1;
		a06_hanoi(n - 1, cache, start, end, count);
	}
}

int a07_euclid(int a, int b) {
	int m = a, n = b, helper = 0, r = 0;
	do {
		if (m < n) {
			helper = m;
			m = n;
			n = helper;
		}
		r = m - n;
		m = n;
		n = r;
	} while (r != 0);
	return m;
}

int main()
{
	//Factorial calculation:
	//int fac = 0;
	//cout << "Welcome to factorial calculation! Please provide a number for the calculation: " << endl;
	//cin >> fac;
	//cout << "The recursive calculated result is: " << factorial_recursive(fac) << endl;
	//cout << "The iterative calculated result is: " << factorial_iterative(fac) << endl;

	//Exercice 4:
	/*int n04 = 0;

	cout << "Welcome to exercise 4! Please provide a number for the calculation: " << endl;
	cin >> n04;
	cout << "The recursive calculated result is: " << a04_recursive(n04) << endl;
	cout << "The iterative calculated result is: " << a04_iterative(n04) << endl;*/

	//Answer: 1:1, 2:1, 3:2, 4:7, 5:33

	//Exercise 5:
	/*int n05 = 0;

	cout << "Welcome to exercise 5! Please provide a number for the calculation: " << endl;
	cin >> n05;
	cout << "The recursive calculated result is: " << a05_recursive(n05) << endl;
	cout << "The iterative calculated result is: " << a05_iterative(n05) << endl;*/
	
	//Answer: 1:1, 2:1, 3:4, 4:5, 5:9

	//Exercise 6:
	/*int n06 = 0, count = 0;
	string start = "start";
	string cache = "cache";
	string end = "end";
	cout << "Welcome to exercise 6! Please provide the number of discs: " << endl;
	cin >> n06;
	a06_hanoi(n06, start, cache, end, &count);
	cout << endl << "Amount of necessary moves: " << count << endl;*/

	//Answer:	3:7, 4:15, 5:31
	//			Amount of necessary moves: 2^n - 1

	//Exercise 7:
	//int a = 0, b = 0;
	//cout << "Welcome to exercise 7! Please provide two numbers for the Euclidean algorithm separated by a space: " << endl;
	//cin >> a;
	//cin >> b;
	//cout << "The greatest common divisor is " << a07_euclid(a, b);
}