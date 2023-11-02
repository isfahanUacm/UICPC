#include <array>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int solve(const string& s) {
    int n = s.size();
    if (n == 1) return 0;

    // for each l, find the shortest r such that [l, r] has all the chars
    array<int, 300> has = {0};
    for (char c : s) {
        has[c] = 1;
    }

    int goal = 0;
    for (int x : has) {
        goal += x;
    }

    array<int, 300> freq = {0};
    int cur = 0;
    vector<int> rs(n, -1);
    for (int l = 0; l < n; ++l) {
        if (l > 0) rs[l] = rs[l - 1];
        while (rs[l] + 1 < n && cur < goal) {
            // I'm sorry
            cur += freq[s[++rs[l]]]++ == 0;
        }

        if (cur < goal) {
            // No suffix has all the characters
            rs[l] = -1;
            break;
        }

        cur -= --freq[s[l]] == 0;
    }

    // [l, r] is minimal if rs[l + 1] != rs[l]
    // We could do this part in O(n log n) with a suffix array, but I think I've
    // already overkilled this problem.
    //
    // To be clear on how to do so, sort the candidates using the suffix array, then
    // check if adjacent ones are equal using LCPs. Could even be O(n) with careful impl.
    unordered_set<string> strs;
    for (int l = 0; l + 1 < n; ++l) {
        if (rs[l] == -1) break;
        if (rs[l] != rs[l + 1] && !(l == 0 && rs[l] == n - 1)) {
            string sub = s.substr(l, rs[l] + 1 - l);
            strs.insert(sub);
        }
    }

    return strs.size();
}

int32_t main() {
    string s;
    while (cin >> s) {
        cout << solve(s) << '\n';
    }

    return 0;
}
