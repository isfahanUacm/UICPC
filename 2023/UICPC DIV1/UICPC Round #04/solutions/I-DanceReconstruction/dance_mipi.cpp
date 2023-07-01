#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <cctype>
#include <cerrno>
#include <algorithm>
#include <list>
#include <queue>
#include <map>
#include <vector>
#include <cassert>

using namespace std;
    
#define REP(i,n) for(int _n=(n),i=0; i<_n; ++i)
#define FOR(i,a,b) for(int _b=(b),i=(a); i<=_b; ++i)
#define FORD(i,a,b) for(int _b=(b),i=(a); i>=_b; --i)
#define FORE(i,a)  for(VAR(i,a.begin()); i!=a.end(); ++i)

#define PB push_back
#define BEG begin()
#define END end()
#define SZ size()
#define MP make_pair
#define F first
#define S second
#define D double
#define LL long long
#define LD long double
#define VI vector<int>

vector<vector<vector<int> > > cycles;
vector<int> input;
vector<int> output;
int n;
LL K;

LL gcd(LL a,LL b){
	if (a<b) swap(a,b); 
        if (b==0) return a; else return gcd(b,a%b);
}

LL maxdiv(LL n,LL d){
	LL r=1;
	for(;;){
		int k=gcd(n,d);
		if (k==1) break;
		r*=k; n/=k;
	}
	return r;
}

/* Extended Euclid copied from the library */

LL NWDR(LL a, LL b, LL &xp, LL &yp) {
	if (a==0) { xp=0; yp=1; return b; }
	LL x,y;
	int d = NWDR(b%a, a, x, y);
	yp = x;
	xp = y-(b/a)*x;
	return d;
}

LL RevMod(LL a, LL p){
	LL x, y;
	NWDR(a, p, x, y);
	if (x < 0LL) return (p - ((-x) % (LL)p)) % p;
	return x % (LL)p;
}

/* ==== Main code starts ==== */

inline void create_cycles(){
	vector<int> vis;
	vector<int> v;	
	vis=vector<int>(n,0);
        REP(i,n) if (!vis[i]){
		int p=i,s=0;
		v.clear();
		while(!vis[p]){
			v.PB(p);
			vis[p]=1;
			s++;
			p=input[p];
		}
		cycles[s].PB(v);
        }
}

inline void do_reconstruction(int t, int q, int r){
	LL T=t*r;
	assert(t==(T/gcd(T,K)));
	assert(K%r==0);
	LL Kp=(K/r)%t;
	assert(gcd(Kp,t)==1);
	LL a=RevMod(Kp,t);
	REP(i,r) REP(j,t) {
		assert(output[cycles[t][q+i][j]]==-1);
		if (i<r-1)
			output[cycles[t][q+i][j]]=cycles[t][q+i+1][j];
		else
			output[cycles[t][q+i][j]]=cycles[t][q][(j+a)%t];
	}
}

int reconstruct_cycles(int t){
//	printf("==== %d ====\n",t);
	int s=cycles[t].size();
	if (s==0) return 0;

	if (t==1){
		LL d=gcd(K,cycles[t].size());
		// if (d==1) return 1;
		for(int i=0;i<s;i+=d) do_reconstruction(t,i,d);
		return 0;
	}

	LL d=gcd(K,(LL)t);
	LL r=maxdiv(K,d);
	if (s%r!=0) return 1;

	for(int i=0;i<s;i+=r) do_reconstruction(t,i,r);
	return 0;
}

void sanity_check(){
	REP(i,n){
		int p=i;
		REP(r,K){
			p=output[p];
		}
		assert(p==input[i]);
	}
}

int main(){
	scanf("%d%lld",&n,&K);
        cycles=vector<vector<vector<int> > >(n+1,vector<vector<int> >());
	REP(i,n){
		int a;
		scanf("%d",&a); a--;
		input.PB(a);
	}
	create_cycles();
/*	printf("%d %lld\n",n,K);
	FOR(t,1,n){
		printf("%d: ",t);
		REP(j,cycles[t].size()){
			printf("(");
			REP(i,cycles[t][j].size()) printf(" %d",cycles[t][j][i]);
			printf(" ) ");
		}
		printf("\n");
	}
	printf("TUTAJ\n");*/
	output=vector<int>(n,-1);
//	printf("TUTAJ\n");
//	fflush(stdout);
	FOR(t,1,n){
		if (reconstruct_cycles(t)) goto hell;
	}
//	sanity_check();
	REP(i,n){
		if (i) printf(" "); printf("%d",output[i]+1);
	}
	printf("\n");
	return 0;
hell:
	printf("Impossible\n");
	return 0;
}

