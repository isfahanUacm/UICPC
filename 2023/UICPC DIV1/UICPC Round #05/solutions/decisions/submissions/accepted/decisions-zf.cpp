#include <iostream>

#define MAXN 20

using namespace std;

int vals[1<<MAXN], cnt, n;

int f(int x, int at) {
    if (at == n) return (1<<vals[x]);
    int left = f(x, at+1), right = f(x|(1<<at), at+1);
    if ((left|right) == 3) ++cnt;
    return left|right;
}

int main() {
    cin >> n;
    for (int i = 0; i < (1<<n); ++i) cin >> vals[i];
    f(0, 0);
    cout << 2*cnt+1 << endl;

    return 0;
}
