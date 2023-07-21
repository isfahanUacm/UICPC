#include <iostream>
#include <cmath>

bool is_prime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

bool full_square(int result) {
    int i = 2;
    while ((i * i) < result) {
        i++;
        if (result % (i * i) == 0) {
            return true;
        }
        if ((i * i) > result) {
            return false;
        }
    }
}

int main() {
    int a, b;
    std::cin >> a >> b;
    int result = a * b;

    if (is_prime(a) && is_prime(b) && a != b) {
        std::cout << "full credit" << std::endl;
    }
    else if (!full_square(result) && !is_prime(a) && !is_prime(b)) {
        std::cout << "partial credit" << std::endl;
    }
    else {
        std::cout << "no credit" << std::endl;
    }

    return 0;
}