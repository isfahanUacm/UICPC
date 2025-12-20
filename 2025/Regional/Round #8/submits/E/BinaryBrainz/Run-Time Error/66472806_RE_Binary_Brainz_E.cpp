// #include <iostream>
// #include <map>
// #include <set>
// #include <vector>
// #include <stack>
// #include <algorithm>
// #include <iomanip>
// #include <unordered_set>
// #include <unordered_map>
// #include <list>
// #include <numeric>
// #include <queue>
// #include <cmath>
// #include <functional>
// #include <sstream>
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;

#define veci vector<int>
#define vecl vector<ll>
#define vecp vector<pair<int, int>>

#define ilp(s,f) for(ll i = s; i < f; i++)
#define jlp(s,f) for(ll j = s; j < f; j++)
#define klp(s,f) for(ll k = s; k < f; k++)
#define rlp(s,f) for(ll r = s; r >= f; r--)
#define getvec(n,v) ilp(0,n)cin >> v[i];
#define getpvec(n,v)ilp(0,n)cin >> v[i].first >> v[i].second;
#define nextl(q) if (q) cout << endl;

#define INF 9223372036854775807
#define MOD 1000000007

template<class T> bool ckmin(T& a, const T& b){ return a > b ? a = b,true : false; }
template<class T> bool ckmax(T& a, const T& b){ return a < b ? a = b,true : false; }

template <typename T>
void prefixSum(const vector<T>& arr, vector<T>& sum) {
    sum = vector<T>(arr.size() + 1);
    sum[0] = 0;

    for (int i = 0; i < arr.size(); i++) {
        sum[i + 1] = sum[i] + arr[i];
    }
}

void print128(__int128 x) {
    if (x == 0) {
        cout << 0;
        return;
    }
    string s;
    bool neg = false;
    if (x < 0) {
        neg = true;
        x = -x;
    }
    while (x > 0) {
        s += (x % 10) + '0';
        x /= 10;
    }
    if (neg) s += '-';
    reverse(s.begin(), s.end());
    cout << s;
}

template <typename T>
void print(vector<T> v) {
    ilp(0,v.size()) {
        cout << v[i] << ' ';
    }
}

// lower_bound(a) : first >= a
// upper_bound(a) : first > a

/*  DO NOT QUIT  */


ll mpow(const ll num, const ll p) {

    if (p == 0) return 1;
    if (p == 1) return num;

    if (p % 2) {
        return (num % MOD) * (mpow(num, p - 1) % MOD);
    }
    else {
        ll tmp = mpow(num, p / 2) % MOD;
        return tmp  * tmp;
    }
}


void solve() {


    int n,m;
    cin >> n >> m;

    while(n != 0 && m != 0){

        vector<string> g(n);
        ilp(0,n) {
            cin >> g[i];
        }
        int lst = g[0][0];
        int cnt = 0;
        int st = 0;
        int len = -1;
        ilp(1,n) {
            if (g[i][0] == lst) {
                cnt++;
            }
            else {
                if (st != 0) {
                    len = cnt;
                    break;
                }

                st = i;
                lst = g[i][0];
                cnt = 1;
            }
        }

        if (len == -1) {
            lst = g[0][0];
            cnt = 0;
            st = 0;

            jlp(1,m) {
                if (g[0][j] == lst) {
                    cnt++;
                }
                else {
                    if (st != 0) {
                        len = cnt;
                        break;
                    }

                    st = j;
                    lst = g[0][j];
                    cnt = 1;
                }
            }
        }

        if (len == -1) {

            bool cant = false;

            lst = g[0][0];
            cnt = 0;
            ilp(1,n) {
                if (g[i][0] != lst) {
                    break;
                }
                cnt++;
            }
            ilp(0,n) {
                int tcnt = 0;
                lst = g[i][0];
                jlp(0,m) {
                    if (g[i][j] != lst) {
                        if (tcnt != cnt) {
                            cant = true;
                            break;
                        }
                    }
                }
                if (cant)break;
            }
            if (!cant) {
                lst = g[0][0];
                cnt = 0;
                jlp(1,m) {
                    if (g[0][j] != lst) {
                        break;
                    }
                    cnt++;
                }
                jlp(0,m) {
                    int tcnt = 0;
                    lst = g[0][j];
                    ilp(0,m) {
                        if (g[i][j] != lst) {
                            if (tcnt != cnt) {
                                cant = true;
                                break;
                            }
                        }
                    }
                    if (cant)break;
                }
            }

            if (cant) {
                cout << -1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }
        else {
            bool cant = false;

            ilp(0,n) {

                lst = g[i][0];
                cnt = 1;
                st = 0;

                jlp(1,m) {
                    if (lst == g[i][j]) {
                        cnt++;
                    }
                    else {
                        if (cnt > len|| (st != 0 && cnt != len)) {
                            cant = true;
                            break;
                        }

                        lst = g[i][j];
                        cnt = 1;
                        st = j;
                    }
                }

                if (cnt > len)
                    cant = true;
                if (cant) break;
            }


            if (!cant) {
                jlp(0,m) {

                    lst = g[0][j];
                    cnt = 1;
                    st = 0;

                    ilp(1,n) {
                        if (lst == g[i][j]) {
                            cnt++;
                        }
                        else {
                            if (cnt > len || (st != 0 && cnt != len)) {
                                cant = true;
                                break;
                            }

                            lst = g[i][j];
                            cnt = 1;
                            st = i;
                        }
                    }
                    if (cnt > len)
                        cant = true;

                    if (cant) break;
                }
            }

            if (cant) {
                cout << -1 << '\n';
            }
            else {
                cout << len <<'\n';
            }
        }

        cin >> n >> m;
    }



}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.in","r",stdin);
    ll t = 1;
    //cin >> t;

    while (t--){

        solve();
        if (t) cout << '\n';
    }
    return 0;
}