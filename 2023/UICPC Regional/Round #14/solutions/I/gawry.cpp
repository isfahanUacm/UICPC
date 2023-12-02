// @EXPECTED_RESULTS@: CORRECT
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;
// how many ways to extend t to |p| chars so that there is a common substring of length >= r?
unsigned long long calc(string t,string p,int r,bool less=false){
	unsigned long long a[20][2]={},aa[20][2];
	a[0][0]=1;
	r=min(r,(int)p.size()+1);
	for(int i=0;i<p.size();i++){
		memset(aa,0,sizeof(a));
		for(int j=0;j<=r;j++)for(int k=0;k<2;k++)for(int z=0;z<10;z++)if(i>=t.size()||i+1<t.size()&&z==t[i]-'0'||i+1==t.size()&&(less&&z<t[i]-'0'||!less&&z==t[i]-'0')){
			int jj=min(r,z==p[i]-'0'?j+1:0),kk=k|jj>=r;
			aa[jj][kk]+=a[j][k];
		}
		memcpy(a,aa,sizeof(a));
	}
	unsigned long long ans=0;
	for(int i=0;i<=r;i++)ans+=a[i][1];
	//cout<<t<<" "<<p<<" "<<r<<" "<<ans<<endl;
	return ans;
}
int T,r;
unsigned long long M,Z;
main(){
	scanf("%d",&T);
	while(T--){
		scanf("%llu %llu %d",&M,&Z,&r);
		char buf[20];
		sprintf(buf,"%llu",Z);
		string p=buf;
		sprintf(buf,"%llu",M-1);
		int n=strlen(buf);
		unsigned long long ans=0;
		while(p.size()<n)p="0"+p;
		string t;
		for(int i=0;i<n;i++){
			t+=buf[i];
			ans+=calc(t,p,r,true);
		}
		ans+=calc(buf,p,r);
		printf("%llu\n",ans);
	}
}

