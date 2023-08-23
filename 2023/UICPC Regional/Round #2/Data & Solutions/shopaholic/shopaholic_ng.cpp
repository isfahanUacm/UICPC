#include <algorithm>
#include <cstdio>

using namespace std;

int MAX_n = 20000;

int main() {
    int s; scanf("%d", &s);
    while (s--) {
        int n; scanf("%d", &n);
        int P[MAX_n];
        for (int i = 0; i < n; i++) 
            scanf("%d", &P[i]);
        int d = 0;
        sort(P, P + n);
        for (int i = n - 3; i >= 0; i -= 3) 
            d += P[i];
        printf("%d\n", d);
    }
}
