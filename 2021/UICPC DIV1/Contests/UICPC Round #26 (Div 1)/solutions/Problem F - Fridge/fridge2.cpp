#include <bits/stdc++.h>
using namespace std;

// Fridge

int a[12];

int main(){
    string s;
    cin >> s;
    for(char c : s)
        a[c - '0']++;
    for(int i = 1; i < 10; i++)
        if(a[i] == 0){
            cout << i << endl;
            return 0;
        }
    if(a[0] == 0){
        cout << 10 << endl;
        return 0;
    }
    int mn_indx, mn_value = INT_MAX;
    for(int i = 0; i < 10; i++)
        if(mn_value > a[i]){
            mn_value = a[i];
            mn_indx = i;
        }
    if(mn_indx != 0){
        for(int i = 0; i < mn_value + 1; i++)
            cout << mn_indx;
        cout << endl;
        return 0;
    }
    for(int i = 1; i < 10; i++)
        if(a[i] == mn_value){
            for(int k = 0; k < mn_value + 1; k++)
                cout << i;
            cout << endl;
            return 0;
        }
    cout << 1;
    for(int i = 0; i < mn_value + 1; i++)
        cout << 0;
    cout << endl;
}