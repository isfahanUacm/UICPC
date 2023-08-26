// [BAPC'12] Another Dice Game
// by: Jan Kuipers
// @EXPECTED_RESULTS@: CORRECT

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

const double fac[9] = { 1,1,2,6,24,120,720,5040,40320 };

using namespace std;

vector<vector<vector<double> > > cache;

double p(int n, int d, int m) {

  if (n<0) n = 0;
  if (n==0 && (m&(1<<5))) return 1;
  if (d==0) return 0;

  double &res = cache[n][d][m];
  if (res != -1) return res;

  res = 0;

  for (int n1=0; n1<=d; n1++)
    for (int n2=0; n1+n2<=d; n2++)
      for (int n3=0; n1+n2+n3<=d; n3++)
        for (int n4=0; n1+n2+n3+n4<=d; n4++)
          for (int n5=0; n1+n2+n3+n4+n5<=d; n5++) {

            int nw = d-(n1+n2+n3+n4+n5);

            double best = 0;
            if (n1>0 && !(m&(1<<0))) best = max(best, p(n-1*n1,d-n1,m|(1<<0)));
            if (n2>0 && !(m&(1<<1))) best = max(best, p(n-2*n2,d-n2,m|(1<<1)));
            if (n3>0 && !(m&(1<<2))) best = max(best, p(n-3*n3,d-n3,m|(1<<2)));
            if (n4>0 && !(m&(1<<3))) best = max(best, p(n-4*n4,d-n4,m|(1<<3)));
            if (n5>0 && !(m&(1<<4))) best = max(best, p(n-5*n5,d-n5,m|(1<<4)));
            if (nw>0 && !(m&(1<<5))) best = max(best, p(n-5*nw,d-nw,m|(1<<5)));

            double prob = fac[d]/fac[n1]/fac[n2]/fac[n3]/fac[n4]/fac[n5]/fac[nw] / pow(6.0,d);

            res += best * prob;
          }

  return res;
}

int main () {

  cache = vector<vector<vector<double> > >(41, vector<vector<double> >(9, vector<double>(1<<6, -1)));

  int runs;
  cin >> runs;

  while (runs--) {
    int n;
    cin >> n;
    cout << setprecision(10) << p(n,8,0) << endl;
  }

  return 0;
}
