#include <bits/stdc++.h>
using namespace std;

// Greeting Card

/*
for a in range(0, 2019):
        for b in range(a+1, 2019):
                if a * a + b * b == 2018 * 2018:
                        print("%d %d" %(a, b))
0 2018
1118 1680
*/

int adjR[12]{0, 2018, 0, -2018, 1118, -1118, 1118, -1118, 1680, -1680, 1680, -1680};
int adjC[12]{2018, 0, -2018, 0, 1680, 1680, -1680, -1680, 1118, 1118, -1118, -1118};

int n, x, y;
set<pair<int, int>> s;

int main(){
    cin >> n;
    while(n--)
        cin >> x >> y, s.insert({x, y});
    int ans = 0;
    for(pair<int, int> p : s)
        for(int k = 0; k < 12; k++)
            if(s.find({p.first + adjR[k], p.second + adjC[k]}) != s.end())
                ans++;
    cout << ans / 2 << endl;
}