#include <bits/stdc++.h>
using namespace std;

// Island Tour

const int maxn = 403;

int n, d[maxn], t[3][maxn], start[3];
vector<pair<int, int>> busy[maxn];

inline bool joint(pair<int, int> a, pair<int, int> b){
    if (a.first >= b.second || a.second <= b.first)
        return false;
    return true;
}

bool track(int i){
    if (i == 3) {
        for (int j = 0; j < 3; j++)
            cout << start[j] + 1 << " ";
        cout << endl;
        return true;
    }
    int bound = n;
    if (i == 0)
        bound = 1;
    for(int a = 0; a < bound; a++){
        start[i] = a;
        vector<int> push;
        int s = 0;
        bool valid = true;
        for(int j = 0; j < n; j++){
            int b = (a + j) % n;
            pair<int, int> visit{s, s + t[i][b]};
            for(pair<int, int> c : busy[b])
                if (joint(c, visit)) {
                    valid = false;
                    break;
                }
            if (!valid)
                break;
            busy[b].push_back(visit);
            push.push_back(b);
            s += t[i][b] + d[b]; 
        }
        if (valid && track(i + 1))
            return true;
        for(int b : push)
            busy[b].pop_back();
    }
    return false;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> d[i];
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < n; j++)
            cin >> t[i][j];
    if (!track(0))
        cout << "impossible" << endl;
}