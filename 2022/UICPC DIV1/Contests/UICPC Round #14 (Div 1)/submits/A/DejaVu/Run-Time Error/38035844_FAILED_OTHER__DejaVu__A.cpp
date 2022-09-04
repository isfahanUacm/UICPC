#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <math.h>
#include <numeric>
#include <map>

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
#define set_cout ios_base::sync_with_stdio(false)
#define set_cin cin.tie(NULL)

vector<vector<int>> edge;
vector<vector<int>> force_edge;
set<int> res;

void solve(int node, int k)
{
	if (k > 1) return;

	if(k==0)
	{
		for (auto t : edge[node])
		{
			if (t == 0) continue;
			if (force_edge[t].size() == 0)
			{
				res.insert(t);
			}
		}
	}
	for (auto t : force_edge[node])
	{
		if (t == 0) continue;
		if (force_edge[t].size() == 0)
		{
			res.insert(t);
		}
	}

	if (k == 0)
	{
		for (auto t : edge[node])
		{
			if (t == 0) continue;
			solve(t, k + 1);
		}
	}

	for (auto t : force_edge[node])
	{
		if (t == 0) continue;
		solve(t, k);
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

	fill_n(back_inserter(edge), n, vector<int>());
	fill_n(back_inserter(force_edge), n, vector<int>());


	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;

		if (u < 0)
		{
			force_edge[-1 * (u + 1)].push_back(v - 1);
		}
		else
		{
			edge[u - 1].push_back(v - 1);
		}
	}

	if (force_edge[0].size() == 0) res.insert(0);
	solve(0, 0);

	cout << res.size();

	for (int i = 0; i < n; i++)
	{
		force_edge[i].~vector();
		edge[i].~vector();
	}
	force_edge.~vector();
	edge.~vector();

}
