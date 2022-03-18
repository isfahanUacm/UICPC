// Misa

#include <bits/stdc++.h>
using namespace std;

int n, m;
char g[53][53];

int adjR[8]{0, 0, 1, -1, 1, 1, -1, -1};
int adjC[8]{1, -1, 0, 0, 1, -1, 1, -1};

inline int adjs(int i, int j){
  int cnt = 0;
  for(int k = 0; k < 8; k++){
    int x = i + adjR[k];
    int y = j + adjC[k];
    if(x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 'o'){
      cnt++;
    }
  }
  return cnt;
}

int main(){
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> g[i][j];
    }
  }
  int for_misa = -1;
  int for_misa_x = -1;
  int for_misa_y = -1;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(g[i][j] == '.'){
        int ad = adjs(i, j);
        if(ad > for_misa) {
          for_misa = ad;
          for_misa_x = i;
          for_misa_y = j;
        }
      }
    }
  }
  if(for_misa >= 0){
    g[for_misa_x][for_misa_y] = 'o';
  }
  int tot = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(g[i][j] == 'o'){
        tot += adjs(i, j);
      }
    }
  }
  cout << tot / 2 << endl;
}
