#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> idx;
int p1[40001];
int p2[40001];
double memo[40001];

double Blood(int i)
{
	if(i == -1)
		return 0; // No parents
	if(memo[i] < 0)
		memo[i] = (Blood(p1[i]) + Blood(p2[i]))/2;
	return memo[i];
}

int NameToIdx(const string& name)
{
	map<string, int>::iterator it = idx.find(name);
	if(it == idx.end())
	{
		int i = idx.size();
		p1[i] = -1;
		p2[i] = -1;
		memo[i] = -1;
		idx.insert(make_pair(name, i));
		return i;
	}
	return it->second;
}

int main()
{
	int n, m;
	cin >> n >> m;
	string name;
	cin >> name;
	idx.insert(make_pair(name, 0));
	memo[0] = 1;
	for(int i = 1; i <= n; ++i)
	{
		string cname, pname1, pname2;
		cin >> cname >> pname1 >> pname2;
		int c = NameToIdx(cname);
		p1[c] = NameToIdx(pname1);
		p2[c] = NameToIdx(pname2);
	}

	// Get the answer
	string ans;
	double best = 0;
	for(int i = 0; i < m; ++i)
	{
		cin >> name;
		int p = NameToIdx(name);
		double b = Blood(p);
		if(b > best)
		{
			best = b;
			ans = name;
		}
	}
	cout << ans << endl;
	return 0;
}
