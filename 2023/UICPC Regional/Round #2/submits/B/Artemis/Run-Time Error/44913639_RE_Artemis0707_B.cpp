#include <bits/stdc++.h>
using namespace std;


bool valid_hash(pair<int,int> words[] , int m) {
    int tab1[m],tab2[m];
    for(int i=0;i<m;i++){
        tab1[i] =-1;
        tab2[i] = -1;
    }

    for (int i=0; i<m;i++) {
        int h1 = words[i].first;
        int h2 = words[i].second;

        if (tab1[h1] == -1) 
            tab1[h1] = i;
        else if (tab2[h2] == -1) 
            tab2[h2] = i;
        else {
            int cur = i;
            for (int j = 0; j < m; ++j) {
                  swap(cur, tab1[h1]);
                h2 = (h2 + 1) % m;
                if (tab2[h2] == -1) {
                    tab2[h2] = cur;
                    break;
                }
            }
            if (tab2[h2] == -1) 
                tab2[h2] = cur;
            else return false; 
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >>m>>n;

        pair<int,int> words[m];
        int h1,h2;
        for (int i = 0; i < m; ++i) {
            cin >> h1 >> h2;
            words[i] = {h1 % n, h2 % n};
        }

        if (valid_hash(words, m))
            cout<<"successful hashing"<<endl;
        else cout<<"rehash necessary"<<endl;
        
    }

    return 0;
}
