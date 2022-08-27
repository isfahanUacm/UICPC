// ayy
// ' lamo
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld; //CARE
typedef complex<ld> pt;
#define fi first
#define se second
#define pb push_back
const ld eps=1e-8;
const int inf=1e9+99;
const ll linf=1e18+99;
// const int P=1e9+7;



// should bound count_{m,n}, N_m

int powq(int x,int e,int P) {
	if(!e) return 1;
	if(e&1) return int(1LL*powq(x,e-1,P)*x%P);
	x=powq(x,e>>1,P);
	return int(1LL*x*x%P);
}
pair<bool,vector<vector<int> > > prime_REF(vector<vector<int> > A,int P) {
	int m=(int)A.size(); assert(m);
	int n=(int)A[0].size(); assert(n);
	int r=0;
	for(int i=0;i<n;i++) { // pivot col
		if(r==m) return {r==n-1,A};
		for(int j=r;j<m;j++) if(A[i][j]) {
			if(j!=r) swap(A[j],A[r]);
			goto pivot;
		}
		return {r==n-1,A};
		pivot:;
		int f=powq(A[r][i],P-2,P);
		for(int k=0;k<n;k++) A[r][k]=int(1LL*A[r][k]*f%P);
		assert(A[r][i]==1);
		for(int j=r+1;j<m;j++) {
			f=A[j][i];
			for(int k=0;k<n;k++) A[j][k]=int(A[j][k]-1LL*A[r][k]*f%P);
			for(int k=0;k<n;k++) if(A[j][k]<0) A[j][k]+=P;
		}
		++r;
	}
	return {0,A}; // should have been unable to pivot by now
}







int32_t main() {
	vector<map<string,int> > molecules;
	vector<string> elts;
	for(;;) {
		int sgn; cin>>sgn;
		if(!sgn) {
			assert(cin>>sgn);
			assert(!(cin>>sgn));
			break;
		}
		assert(abs(sgn)==1);

		int N; cin>>N; // todo should bound N itself.
		map<string,int> molecule;
		for(;N--;) {
			string elt; int cnt; cin>>elt>>cnt;
			// todo should specify elementt is latin letters
			// todo should bound cnt
			assert(elt.size()<=2u);
			assert(1<=cnt && cnt<=12);
			molecule[elt] += sgn*cnt;
			elts.pb(elt);
		}
		molecules.pb(molecule);
	}
	sort(elts.begin(),elts.end());
	elts.resize(unique(elts.begin(),elts.end())-elts.begin());
	int m=(int)elts.size();
	int n=(int)molecules.size();
	assert(n<=10);
	vector<vector<int> > A(m,vector<int>(n,0));
	for(int j=0;j<n;j++) {
		for(const auto &P:molecules[j]) {
			int i=int(lower_bound(elts.begin(),elts.end(),P.fi)-elts.begin());
			A[i][j] += P.se;
		}
	}

	// for(int i=0;i<m;i++) for(int j=0;j<n;j++)
	// 	printf("%d%c",A[i][j],"\t\n"[j==n-1]);
	int P=1e9+7;
	if(!prime_REF(A,P).fi) P+=2, cerr<<"warning: failed one prime"<<endl;
	assert(prime_REF(A,P).fi);
	auto B=prime_REF(A,P).se;

	// for(int i=0;i<m;i++) for(int j=0;j<n;j++)
	// 	printf("%d%c",B[i][j],"\t\n"[j==n-1]);

	vector<int> Z;
	for(int cm=1;cm<=1000;cm++) {
		vector<int> c(n,0);
		c.back()=cm;
		for(int i=n-2;i>=0;i--) {
			for(int j=0;j<i;j++) assert(!B[i][j]);
			assert(B[i][i]==1);
			for(int j=i+1;j<n;j++) c[i]=int((c[i]+P-1LL*B[i][j]*c[j]%P)%P);
		}
		bool good=1;
		for(int x:c) if(x<0 || x>1000) good=0;
		if(!good) continue;

		for(int i=0;i<m;i++) {
			int entry=0;
			for(int j=0;j<n;j++) entry += c[j]*A[i][j];
			if(entry) good=0;
		}
		if(!good) continue;
		if(Z.size()) {
			int f=c[0]/Z[0];
			for(int i=0;i<n;i++) assert(Z[i]*f==c[i]);
			continue;
		}
		Z=c;
	}
	assert((int)Z.size()==n);
	for(int i=0;i<n;i++) cout<<Z[i]<<" \n"[i==n-1];
}











