#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=2e5+9, INF=1e9+7;
int a[N];

int32_t main(){
    while(true) {
        int n;
        cin >> n;
        if (n==0) return 0;
        vector<int> ans;
        string s, t;
        cin >> s >> t;
        string s1, t1;
        s1 = s; t1 = t;
        sort(s1.begin(), s1.end());
        sort(t1.begin(), t1.end());
        if (s1 != t1) {
            cout << "no" << endl;
            continue;
        }
        else {
            cout << "yes" << endl;
            int i = n-1;
            while(i >= 0) {
                if (t[i] == 'a') {
                    int j = 0;
                    vector <int> ans;
                    while(s[j] == 'b' && j <= i) j++;
                    if (s[j] == 'a' && j <= i) j++;
                    while(j <= i) {
                        if (s[j] == 'b')
                            ans.push_back(2);
                        j++;
                    }
                    for (int k = 0 ; k < ans.size(); k++) {
                        cout << 'A';
                    }
                    for (int k = 0 ; k <= i; k++) {
                        for (int l = k+1 ; l <= i; l++) {
                            if (s[k] < s[l]) swap(s[k], s[l]);
                        }
                    }
                    //cout << 'S' << ' ' << s << endl;
                    while(t[i] == 'a') i--;
                    //cout << i << endl;
                }
                else {
                    int j = 0;
                    vector <int> ans;
                    while(s[j] == 'a' && j <= i) j++;
                    if (s[j] == 'b' && j <= i) j++;
                    while(j <= i) {
                        if (s[j] == 'a')
                            ans.push_back(2);
                        j++;
                    }
                    for (int k = 0 ; k < ans.size(); k++) {
                        cout << 'B';
                    }
                    for (int k = 0 ; k <= i; k++) {
                        for (int l = k+1 ; l <= i; l++) {
                            if (s[k] > s[l]) swap(s[k], s[l]);
                        }
                    }
                    //cout << 'S' << ' ' << s << endl;
                    while(t[i] == 'b') i--;
                    //cout << i << endl;
                }
            }
        }
        cout << endl;
    }
    return 0;
}