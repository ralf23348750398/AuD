#include <iostream>
#include <string>

using namespace std;

double a08_recursive(double n) {
	if (n > 0) {
		return 1 / n + a08_recursive(n - 1);
	}
	return 0;
}

double a08_iterative(double n) {
	double result = 0;

	for (; n > 0; n--) {
		result += 1 / n;
	}

	return result;
}

double a09_recursive(int n) {
	if (n <= 100) {
		return 1 + n / (2. * n + 1) * a09_recursive(n + 1);
	}
	return 1 + n / (2. * n + 1);
}

int main()
{
	//Exercise 8:
	/*double n = 0;
	cout << "Welcome to exercise 8! Please provide n for the calculations of the harmonic row: " << endl;
	cin >> n;
	cout << "The recursive calculated result is: " << a08_recursive(n) << endl;
	cout << "The iterative calculated result is: " << a08_iterative(n) << endl;*/

	//Exercise 9:
	double pi = 2 * a09_recursive(1);
	cout.precision(10);
	cout << "The first few digits of pi: " << pi << endl;
}