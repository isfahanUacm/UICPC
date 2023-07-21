#include <stdio.h>
#include <stdbool.h>
bool is_prime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i <= (int)(n / 2); i++) {
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
    int a, b, result;
    
    scanf("%d %d", &a, &b);
    
    result = a * b;
    
    if (is_prime(a) && is_prime(b) && a != b) {
        printf("full credit\n");
    } else if (!full_square(result) && !is_prime(a) && !is_prime(b)) {
        printf("partial credit\n");
    } else {
        printf("no credit\n");
    }
    
    return 0;
}