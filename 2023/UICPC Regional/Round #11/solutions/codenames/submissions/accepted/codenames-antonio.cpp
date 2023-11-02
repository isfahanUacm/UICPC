#include <vector>
#include <iostream>
#include <iomanip>
#include <cassert>
using namespace std;
#define sz(a) int((a).size())
#define pb push_back
// using flt=long double;
using flt=double;

const int N=15;
int n;
int asses=0;
int agents[2];
vector<int> clues;

flt solve(int,int);
flt f(int mk,int t,int ci,int k) {
	if(!k) return 1-solve(mk,1-t);
	static flt dp[2][1<<N][50][N];
	static bool seen[2][1<<N][50][N];
	bool &sn=seen[t][mk][ci][k];
	flt &ans=dp[t][mk][ci][k];
	if(sn) return ans;
	sn=1;
	ans=0;

	int den=0;
	unsigned cc=clues[ci]&~mk;
	for(unsigned y=cc;y;y=y&(y-1)) {
		unsigned x=y&(-y);
		// dbg(mk,clues[ci],cc,x);
		++den;
		if(asses&x) continue;
		int nmk=mk|x;
		if((nmk&agents[t])==agents[t]) { ans+=1; continue; }
		if((nmk&agents[1-t])==agents[1-t]) continue;
		if(x&agents[t]) ans+=f(nmk,t,ci,k-1);
		else ans+=1-solve(nmk,1-t);
	}
	ans/=den;
	// dbg(mk,t,ci,cc,k,ans,den);
	return ans;
}
flt solve(int mk,int t) {
	static flt dp[2][1<<N];
	static bool seen[2][1<<N];
	bool &sn=seen[t][mk];
	flt &ans=dp[t][mk];
	if(sn) return ans;
	sn=1;
	ans=0;
	for(int i=0;i<sz(clues);i++) for(int k=__builtin_popcount(clues[i]&~mk);k>0;k--) ans=max(ans,f(mk,t,i,k));
	// dbg(mk,t,ans);
	return ans;
}




int main() { /* CURSOR START */
	string _us; cin>>n>>_us;
	assert(1<=n && n<=15);
	int us=0;
	if(_us=="B") us=1;
	else assert(_us=="R");

	static string lex[N]; for(int i=0;i<n;i++) cin>>lex[i];
	for(int i=0;i<n;i++) for(int j=0;j<i;j++) assert(lex[i]!=lex[j]);
	for(int i=0;i<n;i++) {
		string typ; cin>>typ;
		if(typ=="A") asses|=1<<i;
		else if(typ=="B") agents[1]|=1<<i;
		else if(typ=="R") agents[0]|=1<<i;
		else assert(typ=="I");
	}
	assert(agents[0]);
	assert(agents[1]);

	int m; cin>>m;
	int sn=0;
	assert(1<=m && m<=50);
	for(;m--;) {
		int msk=0;
		int h; cin>>h;
		assert(1<=h && h<=n);
		for(;h--;) {
			string w; cin>>w;
			for(int i=0;i<n;i++) if(lex[i]==w) { assert(!(msk&1<<i)); msk|=1<<i; goto yup; }
			assert(0);
		yup:;
		}
		sn|=msk;
		clues.pb(msk);
	}
	assert(sn+1==(1<<n));

	cout<<fixed<<setprecision(19)<<solve(0,us)<<endl;
}
