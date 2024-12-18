#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <math.h>
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
#define set_cout ios_base::sync_with_stdio(false)
#define set_cin cin.tie(NULL)

int main()
{
	set_cout;
	set_cin;

	int n;
	cin >> n;

	vector<char> slv;

	for (int i = 0; i < n; i++)
	{
		char r;
		cin >> r;
		slv.push_back(r);
	}

	int res = 0;
	while (true)
	{
		bool flag = true;
		for (int i = n - 1; i >= 0; i--)
		{
			if (slv[i] == 'O')
			{
				slv[i] = 'Z';
				for (int j = i + 1; j < n; j++)
				{
					slv[j] = 'O';
				}
				flag = false;
				res++;
				break;
			}
		}

		if (flag) break;
	}

	cout << res;
}