#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
#define MAX_n 203
#define INF 1e6
int n, m, a, b; double c;
double matAdj[MAX_n][MAX_n];
string currencies[MAX_n], s1,s2, s3;
map<string, int> mp;
vector<string> v;


int main(){
    while(cin>>n){
        if(!n)
            break;
        for (int i = 0; i < n; i++)
        {
            cin>>currencies[i];
            mp[currencies[i]] = i;
        }
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matAdj[i][j]=INF;
            }
        }
        cin>>m;
        for (int i = 0; i < m; i++)
        {
            cin>>s1>>s2>>s3;
            a = mp[s1];b=mp[s2];
            auto it = s3.find(":");
            c = (1.0 * stoi(s3.substr(it+1, s3.length()-it-1)) / stoi(s3.substr(0, it))) ;
            matAdj[a][b] = -log(c);
        }
        for (int k = 0; k < n; k++)
        {    
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if(matAdj[i][k] != INF && matAdj[k][j]!=INF && matAdj[i][k]+matAdj[k][j] < matAdj[i][j]){
                        matAdj[i][j]=matAdj[i][k]+matAdj[k][j];
                    }
                }
            }
        }
        bool ans = false;
        for (int i = 0; i < n; i++)
        {
            if(matAdj[i][i]<0){
                ans = true;
                break;
            }
        }
        if(ans){
            cout<<"Arbitrage"<<endl;
        }
        else{
            cout<<"Ok"<<endl;
        }
    }
    
    return 0;
}
