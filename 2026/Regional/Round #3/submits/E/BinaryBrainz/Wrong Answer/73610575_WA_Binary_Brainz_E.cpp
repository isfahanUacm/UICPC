#include <bits/stdc++.h>
using namespace std;
void solve() {

    int n, k;
    cin >> n >> k;


    vector<int> v(n);

    for (int i =0 ; i < n ; i++) {
        cin >> v[i];
    }

    vector<int> linds(n+1), liss(n+1), s(n+1);
    s[0] = 0;
    for (int i = 1 ; i <= n ; i++) {
        s[i] = v[i-1] + s[i-1];
    }


    int cs = 1;
    int lind = 0;
    int lis = 1;

    liss[1] = 1;
    linds[1] = 0;

    for (int i = 1; i < n ; i++ ) {
        if (v[i] > v[i - 1]) {
            cs++;
            if (cs >= lis) {
                lis = cs;
                lind = i;
            }
        }
        else {
            cs = 1;
            if (lis == 1) {
                lind = i;
            }
        }
        linds[i + 1] = lind;
        liss[i + 1] = lis;
    }

    for (int j = 1 ; j <= n ; j++) {
        if ((linds[j] == j - 1) && (liss[j] > v[j-1])) {

            long int bef_sum = s[j];

            long int tmp_n = liss[j] - 1 + k;
            long int after_sum = tmp_n * (tmp_n + 1) / 2;

            tmp_n = liss[j] - 1;
            after_sum -= tmp_n * (tmp_n + 1) / 2;

            cout << bef_sum + after_sum << ' ';
        }
        else {
            cout << s[j] + k * liss[j] <<' ';
        }
    }

}

int main() {

    int t=1;
    cin>>t;
    while(t--){
        solve();
        if (t)cout<<"\n";
    }

    return 0;
}