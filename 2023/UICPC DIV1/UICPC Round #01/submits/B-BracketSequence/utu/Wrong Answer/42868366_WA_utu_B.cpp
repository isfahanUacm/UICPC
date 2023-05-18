#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef unsigned long long ull;

int main()
{
    ull n;
    cin >> n;

    ull OPEN = 1e9 + 8;
    ull CLOSE = 1e9 + 9;

    vector<ull> tokens(n);
    string temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if (temp == "(")
            tokens[i] = OPEN;
        else if (temp == ")")
            tokens[i] = CLOSE;
        else
            tokens[i] = stoull(temp);
    }

    stack<ull> stack;
    bool should_add = true;

    ull temp_num = 0;
    bool is_reading_num = false;

    for (int i = 0; i < n; i++)
    {
        if (tokens[i] == OPEN)
        {
            if (is_reading_num)
            {
                is_reading_num = false;
                stack.push((temp_num));
            }
            stack.push(OPEN);
            should_add = !should_add;
        }
        else if (tokens[i] == CLOSE)
        {
            // Popping open parentheses
            if (stack.size() > 0 && stack.top() == OPEN)
            {
                stack.pop();
            }
            should_add = !should_add;
            if (stack.size() > 0 && stack.top() < OPEN)
            {
                if (should_add)
                {
                    temp_num += stack.top();
                }
                else
                {
                    temp_num *= stack.top();
                }

                stack.pop();
            }
        }
        else
        {
            if (!is_reading_num)
            {
                temp_num = should_add ? 0 : 1;
            }
            is_reading_num = true;
            if (should_add)
            {
                temp_num += tokens[i];
            }
            else
            {
                temp_num *= tokens[i];
            }
        }
    }

    cout << (temp_num % ull(1e9 + 7)) << '\n';

    return 0;
}
