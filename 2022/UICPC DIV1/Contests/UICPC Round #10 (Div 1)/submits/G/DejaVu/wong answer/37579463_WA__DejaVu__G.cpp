#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <set>
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

int main()
{
	ll n, m;
	vector_ll a, b;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		ll temp;
		cin >> temp;
		a.push_back(temp);
	}

	for (int i = 0; i < m; i++)
	{
		ll temp;
		cin >> temp;
		b.push_back(temp);
	}

	vector<pair<ll, ll>> f;

	for (int i = 0; i < n; i++)
	{
		f.push_back(make_pair(i * 100, a[i]));
	}
	for (int i = 0; i < m; i++)
	{
		f.push_back(make_pair(b[i], 0));
	}

	sort(f.begin(), f.end());

	ll max=0;
	vector<ll> g;
	for (int i = 0; i < n + m; i++)
	{
		if (f[i].second == 0)
		{
			g.push_back(max);
			max = 0;
		}
		else
		{
			max += f[i].second;
			if (i == n+m - 1) g.push_back(max);
		}
	}

	cout << *max_element(g.begin(), g.end());
}