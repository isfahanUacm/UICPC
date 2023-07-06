#include<iostream>

using namespace std;

int Fac[2];

int solve(int N){
   int pos = 0;
   while(N%2 == 0){
      N/=2;
      Fac[pos]++;
   }
   if(Fac[pos] != 0)
      pos++;
   for(long long i = 3; i*i <= N; i+=2){
      while(N%i == 0){
	 N/=i;
	 if(pos > 1)
	    return -1;
	 Fac[pos]++;
      }
      if(Fac[pos] != 0)
	 pos++;
   }
   if(N != 1 and pos > 1)
      return -1;
   if(N != 1){
      Fac[pos]++;
      pos++;
   }
   if(pos == 1)
      return Fac[0]%2;
   else if(pos == 2){
      if(Fac[0] == Fac[1])
	 return 0;
      if(Fac[0] + 1 == Fac[1] or Fac[0] == Fac[1] + 1)
	 return 1;
      return -1;
   }
}

int main(){
   int T;
   cin >> T;
   while(T--){
      Fac[0] = Fac[1] = 0;
      int N; string s;
      cin >> N >> s;
      int ans = solve(N);
      if(ans == 1)
	 cout << s;
      else if(ans == 0)
	 cout << (s == "Alice" ? "Bob" : "Alice");
      else
	 cout << "tie";
      cout << endl;
   }
   return 0;
}

