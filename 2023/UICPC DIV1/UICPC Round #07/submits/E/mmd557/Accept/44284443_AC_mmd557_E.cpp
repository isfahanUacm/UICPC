#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <numeric>
#include <bits/stdc++.h>

using namespace std;


int main() {
    vector<long> arr;
    long a;
    cin >>a;
    for (int i = 0; i < a; ++i) {
        long b;
        cin >> b;
        arr.push_back(b);
    }
    sort(arr.rbegin(), arr.rend());

    long loser_wins = ((arr.size() + 1) / 2) - 1;
    long ans = 0;
    for (int i = 0; i < loser_wins; ++i) {
        ans += arr[i];
    }
    for (int i = loser_wins; i < arr.size(); ++i) {
        long tmp = ((arr[i] + 1) / 2 ) -1;
        ans += tmp;
    }

    cout << ans;
    return 0;
}