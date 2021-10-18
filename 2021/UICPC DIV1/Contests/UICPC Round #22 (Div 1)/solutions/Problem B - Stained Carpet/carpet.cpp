#include <bits/stdc++.h>
using namespace std;

#define ldouble long double

const ldouble PI = acos(-1);
const ldouble TWOPI = 2 * PI;
const ldouble SQRT3OVER4 = sqrt(3.0) / 4.0;
const ldouble EPS = 1e-9;

ldouble a, b, c;

ldouble angle(ldouble a, ldouble b, ldouble c)
    {
        ldouble ang = 0.0;
        if(abs(c - a - b) < EPS) 
            ang = PI;
        else if(abs(abs(a - b) - c) < EPS) 
            ang = 0.0; 
        else 
            ang = acos((a * a + b * b - c * c) / (2.0 * a * b));       
        while(ang < 0.0)
            ang += TWOPI;
        return ang;
    }

ldouble calc(ldouble x)
{
    return angle(a, b, x) + angle(a, c, x) + angle(b, c, x) - TWOPI;
}

int main()
{
    cin >> a >> b >> c;
    
    ldouble lo = max(max(abs(a-b), abs(a-c)), abs(b-c));
    ldouble hi = min(min(a+b, a+c), b+c);

    ldouble area = -1.0;
    
    if (lo <= hi)
        if (lo <= hi + EPS && calc(lo) * calc(hi) <= EPS)
        {
            while(hi - lo > EPS)
            {
                ldouble mid = (lo + hi) / 2.0;
                if(calc(mid) < 0.0)
                    lo = mid;
                else 
                    hi=mid;
            }
            area = lo * hi * SQRT3OVER4;
        }
                           
    printf("%.4Lf\n", area);
    return 0;
}
