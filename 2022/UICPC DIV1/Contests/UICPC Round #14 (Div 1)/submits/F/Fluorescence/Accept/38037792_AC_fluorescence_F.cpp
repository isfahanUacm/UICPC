#include <iostream>
using namespace std;
#include "string"
#include "queue"
#include "algorithm"
#include "vector"
#define pii pair<int,int>
#define ld long double

int n;

int main() {
    string a, b; cin >> a >> b;
    n = a.size();

    int f=-1, l=-1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            if(f == -1) f = i;
            l = i;
        }
        
    }
    
    if (f == l) // no match
    {
        cout << 0;
        return 0;
    }
    
    int size = l-f+1 ;
    string x, y;
    x = a.substr(f, size);
    y = b.substr(f, size);
    for (int i = 0; i < size; i++)
    {
        if(x[i] != y[size-i-1]){
            cout << 0;
            return 0;
        }
    }

    f--;
    l++;
    int ans = 1;
    while (f>=0 && l<n)
    {
        if((a[f] == a[l]) && (b[f] == b[l])){
            ans++;
        }
        else {
            break;
        }
        f--;
        l++;
    }
    cout << ans; 
    
}