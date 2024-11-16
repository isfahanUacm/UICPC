#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define all(x) x.begin(), x.end()

int main()
{
    int n;
    cin >> n;
    string query[4];
    for (int i = 0; i < n; i++)
        query[0].push_back('a' + (i % 26));
    cout << "? " << query[0] << endl;
    string ans[4];
    cin >> ans[0];
    for (int m = 0; m < 3; m++)
    {
        vector<int> alph_pos(26, 0);
        for (int i = 0; i < n; i++)
        {
            int char_ind = ans[m][i] - 'a';
            query[m + 1].push_back('a' + alph_pos[char_ind]);
            alph_pos[char_ind]++;
        }
        cout << "? " << query[m + 1] << endl;
        fflush(stdout);
        cin >> ans[m + 1];
    }
    vector<vector<pair<char, int>>> char_index(4);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char_index[i].push_back(make_pair(ans[i][j], j));
        }
        sort(all(char_index[i]));
        sort(all(ans[i]));
    }

    vector<int> perm(n);
    for (int i = 0; i < n; i++)
    {
        vector<set<int>> pos(4);
        for (int j = 0; j < 4; j++)
        {
            char charac = query[j][i];
            int index_start = lower_bound(ans[j].begin(), ans[j].end(), charac) - ans[j].begin();
            int index_end = upper_bound(ans[j].begin(), ans[j].end(), charac) - ans[j].begin();
            for (int m = index_start; m < index_end; m++)
            {
                pos[j].insert(char_index[j][m].second);
            }
        }
        set<int> res_1;
        set<int> res_2;
        set<int> res_3;
        set_intersection(pos[0].begin(), pos[0].end(), pos[1].begin(), pos[1].end(), inserter(res_1, res_1.begin()));
        set_intersection(pos[1].begin(), pos[1].end(), pos[2].begin(), pos[2].end(), inserter(res_2, res_2.begin()));
        set_intersection(res_1.begin(), res_1.end(), res_2.begin(), res_2.end(), inserter(res_3, res_3.begin()));
        perm[i] = *res_3.begin();
    }
    cout << "! ";
    for (int i = 0; i < n; i++)
        cout << perm[i] + 1 << " ";
    cout << endl;
    fflush(stdout);

    return 0;
}