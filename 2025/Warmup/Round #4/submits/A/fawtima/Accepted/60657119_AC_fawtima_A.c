#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        int count = 0;
        scanf("%d", &n);
        char str[n];
        scanf("%s", str);
        for (int i = n - 1; i >= 0; i--) {
            if (str[i] == '0') {
                str[i] = '1';
            } else if (str[i] == '1') {
                str[i] = '0';
            }
            for (int i = 0; i < n; i++) {
                if (str[i] == '1') {
                    count++;
                }
            }
            if (str[i] == '0') {
                str[i] = '1';
            } else if (str[i] == '1') {
                str[i] = '0';
            }
        }
        printf("%d\n",count);
    }
    return 0;
}