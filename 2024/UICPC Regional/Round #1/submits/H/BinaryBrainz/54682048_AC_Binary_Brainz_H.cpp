#include <iostream>
#include <set>
using  namespace std;

int main() {
    set<long long int> heights;

    long long int n, *h , p , lg ,rg ,lst;
    cin >> n ;
    h = new long long int [n];
    for (int i = 0 ; i < n ;i++)
        cin >> h[i];

    lg = h[0];
    lst = lg;

    long int i = 1;
    bool done = false;

    while(i < n && !done){

        while(lst <= h[i]){
            lst = h[i];
            i++;
            if (i == n){
                done = true;
                break;
            }

        }
        p = lst;
        if (done ) {
            heights.insert(0);
            break;
        }
        lst = h[i];

        while(lst >= h[i]){
            lst = h[i];
            i++;

            if (i == n){
                done = true;
                break;
            }
        }
        rg = lst;


        heights.insert( min(p-rg , p -lg));
        lg = rg;
        if (done )
            break;
        lst = h[i];
    }

    cout << *heights.rbegin();

    return 0;
}
