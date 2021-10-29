#include <bits/stdc++.h>
using namespace std;

// Prince and Princess

map<int, int> m;
vector<int> lis;

int main(){
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++){
        int n, p, q;
        cin >> n >> p >> q;
        m.clear();
        lis.clear();
        for(int i = 0; i <= p; i++){
            int x;
            cin >> x;
            m[x] = i;
        }
        for(int i = 0; i <= q; i++){
            int x;
            cin >> x;
            if(m.find(x) == m.end())
                continue;
            int y = m[x];
            auto ptr = upper_bound(lis.begin(), lis.end(), y);
            if(ptr == lis.end())
                lis.push_back(y);
            else *ptr = y;
        }
        cout << "Case " << tc << ": " << lis.size() << endl;
    }
}