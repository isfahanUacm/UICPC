#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

int main() {

    int n,k,q,i,j,x,aa =0,sum = 0;
    cin>>n;
    cin>>k;

    unordered_map<int, int> mp;
    for (int l = 0; l < k; ++l){
        cin>>i>>j>>x;
        aa = (j-1) + ((i-1) * n);
        mp[aa] = x;
    }
    cin>>q;
    for (int l = 0; l < q; ++l){
        cin>>j>>i>>x;
        aa = (j-1) + ((i-1) * n);
        if(mp.find(aa) != mp.end())
            sum += mp[aa] * x;
    }
    cout<<sum;
    return 0;
}