// @EXPECTED_RESULTS@: CORRECT
#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
#include<cassert>
#include<iostream>
using namespace std;
typedef pair<int,int> p2;
const int MAX=100000;
const int INF=2000000000;
int T,m,n,a[MAX],b[MAX];
set<p2> used;
void use(int x){
	set<p2>::iterator it=used.lower_bound(p2(x,-1));
	p2 cur(x,x);
	if(it!=used.end()&&it->first==x+1){
		cur=p2(x,it->second);
		used.erase(it);
		it=used.lower_bound(p2(x,-1));	
	}
	if(it!=used.begin()){
		--it;
		if(it->second+1==x){
			cur.first=it->first;
			used.erase(it);
		}
	}
  used.insert(cur);
}
bool solve(){
	if(n>m)return false;
	vector<p2> t;
	for(int i=0;i<n;i++)if(a[i]<=b[i]){
		t.push_back(p2(b[i],a[i]));
		t.push_back(p2(m+b[i],m+a[i]));
	}else{
		t.push_back(p2(m+b[i],a[i]));
	}
	sort(t.begin(),t.end());
	used.clear();
	for(int i=0;i<t.size();i++){
		int x=t[i].second;
		set<p2>::iterator it=used.upper_bound(p2(x,INF));
		if(it!=used.begin()){
			--it;
			if(it->second>=x){
				x=it->second+1;
			}
		}
		//printf("%d,%d : %d\n",t[i].first,t[i].second,x);
		if(x>t[i].first)return false;
		use(x);
	}
	return true;
}
main(){
	cin>>T;
	assert(1<=T&&T<=100);
	while(T--){
		cin>>m>>n;
		assert(1<=m&&m<=1000000000);
		assert(1<=n&&n<=MAX);
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i];
			assert(0<=a[i]&&0<=b[i]&&a[i]<m&&b[i]<m);
		}
		cout<<(solve()?"YES":"NO")<<endl;
	}
}

