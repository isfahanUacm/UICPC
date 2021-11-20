#include <bits/stdc++.h>
using namespace std;

// Chewbacca

#define num long long int

num n, k, q, x, y;
vector<num> p1, p2;

int main(){
    cin >> n >> k >> q;
    while(q--){
        cin >> x >> y, x--, y--;
        p1.clear(), p2.clear();
        num it = x;
        while(it){
            p1.push_back(it);
            it = (it - 1) / k;
        }
        p1.push_back(it);
        it = y;
        while(it){
            p2.push_back(it);
            it = (it - 1) / k;
        }
        p2.push_back(it);
        reverse(p1.begin(), p1.end());
        reverse(p2.begin(), p2.end());
        int nm = 0;
        while(nm < p1.size() && nm < p2.size() && p1[nm] == p2[nm])
            nm++;
        cout << int(p1.size()) - nm + int(p2.size()) - nm << endl;
    }
}