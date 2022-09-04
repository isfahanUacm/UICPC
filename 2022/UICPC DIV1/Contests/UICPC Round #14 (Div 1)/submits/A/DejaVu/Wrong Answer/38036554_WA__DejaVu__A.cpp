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

vector<vector<short>> edge;
vector<short> force_edge;
set<short> res;
int y = -1;
void solve(short node, short k)
{
	if (k > 1) return;

	if (k == 0)
	{
		for (short t : edge[node])
		{
			if (t == 0) continue;
			if (force_edge[t] == -1) res.insert(t);
		}
	}

	if (force_edge[node] != -1 && force_edge[force_edge[node]] == -1 && force_edge[node] != 0) res.insert(force_edge[node]);
	

	if (k == 0)
	{
		for (short t : edge[node])
		{
			if (t == 0) continue;
			if (force_edge[t] != -1 && force_edge[force_edge[t]] == -1) res.insert(force_edge[force_edge[t]]);
		}
	}

	if (force_edge[node] != -1 && force_edge[node] != 0) solve(force_edge[node], k);
}

int main()
{
	short n, m;
	cin >> n >> m;

	fill_n(back_inserter(edge), n, vector<short>());
	fill_n(back_inserter(force_edge), n, -1);


	for (short i = 0; i < m; i++)
	{
		short u, v;
		cin >> u >> v;

		if (u < 0)
		{
			force_edge[-1 * (u + 1)] = v-1;
		}
		else
		{
			edge[u - 1].push_back(v - 1);
		}
	}

	if (force_edge[0] == -1) res.insert(0);
	solve(0, 0);

	cout << res.size();
}


