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

int main(){
	int n;
	scanf("%d",&n);
	VI p;
	REP(i,n){
		int a;
		scanf("%d",&a);
		p.PB(a);
	}
	sort(p.begin(),p.end());
	reverse(p.begin(),p.end());
	int b=-1,k;
	REP(i,n) if (b<(k=p[i]+i+2)) b=k;
	printf("%d\n",b);
	return 0;
}
