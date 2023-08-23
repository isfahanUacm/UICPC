/* Sample solution to Circle of Debt (NCPC 2007) by Mikael Goldmann
 *
 * (1): it is never optimal for a person to both give and receive money
 *      of the same denomination.
 * (2): money of denomination 0..i-1 must be exchanged so that the
 *      resulting debts are divisible by GCD(money[i..n.1])
 */

#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

struct Config 
{ 
  int owe[3];
  int cost;
  Config() : cost(0) {};

  bool operator<(const Config &b) const
  {
    for (int i=0; i<3; ++i)
      if (owe[i] != b.owe[i]) return owe[i]<b.owe[i];
    return cost<b.cost;    
  };      

  bool operator==(const Config &b) const
  {
    for (int i=0; i<3; ++i)
      if (owe[i] != b.owe[i]) return false;
    return true;
  };      
};
  

const int NVAL=6;
const int   INF = 100000000;
const int VAL[] = { 1,  5, 10, 20,  50, 100 };
const int MOD[] = { 5, 10, 10, 50, 100, INF   };
    
int best;
int money[3][NVAL];


void solve(vector<Config>::const_iterator cstart,
	   vector<Config>::const_iterator cend,
	   int m) 
{
  if (m==NVAL) { // find best solution
    if (best!=INF) printf("%d\n",best);
    else printf("impossible\n");
  }
  else {    
    vector<Config> newlst;
    
    for ( ; cstart != cend; ++cstart) {
      for (int i=0; i<3; ++i) {
	int j=(i+1)%3;
	int k=(i+2)%3;
	for (int gj=-money[j][m]; gj<=money[i][m]; ++gj) { 
	  // gj < 0 <--> i is getting from both j and k
	  // gj >= 0 <--> i is giving to both j and k
	  int oj = cstart->owe[j]+gj*VAL[m];
	  if ((oj+MOD[m])%MOD[m]!=0) continue;
	  int gklow = gj < 0 ? -money[k][m] : 0;
	  int gkhigh = gj < 0 ? -1 : money[i][m]-gj;
	  for (int gk=gklow; gk<=gkhigh; ++gk) {
	    int oi = cstart->owe[i]-(gj+gk)*VAL[m];
	    if ((oi+MOD[m])%MOD[m]!=0) continue;
	    int ok = cstart->owe[k]+gk*VAL[m];
	    int cst = cstart->cost+abs(gj+gk);
	    if (cst >= best) break;
	    if (oi==0 && oj==0 && ok==0) {
	      if ( cst<best) best=cst;
	      continue;
	    }
	    Config newc;	    
	    newc.cost = cst;
	    newc.owe[i]=oi;
	    newc.owe[j]=oj;
	    newc.owe[k]=ok;
	    newlst.push_back(newc);
	  }
	  
	}		    
      }
    }
    sort(newlst.begin(), newlst.end());
    solve(newlst.begin(), unique(newlst.begin(), newlst.end()), m+1);	    
  }  
}

    
 
void solve() 
{
  
  best = INF;
  int ab,bc,ca;
  scanf("%d%d%d", &ab,  &bc,  &ca);
  Config c;
  c.owe[0] = ab-ca;
  c.owe[1] = bc-ab;
  c.owe[2] = ca-bc;
  for (int i=0; i<3; ++i)
    for (int j=0; j<NVAL; ++j)
      scanf("%d", &money[i][NVAL-j-1]);
  vector<Config> lst;
  lst.push_back(c);
  solve(lst.begin(), lst.end(),0);
}


int main() 
{
  int T;
  scanf("%d",&T);
  for (int i=0; i<T; ++i) {
    //fprintf(stderr, "Case %d\n", (i+1));	    
    solve();
  }
}
 
