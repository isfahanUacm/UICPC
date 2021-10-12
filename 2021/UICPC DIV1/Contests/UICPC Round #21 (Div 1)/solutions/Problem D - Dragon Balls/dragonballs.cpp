#include <bits/stdc++.h>
using namespace std;

// Dragon Balls

#define num long long int

set<num> squares;

map<num, num> root;

int n;

int main(){
    cin >> n;
    for(num a = 0; a <= 1000000; a++)
        squares.insert(a * a), root[a * a] = a;
    while(n--){
        cout << "0 0" << endl;
        cout.flush();
        num d;
        cin >> d;
        if(!d)
            continue;
        num t;
        for(num a : squares){
            num b = d - a;
            if(squares.find(b) == squares.end())
                continue;
            cout << root[a] << " " << root[b] << endl;
            cout.flush();
            cin >> t;
            if(!t)
                break;
            if(a != b){
                cout << root[b] << " " << root[a] << endl;
                cout.flush();
                cin >> t;
                if(!t)
                    break;
            }
        }
    }
}