#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define F first
#define S second
#define vi vector<int>
#define pb push_back
#define pf push_front
char c[4][4];
int mark[4][4];
int ig = -1, jg, ir = -1, jr, iy = -1, jy, ib = -1, jb;
int ig2 = 0, jg2, ir2 = 0, jr2, iy2 = 0, jy2, ib2 = 0, jb2;
int gg = 0, rr = 0, bb = 0, yy = 0;

bool v(int ix, int jx, char ch, int z, int zz, int iii, int jjj) 
{
    if (z == zz && ix == iii && jx == jjj) return true;
    int ii = ix;
    int jj = jx;

    if (ii > 0 && c[ii - 1][jj] == ch && !mark[ii - 1][jj]) {
        mark[ii - 1][jj] = 1;
        if (v(ii - 1, jj, ch, z + 1, zz, iii, jjj)) return true;
        mark[ii - 1][jj] = 0;
    }
    if (ii < 3 && c[ii + 1][jj] == ch && !mark[ii + 1][jj]) {
        mark[ii + 1][jj] = 1;
        if (v(ii + 1, jj, ch, z + 1, zz, iii, jjj)) return true;
        mark[ii + 1][jj] = 0;
    }
    if (jj > 0 && c[ii][jj - 1] == ch && !mark[ii][jj - 1]) {
        mark[ii][jj - 1] = 1;
        if (v(ii, jj - 1, ch, z + 1, zz, iii, jjj)) return true;
        mark[ii][jj - 1] = 0;
    }
    if (jj < 3 && c[ii][jj + 1] == ch && !mark[ii][jj + 1]) {
        mark[ii][jj + 1] = 1;
        if (v(ii, jj + 1, ch, z + 1, zz, iii, jjj)) return true;
        mark[ii][jj + 1] = 0;
    }

    return false;
}

bool valid() 
{
    memset(mark, 0, sizeof(mark));
    gg = 0, rr = 0, bb = 0, yy = 0;
    for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) {
        if (c[i][j] == 'G') gg++;
        if (c[i][j] == 'R') rr++;
        if (c[i][j] == 'B') bb++;
        if (c[i][j] == 'Y') yy++;
    }
    mark[ig][jg] = 1;
    mark[ir][jr] = 1;
    mark[ib][jb] = 1;
    mark[iy][jy] = 1;
    if ((ig != -1) && !v(ig, jg, 'G', 1, gg, ig2, jg2)) return false;
    if ((ir != -1) && !v(ir, jr, 'R', 1, rr, ir2, jr2)) return false;
    if ((ib != -1) && !v(ib, jb, 'B', 1, bb, ib2, jb2)) return false;
    if ((iy != -1) && !v(iy, jy, 'Y', 1, yy, iy2, jy2)) return false;

    return true;
}

bool calc(int i, int j) 
{
    if (j == 4) {
        // if (valid()) {
        //     for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) cout << c[i][j] << " \n"[j == 3];
        //     //cout << gg << ' ' << rr << ' '  << bb << ' ' << rr << '\n';
        // }
        return valid();
    }
    if (c[i][j] == 'W') {
        if (ig != -1) {
            c[i][j] = 'G';
            if (calc((i + 1) % 4, j + (i / 3))) return true;
        }
        if (iy != -1) {
            c[i][j] = 'Y';
            if (calc((i + 1) % 4, j + (i / 3))) return true;
        }
        if (ir != -1) {
            c[i][j] = 'R';
            if (calc((i + 1) % 4, j + (i / 3))) return true;
        }
        if (ib != -1) {
            c[i][j] = 'B';
            if (calc((i + 1) % 4, j + (i / 3))) return true;
        }
        c[i][j] = 'W';
    }
    else {
        if (calc((i + 1) % 4, j + (i / 3))) return true;
    }

    return false;
}


int main()
{
    for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) {
        cin >> c[i][j];
        if (c[i][j] == 'G' && ig == -1) {
            ig = i;
            jg = j;
        }
        else if (c[i][j] == 'R' && ir == -1) {
            ir = i;
            jr = j;
        }
        else if (c[i][j] == 'B' && ib == -1) {
            ib = i;
            jb = j;
        }
        else if (c[i][j] == 'Y' && iy == -1) {
            iy = i;
            jy = j;
        }
        else if (c[i][j] == 'G') {
            ig2 = i;
            jg2 = j;
        }
        else if (c[i][j] == 'R') {
            ir2 = i;
            jr2 = j;
        }
        else if (c[i][j] == 'B') {
            ib2 = i;
            jb2 = j;
        }
        else if (c[i][j] == 'Y') {
            iy2 = i;
            jy2 = j;
        }
    }

    if (calc(0, 0)) {
        cout << "solvable\n";
    }
    else {
        cout << "not solvable\n";
    }

    return 0;
}