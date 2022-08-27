#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
string ring = "ABCDEFGHIJKLMNOPQRSTUVWXYZ '";
int main(){
    double d = 60;
    double c = M_PI*d;
    double each = c/28;
    map<char, int> m;
    for (int i = 0; i < 28; i++)
    {
        m[ring[i]] = i+1;
    }
    
    // min(abs(''-''),28-abs(''-''));
    int N;
    cin>>N;
    string s;
    getline(cin, s);
    for (int i = 0; i < N; i++){
        double total = 0;
        getline(cin, s);
        char pre = s[0];
        for (int j = 1; j < s.size(); j++)
        {
            
            int dist = min(abs(m[pre]-m[s[j]]), 28-abs(m[pre]-m[s[j]]));
            double sec = (dist*each)/15;
            total += sec;
            pre = s[j];
        }
        cout<<fixed<<setprecision(10)<<total+s.size()<<endl;
    }
    
}