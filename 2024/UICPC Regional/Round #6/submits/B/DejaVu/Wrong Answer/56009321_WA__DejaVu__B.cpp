#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define all(x) x.begin(), x.end()
#define M_PI 3.14159265358979323846

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pair<ld, ld> s;
    pair<ld, ld> d;
    pair<ld, ld> c_red;
    pair<ld, ld> c_blue;
    ld r_red, r_blue;
    cin >> s.first >> s.second;
    cin >> d.first >> d.second;
    cin >> c_blue.first >> c_blue.second >> r_blue;
    cin >> c_red.first >> c_red.second >> r_red;

    ld f_t2 = (c_red.first - s.first) * (c_red.first - s.first) + (c_red.second - s.second) * (c_red.second - s.second);
    ld s_t2 = (c_red.first - d.first) * (c_red.first - d.first) + (c_red.second - d.second) * (c_red.second - d.second);
    ld t_f = sqrt(f_t2 - r_red * r_red);
    ld t_s = sqrt(s_t2 - r_red * r_red);
    ld ans = t_f + t_s;
    ld tmp = t_f / r_red;
    ld angle_f = atan(tmp);
    tmp = t_s / r_red;
    ld angle_s = atan(t_s / r_red);

    ld angle = 0;
    ld m1 = (c_red.second - s.second) / (c_red.first - s.first);
    if (m1 == INFINITY || m1 == -INFINITY)
    {
        m1 = 0;
        angle += M_PI / 2;
    }
    ld m2 = (c_red.second - d.second) / (c_red.first - d.first);
    if (m2 == INFINITY || m2 == -INFINITY)
    {
        m2 = 0;
        angle += M_PI / 2;
    }
    angle = angle + atan(abs((m1 - m2) / (1 + m1 * m2)));
    if (angle <= 0)
        angle += M_PI;
    ld angle_tan = angle - angle_f - angle_s;
    ld len_c_tan = angle_tan * r_red;
    ans += len_c_tan;
    cout << setprecision(18) << ans;

    return 0;
}