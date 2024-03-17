#include <iostream>

using namespace std;

int main()
{
    string s, c;
    char p = 0;
    cin >> s;
    int nums[26] = {0};
    for(int i = 0; i < s.length(); i++)
        nums[s[i]-'A']++;
    int k = 0, t = 0;
    for(int i = 0; i < 26; i++)
        if(nums[i] % 2 == 1)
        {
            k++;
            p = i + 'A';
        }
    if(k > 1)
    {
        cout << "NO SOLUTION";
        return 0;
    }
    for(int i = 0; i < 26; i++)
        for(int j = 0; j < nums[i]/2; j++)
            c += char(i+'A');
    if (k!=0) c += p;
    for(int i = 25; i >= 0; i--)
        for(int j = 0; j < nums[i]/2; j++)
            c += char(i+'A');
    cout << c;
    return 0;
}
