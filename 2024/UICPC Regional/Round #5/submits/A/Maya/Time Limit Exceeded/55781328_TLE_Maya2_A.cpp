#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "/home/babilash/blue-folder/cp/cf/debug.h"
#else
#define dbg(...)
#define dbgarr(...)
#endif

const int N = 105, mod = 1e9 + 7;

std::vector<std::vector<int>> removeRowAndColumn(const std::vector<std::vector<int>>& matrix, int i, int j) {  
    std::vector<std::vector<int>> result;  

    for (int row = 0; row < matrix.size(); row++) {  
        if (row == i) continue; // Skip the i-th row  
        std::vector<int> newRow;  
        for (int col = 0; col < matrix[row].size(); col++) {  
            if (col == j) continue; // Skip the j-th column  
            newRow.push_back(matrix[row][col]);  
        }  
        result.push_back(newRow);  
    }  
    
    return result;  
}  

int power(long long n, long long k) {
  int ans = 1 % mod; n %= mod; if (n < 0) n += mod;
  while (k) {
    if (k & 1) ans = (long long) ans * n % mod;
    n = (long long) n * n % mod;
    k >>= 1;
  }
  return ans;
}

int Gauss(vector<vector<int>> a) {
  int n = a.size(), m = (int)a[0].size();
  int free_var = 0;
  const long long MODSQ = (long long)mod * mod;
  int det = 1, rank = 0;
  for (int col = 0, row = 0; col < m && row < n; col++) {
    int mx = row;
    for (int k = row; k < n; k++) if (a[k][col] > a[mx][col]) mx = k;
    if (a[mx][col] == 0) {det = 0; continue;}
    for (int j = col; j < m; j++) swap(a[mx][j], a[row][j]);
    if (row != mx) det = det == 0 ? 0 : mod - det;
    det = 1LL * det * a[row][col] % mod;
    int inv = power(a[row][col], mod - 2);
    for (int i = 0; i < n && inv; i++){
      if (i != row && a[i][col]) {
        int x = ((long long)a[i][col] * inv) % mod;
        for (int j = col; j < m && x; j++){
          if (a[row][j]) a[i][j] = (MODSQ + a[i][j] - ((long long)a[row][j] * x)) % mod;
        }
      }
    }
    row++; ++rank;
  }
  return det;
}

int32_t main() {
  int n; cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> a[i][j];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << Gauss( removeRowAndColumn(a, i, j) ) << ' ';
        }
        cout << '\n';
    }
  return 0;
}
