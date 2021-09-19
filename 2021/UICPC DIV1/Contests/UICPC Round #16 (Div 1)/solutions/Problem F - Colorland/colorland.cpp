#include <bits/stdc++.h>
using namespace std;

string idcolor[6] = {"Blue", "Orange", "Pink", "Green", "Red", "Yellow"};
map<string, int> mp = {{"Blue", 1}, {"Orange", 2}, {"Pink", 3}, {"Green", 4}, {"Red", 5}, {"Yellow", 6}};
int colorboard[200003];
int n;

int main()
{
    string s;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        colorboard[i+1] = mp[s];
    }
    int cur = 0, bestt = 0;
    int c = 0;
    while(cur < n){
        for (int i = 1; i <= 6; ++i) {
//            auto ii = find(colorboard+cur+1, colorboard+n+1, i);
//            cout << *ii << endl;
            int it = find(colorboard+cur+1, colorboard+n+1, i) - colorboard;
//            cerr << i << " " << it << endl;
            if(it == n+1){
                continue;
            }
            bestt = max(it, bestt);
        }
        cur = bestt;
//        cout << cur << endl;
        c++;
    }
    cout << c << endl;
    return 0;
}
