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

int main()
{
	ll t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;

		vector<pair<ll, ll>> a;

		for (int i = 0; i < n; i++)
		{
			ll temp1, temp2;
			cin >> temp1;
			cin >> temp2;
			a.push_back(make_pair(temp2, temp1));
		}

		sort(a.begin(), a.end());
		
		int statue = 1;
		ll sum = 0;
		vector<ll> b;

		for (int i = 0; i < n - 1; i++)
		{
			if (a[i + 1].first == a[i].first)
			{
				continue;
			}
			else
			{
				b.push_back(a[i].first);
				sum += a[i].second;
			}
		}
		sum += a[n - 1].second;
		b.push_back(a[n - 1].first);


		for (int i = 0; i < 10; i++)
		{
			if (b[i] != i + 1)
			{
				statue = 0;
				break;
			}
		}

		if (statue) cout << sum << endl;
		else cout << "MOREPROBLEMS" << endl;
	}


}