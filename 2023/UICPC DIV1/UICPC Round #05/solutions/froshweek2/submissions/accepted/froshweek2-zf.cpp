#include <iostream>
#include <algorithm>

#define MAXN 200000

using namespace std;

int main() {
    int n, m, tot = 0;
    int task[MAXN], quiet[MAXN];

    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> task[i];
    for (int i = 0; i < m; ++i) cin >> quiet[i];

    sort(task, task + n);
    sort(quiet, quiet + m);

    --n;
    --m;

    while (n >= 0 && m >= 0) {
        if (task[n] <= quiet[m]) {
            ++tot;
            --m;
        }
        --n;
    }

    cout << tot << endl;

    return 0;
}
