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
        if (t[n - 1] == 'a') {
            int i = 0;
            while(s[i] == 'b' && i < n) i++;
            while(s[i] == 'a' && i < n) i++;
            while(i < n) {
                if(s[i] == 'b') ans.push_back(2);
                i++;
            }
            sort(s.begin(), s.end());
            reverse(s.begin(), s.end());
            string w = t;
            sort(w.begin(), w.end());
            reverse(w.begin(), w.end());
            if (w != s) {
                cout << "no" << endl;
            }
            else {
                cout << "yes" << endl;
                for (int i = 0 ; i < ans.size() ; i++) {
                    if (ans[i] == 2) {
                        cout << 'A';
                    }
                }
                for (int i = t.size() - 1; i >= 0; i--) {
                    if (t[i] == 'a') {
                        cout << 'B';
                    }
                    else {
                        cout << 'A';
                    }
                }
            }
        }
        else {
            int i = 0;
            while(s[i] == 'a' && i < n) i++;
            while(s[i] == 'b' && i < n) i++;
            while(i < n) {
                if(s[i] == 'a') ans.push_back(2);
                i++;
            }
            sort(s.begin(), s.end());
            string w = t;
            sort(w.begin(), w.end());
            if (w != s) {
                cout << "no" << endl;
            }
            else {
                cout << "yes" << endl;
                for (int i = 0 ; i < ans.size() ; i++) {
                    if (ans[i] == 2) {
                        cout << 'B';
                    }
                }
                for (int i = t.size() - 1; i >= 0; i--) {
                    if (t[i] == 'a') {
                        cout << 'B';
                    }
                    else {
                        cout << 'A';
                    }
                }
            }
        }
    }
    return 0;
}