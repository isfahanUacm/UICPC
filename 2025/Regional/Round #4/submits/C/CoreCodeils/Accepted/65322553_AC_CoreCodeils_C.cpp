#include <iostream>
#include <set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define endl "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k,n ;
    cin >> n>>k;
    set<int> arr2;
    for (int i = 0 ; i <n ; i++) {
        int w ;
        cin >> w;
        arr2.insert(w);
    }
    cout<<min(int(arr2.size()),k)<<endl;


    return 0;
}
