#include <bits/stdc++.h>
using namespace std;

#define num unsigned long long int

num n, r, a, bound;
set<num> bad;
set<num> ans;

void produce(num u){
    if(u >= bound)
        return;
    if(bad.find(u) == bad.end()){
        ans.insert(u);
        return;
    }
    produce(2 * u);
    produce(2 * u + 1);
}

int main(){
    cin >> n >> r;
    while(r--){
        cin >> a;
        while(a)
            bad.insert(a), a /= 2;
    }
    bound = 1ull << (n + 1);
    produce(1ull);
    for(num a : ans)
        cout << a << " ";
    cout << endl;
}