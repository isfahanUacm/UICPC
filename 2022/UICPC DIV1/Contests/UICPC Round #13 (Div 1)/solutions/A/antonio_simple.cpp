// ayy
// ' lamo
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
const int inf=1e9+99;

int32_t main() {
	int n; scanf("%d",&n);
	vector<pair<int,int> > vv;
	for(int i=0;i<n;i++) {
		int t,h; scanf("%d%d",&t,&h);
		vv.pb({t,h});
	}
	sort(vv.begin(),vv.end());
	set<pair<int,int> > ints={{0,inf}};
	int Z=0;
	for(const auto &P:vv) {
		int t=P.fi;
		assert(t>0);
		for(;t>0;) {
			auto it=ints.lower_bound({P.se,-1});
			if(it==ints.begin()) break;
			--it;
			if(it->se>P.se) {
				int L=it->fi;
				int R=it->se;
				ints.erase({L,R});
				ints.insert({L,P.se});
				ints.insert({P.se,R});
				continue;
			}
			if(it->se-it->fi > t) {
				int L=it->fi;
				int R=it->se;
				ints.erase({L,R});
				ints.insert({L,R-t});
				t=0;
				continue;
			}
			t-=it->se-it->fi;
			ints.erase(it);
		}
		if(t>0) {
			ints.insert({P.se-P.fi+t,P.se});
			continue;
		}
		assert(t==0);
		++Z;
	}
	printf("%d\n",Z);
}
