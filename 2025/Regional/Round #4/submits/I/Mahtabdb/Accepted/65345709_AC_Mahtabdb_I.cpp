#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long a[10], s[10];
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> s[i];

    double max_avg = 0.0;

  
    for (int mask = 1; mask < (1 << n); ++mask) {
        long long sum_s = 0;
        int team_size = 0;

        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                sum_s += s[i];
                team_size++;
            }
        }

        long long total = sum_s + a[team_size - 1];
        double avg = (double)total / team_size;

        if (avg > max_avg) max_avg = avg;
    }

    cout << fixed << setprecision(6) << max_avg << endl;

    return 0;
}
