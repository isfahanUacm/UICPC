#include <iostream>
#include <functional>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<string> i_name;
	vector<string> i_last;
	vector<string> i_email;
	vector<string> n_name;
	vector<string> n_last;
	vector<string> n_email;
	set<string> ii_name;
	set<string> ii_last;
	set<string> ii_email;
	string line = "aa";

	while (getline(cin, line))
	{
		if (line.empty())
			break;
		string tmp[3];
		tmp[0].push_back(line[0]);
		string counter;
		int cc = 0;
		for (int kk = 1; kk < line.size(); kk++)
		{
			if (line[kk] != ' ')
				tmp[cc].push_back(line[kk]);
			if (line[kk] == ' ' && line[kk - 1] != ' ')
				cc++;
		}
		n_name.push_back(tmp[0]);
		transform(tmp[0].begin(), tmp[0].end(), tmp[0].begin(), ::tolower);
		i_name.push_back(tmp[0]);
		ii_name.insert(tmp[0]);
		n_last.push_back(tmp[1]);
		n_email.push_back(tmp[2]);
		transform(tmp[1].begin(), tmp[1].end(), tmp[1].begin(), ::tolower);
		transform(tmp[2].begin(), tmp[2].end(), tmp[2].begin(), ::tolower);
		i_last.push_back(tmp[1]);
		i_email.push_back(tmp[2]);
		ii_last.insert(tmp[1]);
		ii_email.insert(tmp[2]);
	}
	vector<string> o_name;
	vector<string> o_last;
	vector<string> o_email;
	vector<string> no_name;
	vector<string> no_last;
	vector<string> no_email;
	set<string> oo_name;
	set<string> oo_last;
	set<string> oo_email;
	string tempo;
	while (cin >> tempo)
	{
		no_name.push_back(tempo);
		transform(tempo.begin(), tempo.end(), tempo.begin(), ::tolower);
		o_name.push_back(tempo);
		oo_name.insert(tempo);
		string l, e;
		cin >> l >> e;
		no_last.push_back(l);
		no_email.push_back(e);
		transform(l.begin(), l.end(), l.begin(), ::tolower);
		transform(e.begin(), e.end(), e.begin(), ::tolower);
		o_last.push_back(l);
		o_email.push_back(e);
		oo_last.insert(l);
		oo_email.insert(e);
	}

	bool is_match = false;
	for (int i = 0; i < i_name.size(); i++)
	{
		if ((oo_email.find(i_email[i]) == oo_email.end()) && ((oo_last.find(i_last[i]) == oo_last.end()) || (oo_name.find(i_name[i]) == oo_name.end())))
		{
			cout << "I " << n_email[i] << " " << n_last[i] << " " << n_name[i] << endl;
			is_match = true;
		}
	}
	for (int i = 0; i < o_name.size(); i++)
	{
		if ((ii_email.find(o_email[i]) == ii_email.end()) && ((ii_last.find(o_last[i]) == ii_last.end()) || (ii_name.find(o_name[i]) == ii_name.end())))
		{
			cout << "O " << no_email[i] << " " << no_last[i] << " " << no_name[i] << endl;
			is_match = true;
		}
	}

	if (is_match == false)
		cout << "No mismatches.";
}