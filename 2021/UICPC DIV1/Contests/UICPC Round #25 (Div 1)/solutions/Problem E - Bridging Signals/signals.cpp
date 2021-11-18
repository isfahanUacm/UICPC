#include <bits/stdc++.h>
using namespace std;

vector<int> lis;

int main(){
    int n, a;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        int ptr = lower_bound(lis.begin(), lis.end(), a) - lis.begin();
        if(ptr == lis.size())
            lis.push_back(a);
        else
            lis[ptr] = a;
    }
    cout << lis.size() << endl;
    return 0;
}