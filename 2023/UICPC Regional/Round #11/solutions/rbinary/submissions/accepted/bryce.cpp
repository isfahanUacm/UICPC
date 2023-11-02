// Brute force with memoization and pruning solution to redundant binary
// notation. The idea is in a given digit position, we try all of {0, 1, ... t} and
// recurse on the remaining number in the remaining digits. While the program
// can branch, since we must get to a representation of the same number, you
// can actually show that in the set of all prefixes of a given length,
// at most t of differing value can be a valid prefix of a redundant binary
// representation of N. Thus, while the total number of representations grows
// exponentially, the number of unique function calls to solve
// given below is extremely small; at most t * 55.

#include <iostream>
#include <map>
#include <vector>

#define M 998244353LL

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;

map<ii, ll> memo;
ll t;

ll solve(ll number, ll digits) {
    if (number < 0)
        return 0;
    if (t*((1LL << digits) - 1) < number) {
        return 0;
    }
    if (number == 0 && digits == 0) {
        return 1;
    }
    if (memo.count(ii(number, digits))) {
        return memo[ii(number, digits)];
    }

    ll ans = 0;
    for (ll i = 0; i <= t; ++i) {
        ans += solve(number - i*(1LL << (digits-1)), digits-1);
        ans = (ans % M);
    }

    memo[ii(number, digits)] = ans;
    return ans;
}

int main() {
    ll N;
    cin >> N >> t;
    cout << solve(N, 55) << endl;
}
