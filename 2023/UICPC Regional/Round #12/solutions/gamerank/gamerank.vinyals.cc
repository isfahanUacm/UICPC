#include <iostream>
using namespace std;

int starlimit[26] = {
  1<<29,
  5,5,5,5,5,5,5,5,5,5,
  4,4,4,4,4,
  3,3,3,3,3,
  2,2,2,2,2
};

int main() {
  int rank=25;
  int stars=0;
  int consecutive=0;
  string s;
  cin >> s;
  for (char c : s) {
    if (rank==0) break;
    if (c=='W') {
      consecutive++;
      stars++;
      if (rank>=6 and consecutive>=3) stars++;
      if (stars>starlimit[rank]) {
        stars-=starlimit[rank];
        rank--;
      }
    }
    else {
      consecutive=0;
      if (stars==0 and rank<20) {
        rank++;
        stars=starlimit[rank];
      }
      if (rank<=20 and stars>0) stars--;
    }
  }
  if (rank) cout << rank << endl;
  else cout << "Legend" << endl;
}
