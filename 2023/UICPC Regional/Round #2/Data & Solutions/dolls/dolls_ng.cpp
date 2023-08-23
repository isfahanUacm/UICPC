#include <algorithm>
#include <cstdio>
#include <set>
#include <vector>

using namespace std;

const int MAX_m = 10000;

struct Doll { 
    int w, h; 
    Doll(int _w, int _h) { w = _w; h = _h; }
};

bool cmpWinc(const Doll& a, const Doll& b) { return a.w < b.w; }

struct cmpHdec { 
    bool operator()(const Doll& a, const Doll& b) { return a.h > b.h; } 
};

int main() {
    int C; scanf("%d", &C);
    for (int c = 0; c < C; c++) {
        int m; scanf("%d", &m);
        vector<Doll> SW;
        for (int i = 0; i < m; i++) {
            int w, h; scanf("%d %d", &w, &h);
            SW.push_back(Doll(w, h));
        }
        sort(SW.begin(), SW.end(), cmpWinc);
        multiset<Doll,cmpHdec> SH;
        vector<Doll> N;
        int a = m;
        // Look at dolls from narrowest to widest
        for (int p = 0; p < m; p++) {
            // Find a tallest shorter doll from the narrower dolls
            if (SH.upper_bound(SW[p]) != SH.end()) {
                // Put it inside this doll
                SH.erase(SH.upper_bound(SW[p]));
                a--;
            } 
            N.push_back(SW[p]);
            // If the next doll is wider, 
            // enter all seen dolls into set of dolls to consider for insertion
            if (p+1 < m && SW[p].w < SW[p+1].w) {
                SH.insert(N.begin(), N.end());
                N.clear();
            }
        }
        printf("%d\n", a);
    }
}
