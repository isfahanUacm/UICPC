#include <bits/stdc++.h>
using namespace std;

bool equal(valarray<char> v, string s){
    for(int i = 0; i < s.size(); i++){
        if(v[i] != s[i])
            return false;
    }
    return true;
}
 
int main(){
    string s;
    cin >> s;
    for(int i = 1; i != s.size()+1; i++){
        bool acc = 0;
        if(s.size() % i == 0){
            acc = 1;
            valarray<char> sub(s.substr(0, i).c_str(), i);
            for(int j = 0; j < s.size(); j += i){
                if(!equal(sub, s.substr(j, i))){
                    acc = 0;
                    break;
                }
                sub = sub.cshift(-1);
            }
        }
        if(acc){
            cout << i << endl;
            break;
        }
    }
}




