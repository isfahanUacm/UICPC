#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

const int INF = 1e9+7;
const int maxN = 1e5+5;

int arr[maxN];

void solve(){
    int n;
    cin >> n;
    int r = log2(n);
    if(pow(2,r) != n)
        r++;
    int ind = 0, z = 1;
    cout << r*2+2 << '\n';
    while (r--) {
        cout << 'B' << ind+1 << " = " << 'B' << ind <<" << " << z << '\n';
        cout << 'B' << ind+2 << " = " << 'B' << ind << " | " << 'B' << ind+1 << '\n';
        ind += 2;
        z *= 2;
    }
    cout << 'B' << ind+1 << " = " << 'B' << ind << " << 1\n";
    cout << 'B' << ind+2 << " = " << 'B' << ind << " ^ " << 'B' << ind+1 << '\n';
}

int main()
{
    int t=1;
//    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
