#include <bits/stdc++.h>
using namespace std;

// Class Picture

int n;
string name[13];
map<string, int> id;
bool enemies[13][13];

bool success;
int order[13];
bool taken[13];

void track(int i){
    if(i == n){
        success = true;
        for(int j = 0; j < n; j++)
            cout << name[order[j]] << " ";
        cout << endl;
    }
    for(int j = 0; j < n; j++){
        if(taken[j])
            continue;
        if(i > 0 && enemies[order[i-1]][j])
            continue;
        order[i] = j;
        taken[j] = true;
        track(i+1);
        taken[j] = false;
        if(success)
            return;
    }
}

int main(){
    while(cin >> n){
        for(int i = 0; i < n; i++)
            cin >> name[i];
        sort(name, name+n);
        id.clear();
        for(int i = 0; i < n; i++)
            id[name[i]] = i;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                enemies[i][j] = false;
        int m;
        cin >> m;
        for(int i = 0; i < m; i++){
            string x, y;
            cin >> x >> y;
            int xi = id[x];
            int yi = id[y];
            enemies[xi][yi] = true;
            enemies[yi][xi] = true;
        }
        success = false;
        for(int i = 0; i < n; i++)
            taken[i] = false;
        track(0);
        if(!success)
            cout << "You all need therapy." << endl;
    }
}