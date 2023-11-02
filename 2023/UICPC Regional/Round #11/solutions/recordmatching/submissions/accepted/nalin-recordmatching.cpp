#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <sstream>
#include <algorithm>
using namespace std;

int main(void)
{
	string inp;
	vector<pair<pair<string, string>, string>> records[2];
	int curidx = 0;
	while (getline(cin, inp))
	{
		if (int(inp.size()) == 0)
		{
			curidx = 1;
			continue;
		}
		istringstream sin(inp);
		string first_name, last_name, email;
		sin >> first_name >> last_name >> email;
		records[curidx].push_back({{first_name, last_name}, email});
	}

	bool nomismatch = true;

	set<pair<string, string>> nameS[2];
	set<string> emailS[2];
	for(int i = 0;i < 2;i++)
	{
		for(auto item: records[i])
		{
			string first_name = item.first.first, last_name = item.first.second, email = item.second;
			transform(first_name.begin(), first_name.end(), first_name.begin(), ::tolower); 
			transform(last_name.begin(), last_name.end(), last_name.begin(), ::tolower); 
			transform(email.begin(), email.end(), email.begin(), ::tolower);

			nameS[i].insert({first_name, last_name});
			emailS[i].insert(email);
		}
	}

	for(int i = 0;i < 2;i++)
	{
		vector<pair<pair<string, string>, pair<string, string>>> answers;
		for (auto item: records[i])
		{
			string first_name = item.first.first, last_name = item.first.second, email = item.second;
			transform(first_name.begin(), first_name.end(), first_name.begin(), ::tolower); 
			transform(last_name.begin(), last_name.end(), last_name.begin(), ::tolower); 
			transform(email.begin(), email.end(), email.begin(), ::tolower);

			if(nameS[int(!i)].find({first_name, last_name}) == nameS[int(!i)].end() && emailS[int(!i)].find(email) == emailS[int(!i)].end())
			{
				nomismatch = false;
				answers.push_back({{email, item.second}, {item.first.second, item.first.first}});
			}
		}

		sort(answers.begin(), answers.end());
		for (auto it: answers)
		{
			cout << (i == 0 ? "I " : "O ") << it.first.second << " " << it.second.first << " " << it.second.second << "\n";
		}
	}

	if(nomismatch) cout << "No mismatches.\n";
}
