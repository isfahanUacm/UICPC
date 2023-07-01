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

LL X;

vector<LL> sols;

LL solve(LL y,LL A){
//	printf("%Ld %Ld %Ld\n",X,A,y);
	LL nom=(A*X-10000LL)*y;
	LL denom=(100000LL - X);
	if (nom%denom!=0) return -1;
	return nom/denom;
}

void gensols(){
	LL A=1;
	REP(i,8){
		FOR(y,1,9){
			LL x=solve(y,A);
			if (x<A/10LL || x>=A) continue;
			sols.PB(A*y+x);
		}
		A*=10LL;
	}
}

void input(){
	char buf[100];
	gets(buf);
	LL r1=0;
	int j;
	for(j=0;((buf[j]!=0)&&(buf[j]!='.'));j++)
		r1=r1*10LL+(buf[j]-'0');
	if (buf[j]=='.'){
		j++;
		int u=0;
		for(;buf[j]!=0;j++){
			r1=r1*10LL+(buf[j]-'0'); u++;
		}
		REP(m,4-u) r1=r1*10LL;
		X=r1;
	} else
		X=r1*10000LL;
}

int main(){
	input();
	if (X>=100000LL) {printf("No solution\n"); return 0;}
	gensols();
	if (sols.size()==0) printf("No solution\n"); else REP(i,sols.size()) printf("%Ld\n",sols[i]);
	return 0;
}
