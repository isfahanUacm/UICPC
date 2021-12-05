#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str, m = "";
    cin>>str;
    for (int fir = 1; fir < str.length() - 1; ++fir) {
            for (int sec = fir + 1; sec < str.length(); ++sec) {
                string f = str.substr(0, fir),
                       s = str.substr(fir, sec - fir),
                       t = str.substr(sec, str.length() - sec);
                reverse(f.begin(), f.end());
                reverse(s.begin(), s.end());
                reverse(t.begin(), t.end());
                string res = f.append(s.append(t));
                if (m == "" || m.compare(res) > 0) m = res;         
            }
        }
    cout<<m<<endl;
    return 0;
}

