#include <bits/stdc++.h>
using namespace std;
vector<int> fact = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };

int p(int r, int n)
{
    return fact[n] / (fact[r] * fact[n-r]);
}


int which_permu(int n)
{
    int otp = 0;
    string ns = to_string(n);
    while(next_permutation(ns.begin(), ns.end()))
        otp++;
    return otp;
}

long long pow(int a ,int b)
{
    int otp = 1;
    for(int i=0; i<b; i++)
        otp *= a;
    return otp;
}

void solve()
{
    int a = 1234;
    cin >> a;
    double otp = 0;
    int k = which_permu(a);
    int nf = to_string(a).size();
    nf = fact[nf];
    vector<double> v;
    v.push_back(0);
    double sum = 1;
    for(int i=0; i<=k; i++)
    {
        sum += v[i];
        v.push_back(sum/nf);
    }
    cout << setprecision(9) << fixed << v[k] << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

//    cout << p(0 , 1);
    int t; cin >> t;
    for(int i=0; i<t; i++)
        solve();
}
