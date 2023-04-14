#include <iostream>

using namespace std;

void recursive_collatz(int number) {
	cout << number << " ";
	
	if (number % 2 == 0) {
		number/=2;
		recursive_collatz(number);
	}
	else if (number != 1) {
		number = number * 3 + 1;
		recursive_collatz(number);
	}
}

void iterative_collatz(int number) {
	while (number != 1) {
		cout << number << " ";
		if (number % 2 == 0) {
			number /= 2;
		}
		else {
			number = number * 3 + 1;
		}
	}
	cout << number << " ";
}

int main()
{
	int user_input = 0;

	cout << "Please provide a number for the Collatz calculation: " << endl;
	cin >> user_input;

	cout << endl << "Recursive solution:" << endl;
	recursive_collatz(user_input);
	cout << endl << "Iterative solution:" << endl;
	iterative_collatz(user_input);
	cout << endl;

	return 0;
}
