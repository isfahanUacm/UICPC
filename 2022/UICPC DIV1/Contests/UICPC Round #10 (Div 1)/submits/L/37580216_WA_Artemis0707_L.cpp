#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll bs[30][360];
ll visited[30][360];
bool ok = false;
pair<ll,ll> mov[] = {{0,1},{1,0},{-1,0},{0,-1}};
bool inr(ll r){
	return r>=0 && r<30;
}
void dfs (ll r, ll d){
	visited[r][d] = 1;
	if(r>20){
		ok = true;
		return;
	}
	for(auto m:mov){
		ll vx = r + m.first;
		ll vy = (d + m.second+360)%360;
		if(inr(vx) && (visited[vx][vy]==0) && (bs[vx][vy]==0)){
			dfs(vx,vy);
			if(ok)return;
		}
	}

}
int main(){
	ll t;
	cin >> t;
	while(t--){
		ok = false;
		for(ll i=0; i<30;i++){
			for(ll j=0;j<360;j++){
				bs[i][j] = 0;
				visited[i][j] = 0;
			}
		}
		ll n;
		cin >> n;
		for(ll i=0;i<n;i++){
			char w;
			cin >> w;
			if(w=='C'){
				ll r,x,y; cin >> r >> x >> y;
				r--;
				for(ll j=x;j!=y;j = ((j+1)%360)){
					bs[r][j] = 1;
				}
			}
			else{
				ll r1,r2,x;
				cin >> r1 >> r2 >> x;
				r1--;r2--;
				for(ll j=r1;j<=r2;j++){
					bs[j][x] = 1;
				}
			}
		}
		for(ll i=0;i<360;i++){
			if(visited[0][i]==0){
				dfs(0,i);
				if(ok)break;
			}
		}
		cout<<(ok ? "YES":"NO")<<endl;

	}	
	return 0;
}