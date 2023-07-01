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
#define eps 1e-8

priority_queue<pair<LD,int> > heap;
LD mn=100000000.0;
vector<LD> in;
LD T;

int main(){
	int n;
	scanf("%Lf%d",&T,&n);
	VI h=VI(n,1);
	REP(i,n){
		int r;
		scanf("%d",&r);
		heap.push(MP((LD)r,i));
		in.PB((LD)r);
		if (r<mn) mn=r;
	}
	int c=0;
	for(;;){
		pair<LD,int> cur=heap.top();
		if ((mn/cur.F)>=T) break;
		heap.pop();
		c++;
		h[cur.S]++; int nw=in[cur.S]/h[cur.S];
		if (mn>nw) mn=nw;
		heap.push(MP(nw,cur.S));
	}
	printf("%d\n",c);
	return 0;
}

