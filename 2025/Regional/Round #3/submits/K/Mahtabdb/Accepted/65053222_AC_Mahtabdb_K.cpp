
#include <iostream>
using namespace std;
int main()
{
  int c,n;
  cin >> c>>n;
  if (n<c){
      cout << "0";
     
  }
  if (n>c){
      cout << c+1;
     
  }
  if (n==c){
      cout << n;
  }
 
    return 0;
}