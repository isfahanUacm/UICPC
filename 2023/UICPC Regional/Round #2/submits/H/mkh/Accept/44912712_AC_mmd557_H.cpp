#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, int> pbb;
typedef tuple<int, bool, bool> tibb;


int main() {
    int a;
    cin >>a;
    vector<int> v;
    for (int i = 0; i < a; ++i) {
        int t ;
        cin >>t;
        v.push_back(t);
    }
    sort(v.rbegin(), v.rend());
    int counter=0;
    long ans = 0;
    for (int i = 0; i < a; ++i) {
        counter++;
        if(counter == 3) {
            counter = 0;
            ans += v[i];
        }
    }
    cout << ans;
    return 0;
}
