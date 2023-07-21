#include <bits/stdc++.h>

using namespace std;

// UnionFind class -- based on Howard Cheng's C code for UnionFind
// Modified to use C++ by Rex Forsyth, Oct 22, 2003
//
// Constuctor -- builds a UnionFind object of size n and initializes it
// find -- return index of x in the UnionFind
// merge -- updates relationship between x and y in the UnionFind


class UnionFind
{
      struct UF { int p; int rank; };

   public:
      UnionFind(int n) {          // constructor
	 howMany = n;
	 uf = new UF[howMany];
	 for (int i = 0; i < howMany; i++) {
	    uf[i].p = i;
	    uf[i].rank = 0;
	 }
      }

      ~UnionFind() {
         delete[] uf;
      }

      int find(int x) { return find(uf,x); }        // for client use
      
      bool merge(int x, int y) {
	 int res1, res2;
	 res1 = find(uf, x);
	 res2 = find(uf, y);
	 if (res1 != res2) {
	    if (uf[res1].rank > uf[res2].rank) {
	       uf[res2].p = res1;
	    }
	    else {
	       uf[res1].p = res2;
	       if (uf[res1].rank == uf[res2].rank) {
		  uf[res2].rank++;
	       }
	    }
	    return true;
	 }
	 return false;
      }
      
   private:
      int howMany;
      UF* uf;

      int find(UF uf[], int x) {     // recursive funcion for internal use
	 if (uf[x].p != x) {
	    uf[x].p = find(uf, uf[x].p);
	 }
	 return uf[x].p;
      }
};


int main()
{
  long long N, M, K=1;
  cin >> N >> M;// >> K;

  UnionFind uf(N);
  
  for (int i = 0; i < M; i++) {
    int u, v;//, p;
    cin >> u >> v;// >> p;
    //if (!p) continue;
    u--; v--;
    uf.merge(u, v);
  }
  
  vector<long long> comp_size(N, 0);
  for (int i = 0; i < N; i++) {
    comp_size[uf.find(i)]++;
  }

  long long conn_count = 0;
  for (int i = 0; i < N; i++) {
    long long C = comp_size[i];
    conn_count += C*(C-1)/2;
  }
  
  // probability that none works
  double prob = 1.0;

  for (int i = 0; i < K; i++) {
    long long total = N*(N-1)/2;
    prob *= (1 - (double)conn_count / total);
  }
    
  cout << fixed << setprecision(10) << 1 - prob << endl;
  

  return 0;
}
