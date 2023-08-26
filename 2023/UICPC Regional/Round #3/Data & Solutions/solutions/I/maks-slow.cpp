/*
 * @EXPECTED_RESULTS@: TIMELIMIT
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

istream &operator>>(istream &is, vector<int> &data)
{
    char dummy;
    is >> dummy;  // '['
    for (size_t n = 0; n < data.size(); ++n)
    {
        if (n > 0) is >> dummy;  // ','
        is >> data[n];
    }
    is >> dummy;  // ']'
    return is;
}

ostream &operator<<(ostream &os, vector<int> &data)
{
    os << '[';
    for (size_t n = 0; n < data.size(); ++n)
    {
        if (n > 0) os << ',';
        os << data[n];
    }
    os << ']';
    return os;
}

int main()
{
    int cases = 0;
    cin >> cases;
    while (cases-- > 0)
    {
        string program;
        cin >> program;
        int N = 0;
        cin >> N;
        vector<int> data(N);
        cin >> data;
        if (count(program.begin(), program.end(), 'D') > N)
        {
            cout << "error" << endl;
            continue;
        }
        bool reversed = false;
        for (string::iterator it = program.begin(); it != program.end(); ++it)
        {
            if (*it == 'R')
            {
                reversed = !reversed;
            }
            if (*it == 'D')
            {
                if (!reversed)
                {
                    reverse(data.begin(), data.end());
                    reversed = true;
                }
                data.pop_back();
            }
        }
        if (reversed) reverse(data.begin(), data.end());
        cout << data << endl;
    }
}
