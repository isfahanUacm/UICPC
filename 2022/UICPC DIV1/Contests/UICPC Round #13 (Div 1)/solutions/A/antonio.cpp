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
const int P=1e9+7;




template<class CIt,class It,class Cmp,class Alloc>
struct custom_node_update {
public:
	typedef int metadata_type;
	int Qh(CIt it,int y) {
		if(it==node_end()) return 0;
		int ltot=(it.get_l_child()==node_end() ? 0 : it.get_l_child().get_metadata());
		int mtot=(*it)->se-(*it)->fi;
		if(y>=(*it)->se) return ltot+mtot+Qh(it.get_r_child(),y);
		if(y>=(*it)->fi) return ltot+y-(*it)->fi;
		return Qh(it.get_l_child(),y);
	}
	int Q(int y) {
		return Qh(node_begin(),y);
	}
	inline void operator()(It it,CIt end_it) {
		It LC=it.get_l_child(), RC=it.get_r_child();
		auto &md=it.get_metadata();
		const_cast<metadata_type&>(md)=(*it)->se-(*it)->fi;
		if(LC!=end_it) const_cast<metadata_type&>(md) += LC.get_metadata();
		if(RC!=end_it) const_cast<metadata_type&>(md) += RC.get_metadata();
	}
	virtual CIt node_begin() const = 0;
	virtual CIt node_end() const = 0;
	virtual ~custom_node_update() {}
};
tree<
	pair<int,int>,
	null_type,
	less<pair<int,int> >,
	rb_tree_tag,
	custom_node_update
> ints;




int32_t main() {
	int n; scanf("%d",&n);
	vector<pair<int,int> > vv;
	for(int i=0;i<n;i++) {
		int t,h; scanf("%d%d",&t,&h);
		vv.pb({t,h});
	}
	sort(vv.begin(),vv.end());
	ints.insert({0,inf});
	int Z=0;
	for(const auto &P:vv) {
		int avail=ints.Q(P.se);
		if(avail<P.fi) continue;
		++Z;
		int used=P.fi;
		for(;used;) {
			auto it=ints.lower_bound({P.se,-1});
			assert(it!=ints.begin());
			--it;
			if(it->se>P.se) {
				int L=it->fi;
				int R=it->se;
				ints.erase({L,R});
				ints.insert({L,P.se});
				ints.insert({P.se,R});
				continue;
			}
			if(it->se-it->fi > used) {
				int L=it->fi;
				int R=it->se;
				ints.erase({L,R});
				ints.insert({L,R-used});
				used=0;
				continue;
			}
			used-=it->se-it->fi;
			ints.erase(it);
		}
	}
	printf("%d\n",Z);
}











