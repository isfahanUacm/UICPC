#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

typedef long long int ll;
typedef vector<ll> vector_ll;
typedef vector<string> vector_string;
typedef vector<char> vector_char;
typedef vector<bool> vector_bool;

#define find_vec(vec, item, first_index, last_index) find(vec.begin()+first_index, vec.begin()+last_index+1, item) != vec.end()
#define destroy_vec(vec) vec.~vector()
#define erace_item_vec(vec, index) vec.erase(vec.begin() + index)
#define erace_range_vec(vec, first_index, last_index) vec.erase(vec.begin() + indexS, vec.end() - indexE)
#define max_vec(vec, first_index, last_index) *max_element(vec.begin()+first_index, vec.begin()+last_index+1)
#define min_vec(vec, first_index, last_index) *min_element(vec.begin()+first_index, vec.begin()+last_index+1)
#define sum_vec(vec, first_index, last_index) accumulate(vec.begin()+first_index, vec.begin()+last_index+1, 0)

string cS(string s, int n)
{
	string f = "";
	for (int i = 0; i < n; i++) f += s;
	return f;
}

int main()
{
	ll t;
	cin >> t;

	while (t--)
	{
		ll n, m;
		cin >> n >> m;

		vector<pair<ll, ll>> a;
		for (int i = 0; i < m; i++)
		{
			ll r, w;
			cin >> r >> w;
			a.push_back(make_pair(r, w));
		}
		
		ll mR = -1, mW = -1;
		for (int i = 0; i < m; i++)
		{
			if (mR < a[i].first) mR = a[i].first;
			if (mW < a[i].second) mW = a[i].second;
		}

		if (mR + mW > n) cout << "IMPOSSIBLE";
		else cout << cS("R", mR) + cS("W", mW);
		cout << endl;
	}
}