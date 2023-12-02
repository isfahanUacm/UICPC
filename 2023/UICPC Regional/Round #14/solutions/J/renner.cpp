// @EXPECTED_RESULTS@: CORRECT

#include <iostream>
#include <iomanip>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

typedef unsigned long ul;


#define MAX_N    100
#define MAX_POW   13   // ceil( log2(5000) )

ul N, l, t;
double matrix[MAX_POW+1][MAX_N][MAX_N];
double res[MAX_N];
vector<ul> conn[MAX_N];


void mpow(ul p2) {
  if (p2 <= 1) return;
  if (p2 > 2) mpow(p2 - 1);
  
  for (ul i = 0; i < N; i++) {
    for (ul j = 0; j < N; j++) {
      matrix[p2][i][j] = 0;  // not needed due to memset, but anyway ...
      for (ul k = 0; k < N; k++) {
        matrix[p2][i][j] += matrix[p2-1][i][k] * matrix[p2-1][k][j];
      }
    }
  }
}

void mmult(ul a, ul b) {
  static double tmp[MAX_N][MAX_N];

  for (ul i = 0; i < N; i++) {
    for (ul j = 0; j < N; j++) {
      tmp[i][j] = 0;
      for (ul k = 0; k < N; k++) {
        tmp[i][j] += matrix[a][i][k] * matrix[b][k][j];
      }
    }
  }
  for (ul i = 0; i < N; i++) {
    for (ul j = 0; j < N; j++) {
      matrix[0][i][j] = tmp[i][j];
    }
  }
}


using namespace std;

int main () {
  ul C;
  cin >> C;
  while (C--) {
    cin >> N >> l >> t;
    memset(matrix, 0, sizeof(matrix)); 
    for (ul i = 0; i < N; i++) {
      double m = 0;
      cin >> m;
      for (ul j = 0; j < N; j++) {
        matrix[0][j][i] = m;
      }
    }
    for (ul i = 0; i < N; i++) {
      conn[i].clear(); 
      matrix[1][i][i] = 1.0;
    }
    for (ul i = 0; i < l; i++) {
      double m;
      ul from, to;
      cin >> from >> to;
      cin >> m;
      matrix[1][from][to]    = m;
      matrix[1][from][from] -= m;
      conn[from].push_back(to);
      conn[to].push_back(from);
    }

    // count ones
    ul p2 = 0;
    for (ul tt = t; tt; p2++, tt /= 2) {}
//cout << p2 << endl;

    // get powers of 2
    mpow(p2);


    // finalize results
/* debug */
/*
    cout << endl << endl << "=== START ===" << endl;
    for (ul p = 0; p <= p2; p++) {
      for (ul i = 0; i < N; i++) {
        for (ul j = 0; j < N; j++) {
          cout << matrix[p][i][j] << " ";
        }
        cout << endl;
      }
      cout << "====" << endl;
    }
/**/
    
    // get result
    p2 = 0;
    for (ul tt = t; tt; p2++, tt /= 2) {
      if (tt & 1) mmult(0, p2+1);
    }
/* to check if ordering of multiplications matters
    p2 = 0;
    for (ul tt = t; tt == t; p2++, tt >>= 1) {}
    for (ul tt = t >> p2, p2x = p2; tt; p2x++, tt >>= 1) {
      if (tt & 1) mmult(0, p2x+1);
    }
    mmult(0, p2);
*/
    double mm = 1e304;
    for (ul i = 0; i < N; i++) {
      res[i] = matrix[0][0][i];
      for (ul c = 0; c < conn[i].size(); c++) {
        res[i] += matrix[0][0][conn[i][c]];
      }
      if (res[i] < mm) {
        mm = res[i];
      }
    }
    cout << setprecision(10) << mm << endl;
  }

  return 0;
}

