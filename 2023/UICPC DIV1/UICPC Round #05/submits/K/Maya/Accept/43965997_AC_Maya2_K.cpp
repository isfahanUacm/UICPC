#include <bits/stdc++.h>
using namespace std;

// C++ program to print all prime factors
#include <bits/stdc++.h>
using namespace std;

int primeFactors(int n)
{
    int ans=0;
	while (n % 2 == 0)
	{
        ans++;
		n = n/2;
	}
	for (int i = 3; i <= sqrt(n); i = i + 2)
	{
		while (n % i == 0)
		{
            ans++;
			n = n/i;
		}
	}

	if (n > 2)
        ans++;
    return ans;
}

const int maxn = 2e5+9;
int t[maxn], l[maxn];

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int n, m; cin >> n >> m;

    for (int i = 0; i < n; ++i) cin >> t[i];
    for (int j = 0; j < m; ++j) cin >> l[j];

    sort(t, t+n, greater<int>());
    sort(l, l+m, greater<int>());


    int j = 0, ans=0;
    for (int i = 0; i < n; ++i) {
        if (t[i] <= l[j]) {
            ans++; j++;
            if (j >= m) break;
        } 
    }

    cout << ans;
    return 0;
}