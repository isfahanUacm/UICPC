#include <iostream>
using namespace std;

int main() {
    int n,k,x,sum,o = 0;
    bool ok = false;
    int min = 0;
    cin>>n>>k;
    sum = k;
    while(--n){
        cin>>x;
        if(x >= 0){
            sum += x;
            ok = true;
        } else{
            o += 1;
            if(o == 1)
                min = x;
            else{
                if(x > min)
                    min = x;
            }
        }
    }
    if(!ok){
        if(abs(min) <= k)
            cout<< k + min;
        else
            cout << -1;
    } else
        cout<<sum;
    return 0;
}