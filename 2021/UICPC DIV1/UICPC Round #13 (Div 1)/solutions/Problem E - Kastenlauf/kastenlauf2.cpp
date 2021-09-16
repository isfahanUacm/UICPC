#include <bits/stdc++.h>
using namespace std;

// Kastenlauf

int n, x[103], y[103];
bool floyd[103][103];

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n, n += 2;
        for(int i = 0; i < n; i++)
            cin >> x[i] >> y[i];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                floyd[i][j] = i == j;
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++){
                int d = abs(x[i] - x[j]) + abs(y[i] - y[j]);
                if(d <= 1000)
                    floyd[i][j] = floyd[j][i] = true;
            }
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    if(floyd[i][k] && floyd[k][j])
                        floyd[i][j] = true;
        cout << (floyd[0][n-1] ? "happy" : "sad") << endl;
    }
}