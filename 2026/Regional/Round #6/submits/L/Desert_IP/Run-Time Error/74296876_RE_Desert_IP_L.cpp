#include <iostream>
#include <cstring>

using namespace std;

int main() {
    long long n,k,q,i,j,x,aa =0,sum = 0;
    cin>>n;
    long long a[n*(n+1)];
    memset(a, 0, sizeof(a));
    long long b[n*(n+1)];
    memset(b, 0, sizeof(b));

    cin>>k;
    for (int l = 0; l < k; ++l){
        cin>>i>>j>>x;
        aa = (j-1) + ((i-1) * n);
        a[aa] = x;
    }
    cin>>q;
    for (int l = 0; l < q; ++l){
        cin>>j>>i>>x;
        aa = (j-1) + ((i-1) * n);
        b[aa] = x;
    }
    for (int l = 0; l < n*n; ++l) {
        sum += a[l] * b[l];
    }
    cout<<sum;
    return 0;
}