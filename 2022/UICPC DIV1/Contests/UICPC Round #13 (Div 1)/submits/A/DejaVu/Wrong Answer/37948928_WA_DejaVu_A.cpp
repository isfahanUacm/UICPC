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

	 vector<pair<ll,ll>> slv;

	 for (int i = 0; i < n; i++)
	 {
		 ll x, y;
		 cin >> x >> y;
		 slv.push_back(make_pair(x, y));
	 }

	 sort(slv.begin(), slv.end());

	 ll t = 0;
	 ll res = 0;
	 vector<pair<ll, ll>> ::iterator a = slv.begin(), b = slv.begin() + 1;


	 for (int i = 0; i < n; i++)
	 {
		 if (a == slv.end() && b == slv.end()) break;
		 if (a == slv.end() - 1)
		 {
			 t += (*a).first;
			 if ((*a).second >= t)
			 {
				 res++;
			 }
			 else
			 {
				 t -= (*a).first;
			 }
		 }

		 if (b != slv.end())
		 {
			 t += (*a).first;
			 if ((*a).second >= t)
			 {
				 t += (*b).first;
				 if ((*b).second >= t)
				 {
					 res += 2;
					 a += 2;
					 b += 2;
					 continue;
				 }
				 t -= ((*a).first);
				 t -= ((*b).first);
			 }
		 }


		 if (b != slv.end())
		 {
			 t += (*b).first;
			 if ((*b).second >= t)
			 {
				 t += (*a).first;
				 if ((*a).second >= t)
				 {
					 res += 2;
					 a += 2;
					 b += 2;
					 continue;
				 }
				 t -= ((*a).first);
				 t -= ((*b).first);
			 }
		 }

		 t += (*a).first;
		 if ((*a).second >= t)
		 {
			 res++;
			 b += 2;
			 a += 2;
		 }
		 else
		 {
			 t -= (*a).first;
		 }

	 }

	 cout << res;
}
