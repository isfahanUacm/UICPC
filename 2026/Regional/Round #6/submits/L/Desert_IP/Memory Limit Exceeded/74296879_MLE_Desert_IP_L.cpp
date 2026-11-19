#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main() {
//    struct a{
//        int i;
//        int j;
//        int x;
//    };
    int n,k,q,i,j,x,aa =0,sum = 0;
    cin>>n;
    vector<int> b(n * n, 0);

    cin>>k;
    for (int l = 0; l < k; ++l){
        cin>>i>>j>>x;
        aa = (j-1) + ((i-1) * n);
        b[aa] = x;
    }
    cin>>q;
    for (int l = 0; l < q; ++l){
        cin>>j>>i>>x;
        aa = (j-1) + ((i-1) * n);
        if(b[aa] != 0)
            sum += b[aa] * x;
    }
    cout<<sum;
    return 0;
}