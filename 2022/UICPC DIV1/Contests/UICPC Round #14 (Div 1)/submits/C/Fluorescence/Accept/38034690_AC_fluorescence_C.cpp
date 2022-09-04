#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool range(int i ,int j){
    return i>=0 && i<5 && j>=0 && j<5;
}
int main(){
    bool f = true;
    int cnt = 0;
    int move[8][2] = {{-1, -2}, {-2, -1}, {1, -2}, {2, -1}, {-1, 2}, {-2, 1}, {2, 1}, {1, 2}};
    char grid[5][5];

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin>>grid[i][j];
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if(grid[i][j] == 'k'){
                cnt ++;
                for (int t = 0; t < 8; t++)
                {
                    
                    if (range(i+move[t][0], j+move[t][1]) && grid[i+move[t][0]][j+move[t][1]] == 'k'){
                        
                        f = false;
                        break;
                    }
                }
                if (!f) break;
            }
        }
        if (!f) break;
    }

    if (cnt == 9){
        if (f) cout<<"valid\n";
        else cout<<"invalid\n";
    }
    else cout<<"invalid\n";   
}