#include <bits/stdc++.h>
using namespace std;

int main(){
  long long x,y; cin >> x >> y;

  long long ax,ay,bx,by;
  cin >> ax >> ay >> bx >> by;

  long long g = __gcd(x,y);
  long long X = x/g, Y = y/g;

  if(ax <= X && X <= bx && ay <= Y && Y <= by){
    long long k = min(bx/X, by/Y) + 1;
    X *= k;
    Y *= k;
  }
  
  if(X < x){
    assert(Y < y);
    cout << "No" << endl;
    cout << X << " " << Y << endl;
  } else {
    cout << "Yes" << endl;
  }
}
