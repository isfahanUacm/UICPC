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

#define MAX 200000

int main(){
	char b1[MAX], b2[MAX];
	gets(b1); gets(b2);
	int n1=strlen(b1),n2=strlen(b2);
	int mn,mx,p,r;
	for(mn=0;((mn<n1) && (mn<n2));mn++) if (b1[mn]!=b2[mn]) break;
        for(mx=0; ((mx<n1) && (mx<n2));mx++) if (b1[n1-1-mx]!=b2[n2-1-mx]) break;
	p=(mn+mx>n1)?n1:(mn+mx);
        if (p>=n2) r=0; else r=n2-p;
	printf("%d\n",r);

	return 0;
}
