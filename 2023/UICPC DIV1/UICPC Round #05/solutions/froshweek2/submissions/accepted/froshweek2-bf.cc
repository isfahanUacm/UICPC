#include<iostream>
#include<algorithm>

using namespace std;

const int MAX = 200010;

int t[MAX], l[MAX];

int main(){
   int n,m; cin >> n >> m;
   for(int i = 0; i < n; i++)
      cin >> t[i];
   for(int j = 0; j < m; j++)
      cin >> l[j];
   sort(t, t+n);
   sort(l, l+m);
   int tpos=0,lpos=0;
   int count = 0;
   while(tpos < n and lpos < m){
      if(t[tpos] <= l[lpos]){
	 //cerr << t[tpos] << " " << l[lpos] << endl;
	 count++;
	 tpos++;
	 lpos++;
      }
      else{
	 lpos++;
      }
   }
   cout << count << endl;
   return 0;
}
