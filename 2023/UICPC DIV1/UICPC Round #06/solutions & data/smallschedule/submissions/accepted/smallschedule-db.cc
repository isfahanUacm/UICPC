// A slow, but acceptable solution

#include <bits/stdc++.h>
using namespace std;

int main(){
  int Q, M, S, L;
  cin >> Q >> M >> S >> L;

  vector<int> A(M);

  // Greedily allocate the Q's...
  for(int i=0;i<L;i++)
    A[i % M] += Q;

  // Even up everything if we need to...
  for(int i=1;i<M;i++)
    if(A[i] != A[i-1]){
      A[i] = A[i-1];
      S -= Q;
    }

  // Now fill in the remaining...
  for(int i=0;S > 0;i=(i+1)%M, S--)
    A[i]++;

  // Now the largest computer is the answer (should be A[0])
  cout << *max_element(begin(A), end(A)) << endl;
}
