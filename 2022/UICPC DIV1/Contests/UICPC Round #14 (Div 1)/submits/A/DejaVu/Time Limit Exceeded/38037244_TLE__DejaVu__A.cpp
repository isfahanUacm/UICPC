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
vector<int> force_edge;
vector<bool> res;

void DFS(int node , int k)
{
	if (force_edge[node] == -1) res[node] = true;
	if (k > 1) return;

	for (int t : edge[node])
	{
		if (t == 0) continue;
		if (k == 0 && force_edge[t] != -1) DFS(force_edge[t], k + 1);
		if (k == 0 && force_edge[t] == -1) res[t] = true;
	}
	if(force_edge[node] != -1 && force_edge[node] != 0) DFS(force_edge[node], k);
}

int main()
{
	short n, m;
	cin >> n >> m;

	fill_n(back_inserter(edge), n, vector<int>());
	fill_n(back_inserter(force_edge), n, -1);
	fill_n(back_inserter(res), n, false);


	for (short i = 0; i < m; i++)
	{
		int u, v;
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
	DFS(0, 0);

	int y = 0;
	for (auto i : res) if (i) y++;

	cout << y;
}


