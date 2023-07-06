#include<iostream>
#include<iomanip>

using namespace std;

int main(){
   int N;
   cin >> N;
   while(N--){
      int b; double p;
      cin >> b >> p;
      cout << fixed << setprecision(10) << (60*(b-1))/p << " " << 60*b/p << " "
           << (60*(b+1))/p << endl;
   }
   return 0;
}
