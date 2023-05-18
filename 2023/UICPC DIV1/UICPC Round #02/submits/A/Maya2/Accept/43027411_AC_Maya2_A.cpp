#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n, m, d, o = 0;
   cin >> n >> m;
for( int i = 0; i < n; i++) {
      
cin >> d;
   if( m - d >= 0 ) {
       m -= d;
      o ++;
}
else break;
}
cout << o;
}
   




