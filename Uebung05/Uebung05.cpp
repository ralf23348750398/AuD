#include <iostream>

int faculty_recursive(int n, int* count) {
    if (n > 1) {
        *count += 1;
        return n * faculty_recursive(n - 1, count);
    }
    return 1;
}

int faculty_iterative(int n, int* count) {
        for (int i = n - 1; i > 0; i--) {
        n *= i;
        *count += 1;
    }
    return n;
}

int main()
{
    int n = 5, count_iterative = 0, count_recursive = 0;

    std::cout << "Recursive calculated result: " << faculty_recursive(n, &count_recursive) << ", counter: " << count_recursive << std::endl;
    std::cout << "Iterative calculated result: " << faculty_iterative(n, &count_iterative) << ", counter: " << count_iterative <<  std::endl;
}
