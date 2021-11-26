#include <bits/stdc++.h>
using namespace std;

// Bridging Signals

int n, a;
vector<int> lis;

int main(){
    cin >> n;
    while(n--){
        cin >> a;
        auto it = upper_bound(lis.begin(), lis.end(), a);
        if(it == lis.end())
            lis.push_back(a);
        else
            *it = a;
    }
    cout << lis.size() << endl;
}