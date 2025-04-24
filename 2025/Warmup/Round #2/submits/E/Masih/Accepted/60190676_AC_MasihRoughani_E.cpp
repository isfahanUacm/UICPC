#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    const int ALPHA = 17;
    int Msk = 1<<ALPHA;

    vector<bool> club(Msk,false);
    for(int i=0;i<N;i++){
        string s; cin>>s;
        int m=0;
        for(char c:s) m |= 1<<(c-'a');
        club[m]=true;
    }
    vector<bool> cover = club;
    for(int b=0;b<ALPHA;b++){
        for(int mask=0;mask<Msk;mask++){
            if(mask&(1<<b))
                cover[mask] = cover[mask] | cover[mask^(1<<b)];
        }
    }

    string sched;
    cin >> sched;
    int M = sched.size();
    vector<array<int,ALPHA>> next_pos(M+1);
    for(int b=0;b<ALPHA;b++) next_pos[M][b]=M;
    for(int i=M-1;i>=0;i--){
        next_pos[i]=next_pos[i+1];
        next_pos[i][sched[i]-'a'] = i;
    }

    ll ans=0;
    vector<pair<int,int>> occ;
    occ.reserve(ALPHA);
    for(int l=0;l<M;l++){
        occ.clear();
        for(int b=0;b<ALPHA;b++){
            int p = next_pos[l][b];
            if(p<M) occ.emplace_back(p,b);
        }
        sort(occ.begin(), occ.end());
        int mask=0;
        for(auto &pr:occ){
            mask |= 1<<pr.second;
            if(cover[mask]){
                ans += (M - pr.first);
                break;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
