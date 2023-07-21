#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> ppl(n);

    for (int i = 0; i < n; i++)
        cin >> ppl[i];

    sort(ppl.begin(), ppl.end());

    // int vote_w = 0;
    int vote_l = 0;

    for (int i = 0; i < (n / 2) + 1; i++)
    {
        // vote_w += (ppl[i] / 2) + 1;
        vote_l += (ppl[i] / 2);
    }

    for (int i = (n / 2) + 1; i < n; i++)
    {
        vote_l += ppl[i];
    }

    cout << vote_l;

    return 0;
}