///In he nme of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll ;

int main()
{
    ios_base::sync_with_stdio(false) ;
    double n , m ;
    cin >> n >> m ;
    double answer = (n+1)/2 ;
    for(int i=1 ; i<m ; i++){
        answer += n ;
        answer /= 2 ;
    }
    cout << answer << '\n' ;
    return 0;
}
