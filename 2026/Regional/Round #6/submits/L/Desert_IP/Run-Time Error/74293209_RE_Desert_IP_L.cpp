#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int n,k,i,j,x,aa,sum = 0;
    cin>>n;
    int a[n*n];
    memset(a, 0, sizeof(a));
    int b[n*n];
    memset(b, 0, sizeof(b));

    cin>>k;
    while(k--){
        cin>>i>>j>>x;
        aa = (i-1) + ((j-1) * n);
        a[aa] = x;
    }
    cin>>k;
    while(k--){
        cin>>j>>i>>x;
        aa = (i-1) + ((j-1) * n);
        b[aa] = x;
    }
    for (int l = 0; l < n*n; ++l) {
        sum += a[l] * b[l];
    }
    cout<<sum;
    return 0;
}