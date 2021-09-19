#include <bits/stdc++.h>
using namespace std;

// Battleship

int n, m, q;
char p[3][33][33];

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> m >> n >> q;
        int s1 = 0, s2 = 0;
        for(int i = n-1; i >= 0; i--)
            for(int j = 0; j < m; j++){
                cin >> p[0][i][j];
                if(p[0][i][j] == '#')
                    s1++;
            }
        for(int i = n-1; i >= 0; i--)
            for(int j = 0; j < m; j++){
                cin >> p[1][i][j];
                if(p[1][i][j] == '#')
                    s2++;
            }
        bool turn = true, end = false;
        while(q--){
            int x, y;
            cin >> y >> x;
            if(end)
                continue;
            if(p[turn][x][y] == '#'){
                p[turn][x][y] = '_';
                if(turn){
                    s2--;
                    if(!s2) turn = !turn;
                }
                else{
                    s1--;
                    if(!s1) end = true;
                }
            }
            else turn = !turn;
        }
        if(s1 && !s2)
            cout << "player one wins" << endl;
        else if(!s1 && s2)
            cout << "player two wins" << endl;
        else 
            cout << "draw" << endl;
    }
}