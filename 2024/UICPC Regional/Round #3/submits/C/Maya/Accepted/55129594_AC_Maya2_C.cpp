#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "/home/mohammad/code/debug.h"
#else
#define dbg(...)
#endif

string mx_ball(map<string, int> score) {
    if (score["black"] != 0) return "black";
    if (score["pink"] != 0) return "pink";
    if (score["blue"] != 0) return "blue";
    if (score["brown"] != 0) return "brown";
    if (score["green"] != 0) return "green";
    if (score["yellow"] != 0) return "yellow";
    if (score["red"] != 0) return "red";
}

void solve() {
    map<string, int> score;
    score["red"] = 1;
    score["yellow"] = 2;
    score["green"] = 3;
    score["brown"] = 4;
    score["blue"] = 5;
    score["pink"] = 6;
    score["black"] = 7;

    long long ans = 0;
    int n;
    cin >> n;
    map<string, int> balls;
    int nball=0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        balls[s]++;
        nball++;
    }

    bool red_turn = false;
    while (nball) {
        dbg(balls, ans);
        if (red_turn) {
            if (!balls["red"]) {
                red_turn = false;
                continue;
            }
            nball--;
            balls["red"]--;
            ans++;
            red_turn = false;
        } else {
            string mxmx = mx_ball(balls);
            if (mxmx == "red") break;
            if(balls["red"] != 0) {
                ans += score[mxmx];
            } else {
                nball--;
                ans += score[mxmx];
                balls[mxmx]--;
            }
            red_turn = true;
        }
    }
    if (ans == 0 && balls["red"]) ans = 1;

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
