#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <stack>
#include <math.h>
using namespace std;
using ll = long long;

int main(){

    ll q;
    cin >> q;

    while(q--){
        ll n;
        cin >> n;
        vector<ll> aray(n);

        for (int i = 0; i < n; i++)
            cin >> aray[i];
        
        bool flag = true;
        for (int i =  n - 1; i >= 0; i--){
            if (aray[i] > i + 1){
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}