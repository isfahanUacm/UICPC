#include <bits/stdc++.h>
using namespace std;

// Kitten on a Tree

int k, a, b, par[103];
string line;

int main(){
    fill_n(par, 103, -1);
    cin >> k;
    cin.ignore();
    while(1){
        getline(cin, line);
        stringstream ss(line);
        ss >> a;
        if(a == -1)
            break;
        while(ss >> b)
            par[b] = a;
    }
    while(k != -1)
        cout << k << " ", k = par[k];
    cout << endl;
}