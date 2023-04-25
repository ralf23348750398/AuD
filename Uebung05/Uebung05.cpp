#include <iostream>

int main()
{
    int n = 5, count = 0;
    for (int i = n-1; i > 0; i--) {
        n *= i;
        count++;
    }
    std::cout << "Calculated result: " << n << ", counter: " << count << std::endl;
}
