#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string prev, word;
    vector<string> cands;
    int N, freq[256] = {};
    cin >> prev >> N;
    for (int i = 0; i < N; ++i) {
        cin >> word;
        ++freq[word.front()];
        if (word.front() == prev.back())
            cands.push_back(word);
    }
    if (cands.empty()) printf("?\n");
    else {
        for (auto w: cands) {
            if (freq[w.back()] == (w.front() == w.back())) {
                cout << w << "!\n";
                return 0;
            }
        }
        cout << cands.front();
    }
    return 0;
}
