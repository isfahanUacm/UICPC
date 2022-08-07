#include <string>
#include<algorithm>
#include<vector>
#include<iostream>
//#include<bits/stdc++.h>
using namespace std;




bool trivial (string a){

    vector <char> comp = {'z'};

    int anz = 0;
    for (auto x : a){

        if (x == 'B'){
            anz++;
            continue;
        }

        if( comp.back() == x){
            comp.pop_back();
            continue;
        }

        comp.push_back(x);
    }
   /* cout << "x: ";
    for (auto x : comp){
        cout << x << "\n";
    }
    cout << "anz: " << " " << anz << endl;*/

    return (comp.size()==1 && anz%2==0);
}

void do_test(){


    string a, b; cin >> a >> b;
    reverse(b.begin(), b.end());
    string c = a+b;

    if (trivial(c)){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }

}

signed main(){
    int T; cin >> T;
    while(T--){
        do_test();
    }

}
