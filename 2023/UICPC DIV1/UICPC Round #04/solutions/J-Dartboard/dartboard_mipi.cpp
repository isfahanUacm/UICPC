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

const LD pi=(LD)2.0*acosl(0);

LD sigma;
LD sigma2q;

LD Phi(LD a,LD b){
	return expl(-(a*a)/sigma2q)-expl(-(b*b)/sigma2q);
}

LD input[6];

int main(){
	REP(t,6) scanf("%Lf",&input[t]);
	scanf("%Lf",&sigma);
	sigma2q=sigma*sigma*(LD)2.0;

	LD ret=0.0;

	ret+=(LD)50.0*Phi(0.0,input[0]);

	ret+=(LD)25.0*Phi(input[0],input[1]);

	ret+=(LD)10.5*Phi(input[1],input[2]);

	ret+=(LD)31.5*Phi(input[2],input[3]);

	ret+=(LD)10.5*Phi(input[3],input[4]);

	ret+=(LD)21.0*Phi(input[4],input[5]);

	printf("%.10Lf\n",ret);

	return 0;
}
