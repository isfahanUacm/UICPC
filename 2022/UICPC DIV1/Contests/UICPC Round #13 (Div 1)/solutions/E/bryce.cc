#include <iostream>
#include <vector>

#define INF 1000000000000000000LL

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

int main() {
    ll N, K, S;
    cin >> N >> K >> S;

    vi A(N);
    for (ll i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vvi ic(K, vi(S+1, 0));
    for (ll i = 0; i < K; ++i) {
        for (ll j = 0; j <= S; ++j) {
            for (ll k = i; k < N; k += K) {
                if (A[k] != j) ++ic[i][j];
            }
        }
    }

    vvi interesting(K);
    for (ll i = 0; i < K; ++i) {
        for (ll k = i; k < N; k += K) {
            interesting[i].push_back(A[k]);
        }
    }

    vvi DP(K, vi(S+1, INF));

    for (ll j = 0; j <= S; ++j) {
        DP[K-1][j] = ic[K-1][j];
    }
    
    vvi best(K, vi(S+1, INF));
    best[K-1][0] = DP[K-1][0];
    for (ll j = 1; j <= S; ++j) {
        best[K-1][j] = min(best[K-1][j-1], DP[K-1][j]);
    }

    for (ll i = K-2; i >= 0; --i) {
        for (ll j = 0; j <= S; ++j) {
            // uninteresting
            DP[i][j] = min(DP[i][j], best[i+1][j] + (N-i+K-1)/K);
            // interesting
            for (ll k = 0; k < interesting[i].size(); ++k) {
                ll v = interesting[i][k];
                if (j-v >= 0) {
                    DP[i][j] = min(DP[i][j], DP[i+1][j-v] + ic[i][v]);
                }
            }   
        }

        best[i][0] = DP[i][0];
        for (ll j = 1; j <= S; ++j) {
            best[i][j] = min(best[i][j-1], DP[i][j]);
        }
    }

    cout << DP[0][S] << endl;
}
