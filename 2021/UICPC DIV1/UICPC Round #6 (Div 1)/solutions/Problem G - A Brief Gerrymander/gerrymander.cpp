#include <bits/stdc++.h>
using namespace std;

// A Brief Gerrymander

const int maxn = 1e4 + 3;

int n, x[maxn], y[maxn], s, streets[103], a;
int ps[103][103], ridings[103][103], dp[103][103], trace[103][103];

int main(){
    while(1){
        cin >> n;
        if(n == -1)
            break;
        for(int i = 0; i < n; i++)
            cin >> x[i] >> y[i];
        cin >> s;
        for(int i = 0; i < s; i++)
            cin >> streets[i];
        s--;
        cin >> a;
        a -= 2;
        for(int i = 0; i < s; i++)
            for(int j = 1; j <= 99; j++)
                ps[i][j] = 0;
        for(int k = 0; k < n; k++){
            int i = s-1;
            while(streets[i] > x[k])
                i--;
            ps[i][y[k]] += 1;
        }
        for(int i = 0; i < s; i++)
            for(int j = 1; j < 99; j++)
                ps[i][j + 1] += ps[i][j];
        for(int i = 1; i <= 100; i++)
            for(int j = i; j <= 100; j++){
                int counter = 0;
                for(int k = 0; k < s; k++)
                    if(ps[k][j - 1] - ps[k][i-1])
                        counter++;
                ridings[i][j] = counter;
            } 
        for(int i = 99; i >= 1; i--)
            for(int k = 0; k <= a; k++)
                if(99 - i >= k - 1){
                    if(!k){
                        dp[i][k] = ridings[i][100];
                        continue;
                    }
                    dp[i][k] = -1;
                    for(int j = i + 1; j <= 100 - k; j++)
                        if(ridings[i][j] + dp[j][k - 1] > dp[i][k])
                            dp[i][k] = ridings[i][j] + dp[j][k - 1], trace[i][k] = j;
                }
        cout << a + 2 << " 1 ";
        int i = 1, k = a;
        while(k)
            cout << trace[i][k] << " ", i = trace[i][k], k--;
        cout << 100 << endl;
    }
}