#include <bits/stdc++.h>
using namespace std;

#define ll long long

int const maxI = 1e5*2;

int arr[7];
void solve(){
 int n;
 cin >> n;
 for(int i=0; i<n; i++){
     string s;
     cin >> s;
     switch (s[0]) {
     case 'r':
         arr[0]++;
         break;
     case 'y':
         arr[1]++;
         break;
     case 'g':
         arr[2]++;
         break;
     case 'p':
         arr[5]++;
         break;
     case 'b' :
     {
         if(s == "brown")
             arr[3]++;
         else if(s== "blue")
             arr[4]++;
         else if(s == "black")
             arr[6]++;
         break;
     }
     default:
         break;
     }
 }

 int sum = 0;
    bool f = true;
    for(int i =6; i>=0; i--){
        if(arr[i] > 0 && f && i>0){
            sum = (i+2)*arr[0];
            sum += arr[i]*(i+1);
            arr[0] = 0;
            f = false;
        }
        else if(i==0 && sum==0)
            sum = 1;
        else
            sum += arr[i]*(i+1);
    }
    cout << sum << '\n';
 return;
}

int main()
{
    solve();
    return 0;
}
