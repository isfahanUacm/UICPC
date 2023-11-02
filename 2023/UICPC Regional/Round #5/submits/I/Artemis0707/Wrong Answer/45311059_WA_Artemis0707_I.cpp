#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, w , m;
    double s_speed,fer_speed,t1,t2,slen,spos;
    char dir;
    cin>>n>>w>>s_speed>>fer_speed>>t1>>t2;
    vector<double> times;
    map<double,int>entery;
    times.push_back(t1);
    times.push_back(t2);
    entery[t1] = 1, entery[t2] = 0;
    for(int i=0;i<n;i++){
         cin>>dir>>m;
         for(int j=0;j<m;j++){
            cin>>slen>>spos;
            // if(dir== 'E') 
            //  double entryTime = spos/s_speed +(i+1)*w/fer_speed;
            //  double exitTime = (spos+slen)/s_speed +i*w/fer_speed;
            if(dir== 'W') spos = -spos;
             double entryTime = -1.0 * (spos/s_speed +(i+1)*w/fer_speed);
             double exitTime = -1.0 *((spos-slen)/s_speed +i*w/fer_speed);
             times.push_back(entryTime);
             times.push_back(exitTime);
             entery[entryTime] = 1;
         }
    }
    sort(times.begin(),times.end());
    // for(auto x:times){
    //     cout<<x<<' ' <<entery[x]<<endl;
    // }
    int bother = -1;
    double  mx =0.0;
    for(int i=0;i<times.size();i++){
        if(entery[times[i]]==1)
            bother++;
        else bother--;
        // cout<<bother<<endl;
        if(bother ==0 && times[i]>=t1- 1e-9  && times[i]<=t2 +1e-9){
            mx = max(mx, times[i+1]-times[i]);
        }
    }
    printf("%.3lf\n", mx);
    return 0;
}