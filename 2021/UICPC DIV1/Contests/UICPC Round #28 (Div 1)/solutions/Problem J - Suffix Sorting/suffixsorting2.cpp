#include <bits/stdc++.h>
using namespace std;

// Suffix Sorting

const int maxn = 1e5 + 3;

string s;
int n, q, x, sa[maxn], ra[maxn], cnt;
vector<pair<pair<int, int>, int>> tmp;
pair<int, int> prevy, nil = {-1, -1};

int main(){
    while(getline(cin, s)){
        n = s.size();
        for(int i = 0; i < n; i++)
            sa[i] = i, ra[i] = s[sa[i]];
        for(int k = 1; k < n; k *= 2){
            tmp.clear();
            for(int i = 0; i < n; i++)
                tmp.push_back({{ra[sa[i]], (sa[i] + k >= n) ? 0 : ra[sa[i] + k]}, sa[i]});
            sort(tmp.begin(), tmp.end());
            cnt = -1;
            prevy = {-1, -1};
            for(int i = 0; i < n; i++){
                sa[i] = tmp[i].second;
                if(tmp[i].first != prevy)
                    cnt++;
                ra[sa[i]] = cnt;
                prevy = tmp[i].first;
            }
            if(ra[sa[n-1]] == n-1)
                break;
        }
        cin >> q;
        while(q--)
            cin >> x, cout << sa[x] << " ";
        cin.ignore(), cout << endl;
    }
}