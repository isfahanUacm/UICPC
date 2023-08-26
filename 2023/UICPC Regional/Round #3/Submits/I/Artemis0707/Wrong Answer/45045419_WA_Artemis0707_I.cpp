#include<bits/stdc++.h>
using namespace std;
using ll =long long;

int main() {
    int t;
    cin >> t;
    while(t--){
        ll n;
        string cm ,s;
        cin>>s;
        cin>>n;
        cin>>cm;
        list<ll> ls;
        cm = cm.substr(1, cm.size() - 2);
        stringstream ss(cm);
        string token;

        while (getline(ss, token, ',')) {
            ll num = stoi(token);
            ls.push_back(num);
        }
        bool frnt = 1;
        bool error =0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='R') frnt = !frnt;
            else if(s[i]=='D'){
                if(ls.size()==0){
                    error = 1;
                    break;
                }
                if(frnt) ls.pop_front();
                else ls.pop_back();
            }
        }
        if(error) cout<<"error"<<endl;
        else{
            cout<<'[';
            ll cnt =0;
            if(!frnt)  reverse(ls.begin(), ls.end());
            for (list<ll>::iterator it = ls.begin(); it != ls.end(); ++it) {
                cout << *it <<',';
                cnt++;
                if(cnt==ls.size()-1) break;
            }
            if(ls.size()!=0)
                cout<<ls.back();
            cout<<']'<<endl;
        }

    }

    return 0;
}
