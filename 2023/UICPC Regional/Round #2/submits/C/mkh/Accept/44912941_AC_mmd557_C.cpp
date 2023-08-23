#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, int> pbb;
typedef tuple<int, bool, bool> tibb;


int main() {
    int b;
    cin >>b;
    for (int i = 0; i < b; ++i) {
        int a;
        cin >> a;
        vector<int> v;
        for (int i = 0; i < a; ++i) {
            int t;
            cin >> t;
            v.push_back(t);
        }
        int m = *min_element(v.begin(), v.end());
        int min = *max_element(v.begin(), v.end());

        cout << 2 * (min - m)<< endl;
    }
    return 0;
}
