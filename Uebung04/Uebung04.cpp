#include <iostream>
#include <time.h>

using namespace std;

long fibonacci_recursive(int n) {
    if (n <= 2) {
        return 1;
    }
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

long long fibonacci_iterative(long long n) {
    long long h1 = 1, h2 = 1, res = 1;
    if (n > 2) {
        for (int i = 3; i <= n; i++) {
            res += h2;
            h2 = h1;
            h1 = res;
        }
    }
    else {
        return res;
    }
    return res;
}

int fibonacci_array(int n) {
    static int known_fib[100];
    known_fib[1] = 1;
    known_fib[2] = 1;
    int res;
    if (known_fib[n] != 0) {
        res = known_fib[n];
    }
    else {
        res = fibonacci_array(n - 1) + fibonacci_array(n - 2);
        known_fib[n] = res;
    }
    return res;
}

class Vektor {
private:
    int dimension;
    int* daten;
public:
    Vektor(int dim);
    virtual ~Vektor();
    void set(int i, int val);
    int get(int i);
    int bin_suche(int sw);
};

int Vektor::bin_suche(int sw) {
    int l_u = 0, l_o = dimension - 1;
    while (l_u <= l_o) {
        if (daten[l_u + (l_o - l_u) / 2] > sw) {
            l_u = l_u + (l_o - l_u) / 2 + 1;
        }
        else if(daten[l_u + (l_o - l_u) / 2] < sw){
            l_o = l_u + (l_o - l_u) / 2 - 1;
        }
        else {
            return l_u + (l_o - l_u) / 2;
        }
    }
    return l_u;
}

Vektor::Vektor(int dim) {
    dimension = dim;
}

Vektor::~Vektor() {

}

void Vektor::set(int i, int val){
    this->daten[i] = val;
}

int Vektor::get(int i) {
    return daten[i];
}

int e_15_recursive(int n) {
    if (n == 1) {
        return 1;
    }
    if (n > 1) {
        return n * e_15_recursive(n - 1) + 1;
    }
    else {
        return n;
    }
}

int e_15_iterative(int n) {
    int res = 1, h1 = 1;
    if (n > 1) {
        for (int i = 2; i <= n; i++) {
            res = i * h1 + 1;
            h1 = res;
        }
    }
    return res;
}

int main()
{
    //Exercise 13
    /*int n = 5;
    time_t start, end;

    start = time(NULL);
    cout << "1) Recursive calculated fibonacci of " << n << ": " << fibonacci_recursive(n) << endl;
    end = time(NULL);
    cout << "With a time of " << end - start << " seconds." << endl;

    start = time(NULL);
    cout << "2) Iterative calculated fibonacci of " << n << ": " << fibonacci_iterative(n) << endl;
    end = time(NULL);
    cout << "With a time of " << end - start << " seconds." << endl;
    cout << "3) Recursive dynamic calculated fibonacci of " << n << ": " << fibonacci_array(n) << endl;*/

    //Exercise 14
    /*Vektor v1(5);
    v1.set(0, 5);
    v1.set(1, 3);
    v1.set(2, 1);
    v1.set(3, 8);
    v1.set(4, 4);

    cout << "The number you searched for (5) is at position " << v1.bin_suche(5) << endl;*/

    //Exercise 15
    cout << "Recursive result: " << e_15_recursive(10) << endl;
    cout << "Iterative result: " << e_15_iterative(10) << endl;
}