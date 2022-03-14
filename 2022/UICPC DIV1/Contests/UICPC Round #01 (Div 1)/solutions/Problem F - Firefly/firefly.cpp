#include <bits/stdc++.h>

using namespace std;

int n, mi, l, obsu, obsd, val;
double h , a;
vector<double> stit, smit;

int main()
{
    cin >> n >> h;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        if (i % 2)
            stit.push_back(a);
        else
            smit.push_back(a);
    }
    mi = n+1;
    sort(stit.begin(), stit.end());
    sort(smit.begin(), smit.end());
    for (double i = .5; i < h; ++i) {
        obsu = distance(upper_bound(stit.begin(), stit.end(), h-i), stit.end());
        obsd = distance(upper_bound(smit.begin(), smit.end(), i), smit.end());
        val = obsu + obsd;
        if (mi > val){
            mi = val;
            l = 1;
        }
        else if (mi == val)
            l++;
    }
    cout << mi << " " << l << endl;
    return 0;
}

