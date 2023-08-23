#include <bits/stdc++.h>
using namespace std;


bool valid_hash(pair<int,int> words[] , int m, int n) {
    int tab[n];
    for(int i=0;i<n;i++){
        tab[i] =-1;
    }

    for (int i=0; i<m;i++) {
        int h1 = words[i].first;
        int h2 = words[i].second;

        if (tab[h1] == -1) 
            tab[h1] = i;
        else if (tab[h2] == -1) 
            tab[h2] = i;
        else {
            int cur = i;
            for (int j = 0; j < m; ++j) {
                  swap(cur, tab[h1]);
                h2 = (h2 + 1) % n;
                if (tab[h2] == -1) {
                    tab[h2] = cur;
                    break;
                }
            }
            if (tab[h2] == -1) 
                tab[h2] = cur;
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

        if (valid_hash(words, m,n))
            cout<<"successful hashing"<<endl;
        else cout<<"rehash necessary"<<endl;
        
    }

    return 0;
}
