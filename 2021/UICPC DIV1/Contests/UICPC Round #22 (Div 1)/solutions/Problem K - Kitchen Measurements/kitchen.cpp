#include <bits/stdc++.h>
using namespace std;

// Kitchen Measurements

const int inf = INT_MAX;

int n, v, c[5], dis[65][65][65][65];

struct state{
    int w, f[5];

    state(int w, int f1, int f2, int f3, int f4){
        this->w = w;
        this->f[0] = c[0] - (f1 + f2 + f3 + f4);
        this->f[1] = f1;
        this->f[2] = f2;
        this->f[3] = f3;
        this->f[4] = f4;
    }

    bool operator<(const state& o) const{
        return this->w > o.w;
    }
};

priority_queue<state> dij;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> c[i];
    cin >> v;
    for(int i = 0; i < 65; i++)
        for(int j = 0; j < 65; j++)
            for(int k = 0; k < 65; k++)
                for(int a = 0; a < 65; a++)
                    dis[i][j][k][a] = inf;
    dis[0][0][0][0] = 0;
    dij.push(state(0, 0, 0, 0, 0));
    while(!dij.empty()){
        state s = dij.top();
        dij.pop();
        if(s.f[0] == v){
            cout << s.w << endl;
            return 0;
        }
        if(dis[s.f[1]][s.f[2]][s.f[3]][s.f[4]] < s.w)
            continue;
        for(int i = 0; i < n; i++)
            if(s.f[i])
                for(int j = 0; j < n; j++)
                    if(j != i){
                        int pour = min(s.f[i], c[j] - s.f[j]);
                        int cf[5];
                        for(int k = 0; k < 5; k++)
                            cf[k] = s.f[k];
                        cf[i] -= pour, cf[j] += pour;
                        if(s.w + pour < dis[cf[1]][cf[2]][cf[3]][cf[4]])
                            dis[cf[1]][cf[2]][cf[3]][cf[4]] = s.w + pour, dij.push(state(s.w + pour, cf[1], cf[2], cf[3], cf[4])); 
                    }
    }
    cout << "impossible" << endl;
}