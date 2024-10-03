#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;

ii loc, burn;
set<ii> garb;

void simul(int dx, int dy) {
    ii movto(loc.first + dx, loc.second + dy);
    ii look = movto;
    if(garb.count(look)) {
        while(garb.count(look)) {
            look = ii(look.first + dx, look.second + dy);
        }
        garb.erase(movto);
        if(look != burn) garb.insert(look);
    }
    loc = movto;
    assert(loc != burn);
}

void printmove(int dx, int dy) {
    if(dx == 1) cout << "right\n";
    else if(dx == -1) cout << "left\n";
    else if(dy == 1) cout << "up\n";
    else cout << "down\n";
}

void domove(int dx, int dy) {
    simul(dx, dy);
    printmove(dx, dy);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, x, y;
    cin >> n;
    cin >> x >> y;
    loc = ii(x, y);
    cin >> x >> y;
    burn = ii(x, y);
    for(int i = 0; i < n; ++i) {
        cin >> x >> y;
        garb.insert(ii(x, y));
    }
    while(loc.first > burn.first + 1) domove(-1, 0);
    if(burn == ii(loc.first - 1, loc.second)) {
        domove(0, 1);
        domove(-1, 0);
        domove(-1, 0);
        domove(0, -1);
    } else {
        domove(-1, 0);
        domove(-1, 0);
        while(loc.second < burn.second) domove(0, 1);
        while(loc.second > burn.second) domove(0, -1);
    }
    for(int i = 0; i < 50; ++i) domove(-1, 0);
    domove(0, 1);
    for(int i = 0; i < 50; ++i) domove(-1, 0);
    domove(0, -1);
    while(loc.first < burn.first - 1) domove(1, 0);
    assert(loc == ii(burn.first - 1, burn.second));
    while(garb.size() > 0 && garb.begin()->first < burn.first) {
        int mnx = garb.begin()->first;
        int yloc = garb.begin()->second;
        while(loc.first >= mnx) domove(-1, 0);
        if(yloc < loc.second) {
            while(loc.second >= yloc) domove(0, -1);
            domove(1, 0);
            while(!garb.count(ii(loc.first, burn.second))) domove(0, 1);
            domove(-1, 0);
            while(loc.second != burn.second) domove(0, 1);
        } else {
            auto it = ++garb.begin();
            while(it != garb.end() && it->first == mnx) it++;
            it--;
            yloc = it->second;
            while(loc.second <= yloc) domove(0, 1);
            domove(1, 0);
            while(!garb.count(ii(loc.first, burn.second))) domove(0, -1);
            domove(-1, 0);
            while(loc.second != burn.second) domove(0, -1);
        }
        while(loc.first < burn.first - 1) domove(1, 0);
        assert(loc == ii(burn.first - 1, burn.second));
    }
    if(garb.empty()) { return 0; }
    assert(garb.begin()->first >= burn.first);
    int mxy = INT_MIN, mny = INT_MAX;
    for(ii g : garb) {
        if(g.first != burn.first) continue;
        mxy = max(mxy, g.second);
        mny = min(mny, g.second);
    }
    if(mny < burn.second) {
        while(loc.second >= mny) domove(0, -1);
        domove(1, 0);
        while(loc.second < burn.second - 1) domove(0, 1);
        domove(-1, 0);
        domove(0, 1);
        assert(loc == ii(burn.first - 1, burn.second));
    }
    if(mxy > burn.second) {
        while(loc.second <= mxy) domove(0, 1);
        domove(1, 0);
        while(loc.second > burn.second + 1) domove(0, -1);
    }
    if(garb.empty()) { return 0; }
    assert(garb.begin()->first > burn.first);
    for(int i = 0; i < 100; ++i) domove(0, 1);
    int mxx = (--garb.end())->first;
    while(loc.first <= mxx) domove(1, 0);
    while(loc.second > burn.second) domove(0, -1);
    assert(garb.begin()->first > burn.first);
    while(loc.first > burn.first + 1) domove(-1, 0);
    if(garb.empty()) { return 0; }
    assert(garb.begin()->first > burn.first);
    assert(loc == ii(burn.first + 1, burn.second));
    while(garb.size() > 0) {
        int mxx = (--garb.end())->first;
        int yloc = (--garb.end())->second;
        while(loc.first <= mxx) domove(1, 0);
        if(yloc > loc.second) {
            while(loc.second <= yloc) domove(0, 1);
            domove(-1, 0);
            while(!garb.count(ii(loc.first, burn.second))) domove(0, -1);
            domove(1, 0);
            while(loc.second != burn.second) domove(0, -1);
        } else {
            auto it = --garb.end();
            while(it != garb.begin() && it->first == mxx) it--;
            if(it->first != mxx) it++;
            yloc = it->second;
            while(loc.second >= yloc) domove(0, -1);
            domove(-1, 0);
            while(!garb.count(ii(loc.first, burn.second))) domove(0, 1);
            domove(1, 0);
            while(loc.second != burn.second) domove(0, 1);
        }
        while(loc.first > burn.first + 1) domove(-1, 0);
        assert(loc == ii(burn.first + 1, burn.second));
    }
}
