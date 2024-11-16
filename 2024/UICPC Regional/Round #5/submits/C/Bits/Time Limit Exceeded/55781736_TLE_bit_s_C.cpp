#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, q; cin >> n >> q;
    vector<int> v;
    for(int i=0; i<n; i++)
    {
        int x; cin >> x;
        v.push_back(x);
    }

    int ind = 0;
    for(int c =0; c<q; c++)
    {
        int k; cin >> k;

        ind = 0;
        for(int i=0; i<n; i++)
        {
            if(ind > k-1)
                break;

            if(v[i] == -1)
            {
                continue;
            }

            if(!(ind&1))
            {
                v[i] = -1;
            }

            ind ++;
        }



        vector<int> tmp;
        ind = 0;
        for(int i=0; i<n; i++)
        {
            if(ind>=k/2)
                break;
            if(v[i] == -1)
                continue;

            tmp.push_back(v[i]);
            ind++;
        }
        for(int i=0; i<tmp.size()/2; i++)
        {
            int a = tmp[i];
            tmp[i] = tmp[tmp.size()-i-1];
            tmp[tmp.size()-i-1] = a;
        }

        int tmp_index = 0;
        ind = 0;
        for(int i=0; i<n; i++)
        {
            if(ind>=k/2)
                break;
            if(v[i] == -1)
                continue;

//            cout << v[i] << "   " << tmp[tmp_index] << endl;
            v[i] = tmp[tmp_index];
            tmp_index ++;
            ind++;
        }
//        for(auto x : v)
//            cout << x << " ";
//        cout << "\n===============\n";

    }
    for(auto x : v)
    {
        if(x == -1)
            continue;
        cout << x << " ";
    }
}


int main()
{
    int x; cin >> x;
    for(int i=0; i<x; i++)
        solve();
    return 0;
}