#include <bits/stdc++.h>
using namespace std;

#define M 20000000
string s[26];
int n, dp[20][2000], dif[20][20];

int solve(int i, int num){
      num |= (1 << i);
      
      if (num == pow(2, n)-1) return 0;
      if (dp[i][num] != -1) return dp[i][num];

      int ans = M;
      for (int j=0 ; j<n; j++)
            if ( !(num & (1<<j)) )
                  ans = min(ans, solve(j, num)+dif[i][j]);
      
      return dp[i][num] = ans;
}

int diffrent (int i, int j){
      vector <int> num(26, 0);

      for (int x=0; x<s[i].size(); x++)
            num[s[i][x]-'A']++;
      for (int x=0; x<s[j].size(); x++)
            num[s[j][x]-'A']++;

      int ans = 0;
      for (int x=0; x<26; x++)
            if (num[x] == 2) ans++;
      
      return ans;
}

int main(){
      cin >> n;
      for (int i=0; i<n; i++)
            cin >> s[i];
      
      memset(dif, 0, sizeof(dif));
      for (int i=0; i<n; i++)
            for (int j=i+1; j<n; j++){
                  dif[i][j] = diffrent(i, j);
                  dif[j][i] = dif[i][j];
            }
      
      memset(dp, -1, sizeof(dp));
      int ans = M;
      for (int i=0; i<n; i++)
            ans = min(ans, solve(i, 0));

      cout << ans << endl;

      return 0;
}