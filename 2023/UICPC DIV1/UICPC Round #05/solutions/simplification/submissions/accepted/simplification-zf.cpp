#include <iostream>
#include <queue>
#include <cstdlib>
#include <complex>

#define MAXN 200000

using namespace std;

typedef complex<int> point;

point p[MAXN+1];

int find(int i, int* uf) {
    return uf[i] == i ? i : (uf[i] = find(uf[i], uf));
}

struct tri {
    int i, j, k, a2;
    tri(int ii = 0, int jj = 1, int kk = 2) {
        i = ii; j = jj; k = kk;
        a2 = abs(imag((p[k]-p[j])*conj(p[i]-p[j])));
    }
    bool operator<(const tri& rhs) const {
         return a2 > rhs.a2 || (a2 == rhs.a2 && j > rhs.j);
    }
};

int main() {
    int n, m;
    int ufl[MAXN+1], ufr[MAXN+1];
    priority_queue<tri> pq;

    cin >> n >> m;
    for (int i = 0; i <= n; ++i) {
        ufl[i] = ufr[i] = i;
        int x, y;
        cin >> x >> y;
        p[i] = point(x, y);
        if (i >= 2) pq.push(tri(i-2, i-1, i));
    }

    for (int i = n; i > m; --i) {
        tri t;
        while (true) {
            t = pq.top();
            pq.pop();
            if (ufl[t.i] == t.i && ufr[t.k] == t.k) break;
        }
        cout << t.j << endl;
        ufl[t.j] = t.i;
        if (t.i > 0) pq.push(tri(find(t.i-1, ufl), t.i, t.k));
        ufr[t.j] = t.k;
        if (t.k < n) pq.push(tri(t.i, t.k, find(t.k+1, ufr)));
    }

    return 0;
}
