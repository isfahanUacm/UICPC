#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    scanf("%d", &n);
    vector<int> outdeg(n), idx(n);
    for (int i = 1; i < n; ++i) {
        char w[n];
        scanf("%s", w);
        for (int j = 0; j < i; ++j)
            ++outdeg[w[j]=='1' ? i : j];
    }
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int a, int b) { return outdeg[a] < outdeg[b]; });
    int ans = 0, cur = 0;
    for (int pos = 0; pos < n; ++pos) {
        int i = idx[pos];
        cur += outdeg[i] - pos;
        ans = max(ans, cur);
    }
    printf("%d\n", ans);
}
