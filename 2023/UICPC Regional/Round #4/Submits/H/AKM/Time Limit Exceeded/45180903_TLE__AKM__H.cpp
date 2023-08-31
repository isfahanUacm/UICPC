#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c, n, a;
    cin >> c >> n >> a;
    vector<int> input(a);
    for (int i = 0; i < a; i++)
    {
        cin >> input[i];
    }

    int res = 0;
    set<int> capa;
    for (int i = 0; capa.size() < c && i < a; i++)
    {
        int sz = capa.size();
        capa.insert(input[i]);
        if (capa.size() > sz)
            res++;
    }
    if (a <= c)
    {
        cout << res;
        return 0;
    }

    for (int i = c; i < a; i++)
    {
        if (capa.find(input[i]) != capa.end())
        {
            continue;
        }
        else
        {
            bool is_repeated = false;
            for (int j = input.size() - 1; j >= i; j--)
            {
                if (capa.find(input[j]) != capa.end())
                {
                    capa.erase(input[j]);
                    is_repeated = true;
                    break;
                }
            }
            if (is_repeated == true)
            {
                capa.insert(input[i]);
            }
            else
            {
                capa.erase(capa.begin());
                capa.insert(input[i]);
            }
            res++;
        }
    }
    cout << res;
}