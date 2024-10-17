#include <bits/stdc++.h>
#ifndef LOCAL
#define LINE
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#else
#define LINE cerr << "----------" << nl;
#define fastio
#endif
using namespace std;
using ll = long long; using ld = long double;
#define nl '\n'
#define arr array
#define pb push_back

struct pt {
    double x, y;
    bool operator == (pt const& t) const {
        return x == t.x && y == t.y;
    }
};

int orientation(pt a, pt b, pt c) {
    double v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1; // clockwise
    if (v > 0) return +1; // counter-clockwise
    return 0;
}

bool cw(pt a, pt b, pt c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}
bool collinear(pt a, pt b, pt c) { return orientation(a, b, c) == 0; }

void convex_hull(vector<pt>& a, bool include_collinear = false) {
    pt p0 = *min_element(a.begin(), a.end(), [](pt a, pt b) {
        return make_pair(a.y, a.x) < make_pair(b.y, b.x);
    });
    sort(a.begin(), a.end(), [&p0](const pt& a, const pt& b) {
        int o = orientation(p0, a, b);
        if (o == 0)
            return (p0.x-a.x)*(p0.x-a.x) + (p0.y-a.y)*(p0.y-a.y)
                < (p0.x-b.x)*(p0.x-b.x) + (p0.y-b.y)*(p0.y-b.y);
        return o < 0;
    });
    if (include_collinear) {
        int i = (int)a.size()-1;
        while (i >= 0 && collinear(p0, a[i], a.back())) i--;
        reverse(a.begin()+i+1, a.end());
    }

    vector<pt> st;
    for (int i = 0; i < (int)a.size(); i++) {
        while (st.size() > 1 && !cw(st[st.size()-2], st.back(), a[i], include_collinear))
            st.pop_back();
        st.push_back(a[i]);
    }

    if (include_collinear == false && st.size() == 2 && st[0] == st[1])
        st.pop_back();

    a = st;
}

void solve() {
    int n;
    cin >> n;

    vector<int> x(n), y(n);
    vector<pt> points(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        points[i].x = x[i];
        points[i].y = y[i];
    }
    convex_hull(points, 1);
    n = points.size();
    x.clear();
    y.clear();
    for (int i=0; i<n; i++) {
        x.pb(points[i].x);
        y.pb(points[i].y);
        cout << points[i].x << ' ' << points[i].y << nl;
    }

    /*
    double ans = 1e9;
    for (int i = 0; i < n; i++) {
        double mx = 0;
        for (int j = i+1; j != (i-1+n)%n; j = (j+1)%n) {
            int k = (j+1)%n;
            double m = (double)abs(y[j] - y[k]) / abs(x[j] - x[k]);
            double c = -m * x[j] + y[j];
            double d = fabs(m * x[i] - y[i] + c) / sqrt(m * m + 1);
            mx = max(mx, d);
        }
        ans = min(ans, mx);
    }
    for (int j=0; j<n; j++) {
        for (int k=j+1; k<n; k++) {
            double dis = sqrt(pow(x[j]-x[k], 2)+pow(y[j]-y[k], 2));
            ans = min(ans, dis);
        }
    }
    */

    cout << fixed << setprecision(6) << ans << '\n';
}

int32_t main() {
    fastio
    int t = 1;
cin >> t;
    while (t--) {
        solve();
        LINE
    }
    return 0;
}

