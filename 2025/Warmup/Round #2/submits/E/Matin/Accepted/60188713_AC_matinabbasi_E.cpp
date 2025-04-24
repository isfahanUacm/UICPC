#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;

	vector<int> v;

	for(int i=0; i<n; i++){
		string s;
		cin>>s;
		int k=0;
		for(auto x:s){
			k|=1<<(x-'a');
		}

		v.push_back(k);
	}

	vector<int> dp(1<<18,0);
	for(auto i:v) dp[i]=1;

	for(int mask=0; mask<1<<17; mask++){
		for(int j=0; j<17; j++){
			if(dp[mask & ~(1<<j)]) dp[mask]=1;
		}
	}

	string s;

	cin>>s;

	long long ans=0;
	vector<int> mp(20);
	int mask=0;
	long long l=0, r=0;

	while(r<=(long long)s.size()){
		if(dp[mask]){
		       int chr=s[l]-'a';
		       mp[chr]--;
		       if(mp[chr]==0) mask&=~(1<<(chr));

		       ans+=s.size()-r+1;
		       l++;
		}
		else{
			if(r==s.size()) break;
		        int chr=s[r]-'a';
			mask|=1<<chr;
			mp[chr]++;

			r++;


		}
	}
	cout<<ans<<endl;
}