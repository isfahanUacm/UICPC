#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;

    vector<pair<long long, long long>> v(n);

    for(int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());
    
    int half = (n-1)/2;
    long long big = 1000000000000LL;

	long long ax = v[half].first + 1, ay = v[half].second-big,bx=v[half].first-1,by=v[half].second+big+((n%2)?0:1);

    printf("%lld %lld\n%lld %lld\n", 
            ax+by-ay, ay-bx+ax,
            ax-by+ay, ay+bx-ax);

    return 0;
}
