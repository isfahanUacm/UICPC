#include<iostream>

using namespace std;

const int MAX = 1000000;

bool B[MAX];

int main(){
   int N;
   cin >> N;
   
   for(int i = 0; i < 1000; i++){
      if(i / 100 == 0) continue;
      int pal = i;
      int ii = i;
      for(int j = 0; j < 3; j++){
	 pal*= 10;
	 pal += ii%10;
	 ii /= 10;
      }
      //cerr << pal << endl;
      B[pal] = true;
   }
   
   while(N--){
      int in; cin >> in;
      int i=in, j=in;
      while(true){
	 if(B[i]){
	    cout << i << endl;
	    break;
	 }
	 if(B[j]){
	    cout << j << endl;
	    break;
	 }
	 if(i > 0)
	    i--;
	 if(j < MAX-1)
	    j++;
      }
   }
   return 0;
}
