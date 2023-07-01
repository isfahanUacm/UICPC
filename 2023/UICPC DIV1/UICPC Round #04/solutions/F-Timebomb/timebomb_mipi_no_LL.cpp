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
#include <cstring>

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

int rr[20];

void prep(){
rr[0]=32319;
rr[1]=31744;
rr[2]=24253;
rr[3]=32437;
rr[4]=31879;
rr[5]=30391;
rr[6]=30399;
rr[7]=31777;
rr[8]=32447;
rr[9]=32439;
}

char input[5][1000];

int nonempty(int y){
	REP(x,5) if (input[x][y]) return 1;
	return 0;
}

int mask(int y){
	int m=0;
	REP(dy,3) REP(x,5) if (input[x][y+dy]) m|=(1<<(5*dy+x));
	return m;
}

int main(){
	prep();
	int m,d,n,nn;
        int r;
	REP(x,5) gets(input[x]);
	REP(x,5) if ((strlen(input[x])+1)%4!=0) goto hell;
	nn=strlen(input[0]);
	n=(nn+1)/4;
	REP(x,5) REP(i,nn){
		if (input[x][i]==' ') input[x][i]=0; else 
		if (input[x][i]=='*') input[x][i]=1; else goto hell;
	}
	REP(y,n-1) if (nonempty(3+4*y)) goto hell;
	r=0;
	REP(y,n){
		m=mask(y*4);
		d=-1;
		REP(i,10) if (rr[i]==m) d=i;
		if (d<0) goto hell;
		r=r*10+d;
	}
	if (r%6!=0) goto hell;
	printf("BEER!!\n");
	return 0;
hell:
	printf("BOOM!!\n");
	return 0;
}

