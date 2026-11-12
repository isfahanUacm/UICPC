#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    char ta, td;
    ll p,h;
    cin>>ta>>td>>p>>h;
    if ((ta=='G' && td=='W')||(ta=='F' && td=='G')||(ta=='W' && td=='F')) {
        h-=p*2;
    }
    else {
        h-=p*0.5;
    }
    if (h<=0)
        cout<<"Nocaute!"<<endl;
    else cout<<"Sobraram "<<h<<" pontos de vida!"<<endl;
    return 0;
}