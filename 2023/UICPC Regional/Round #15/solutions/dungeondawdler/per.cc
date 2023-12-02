#include <bits/stdc++.h>
using namespace std;

struct pos {
    int r, c;
    pos(int r=0, int c=0): r(r), c(c) {}
    pos operator+(const pos& p) const { return pos(r+p.r, c+p.c); }
    pos operator-(const pos& p) const { return pos(r-p.r, c-p.c); }
    pos operator-() const { return pos(-r, -c); }
    bool operator<(const pos& p) const { return r < p.r || r == p.r && c < p.c; }
    bool operator==(const pos& p) const { return r == p.r && c == p.c; }
};
struct fragment;
typedef pair<fragment*, pos> frag_pos;

const pos dirs[] = {pos(-1, 0), pos(0, 1), pos(1, 0), pos(0, -1)};
const char *dir_sym = "NESW";

struct fragment {
    set<pos> visited, frontier;
    map<pos, frag_pos> traps;
    fragment() { visited.insert(pos()); }
    void show() {
        pos minpos, maxpos;
        for (auto p: visited) {
            minpos = pos(min(minpos.r, p.r), min(minpos.c, p.c));
            maxpos = pos(max(maxpos.r, p.r), max(maxpos.c, p.c));
        }
        pos dim = pos(3,3) + maxpos - minpos, offs = pos(1,1) - minpos;
        vector<string> grid(dim.r, string(dim.c, '#'));
        for (auto p: visited)
            grid[p.r+offs.r][p.c+offs.c] = '.';
        for (auto p: frontier)
            grid[p.r+offs.r][p.c+offs.c] = '?';
        char sym = 'A';
        for (auto t: traps) {
            pos start = t.first, end = t.second.second;
            grid[start.r+offs.r][start.c+offs.c] = sym;
            grid[end.r+offs.r][end.c+offs.c] = sym - 'A' + 'a';
            ++sym;
        }
        grid[offs.r][offs.c] = 'S';
        cout << dim.r << " " << dim.c << "\n";
        for (auto row: grid)
            cout << row << "\n";
        cout.flush();
    }

    void merge(const fragment &f, pos offset) {
        for (auto p: f.visited) {
            frontier.erase(p+offset);
            visited.insert(p+offset);
        }
        for (auto p: f.frontier)
            if (!visited.count(p+offset))
                frontier.insert(p+offset);
        for (auto t: f.traps)
            if (traps.find(t.first+offset) == traps.end())
                traps[t.first+offset] = t.second;
    }
};


int main(void) {
    vector<fragment*> fragments;
    fragments.push_back(new fragment());
    fragment* cur_frag = fragments[0];
    int new_fragments = 0;
    pos cur_pos;
    
    auto get_surroundings = [&]() {
        string msg;
        cin >> msg;
        for (int d = 0; d < 4; ++d)
            if (msg[d] == '.' && !cur_frag->visited.count(cur_pos + dirs[d]))
                cur_frag->frontier.insert(cur_pos + dirs[d]);
    };
    auto get_response = [&]() {
        get_surroundings();
        string msg;
        cin >> msg;
        if (msg == "trap") {
            if (!cur_frag->traps.count(cur_pos)) {
                ++new_fragments;
                fragments.push_back(new fragment());
                cur_frag->traps[cur_pos] = frag_pos(fragments.back(), pos());
            }
            auto dest = cur_frag->traps[cur_pos];
            cur_frag = dest.first;
            cur_pos = dest.second;
            get_surroundings();
        }
    };
    
    function<void(fragment*, fragment*, pos)> merge_fragments = [&](fragment *frag1, fragment *frag2, pos offset) {
        if (frag2 == fragments.front()) {
            swap(frag1, frag2);
            offset = -offset;
        }
        auto it1 = find(fragments.begin(), fragments.end(), frag1);
        if (it1 == fragments.end()) return;
        auto it2 = find(fragments.begin(), fragments.end(), frag2);
        if (it2 == fragments.end()) return;
        
        for (auto frag: fragments)
            for (auto &t: frag->traps)
                if (t.second.first == frag2)
                    t.second = frag_pos(frag1, t.second.second + offset);
        if (cur_frag == frag2) {
            cur_frag = frag1;
            cur_pos = cur_pos + offset;
        }
        frag1->merge(*frag2, offset);
        fragments.erase(it2);
        for (auto t1: frag1->traps)
            for (auto t2: frag2->traps)
                if (t1.first == t2.first + offset &&
                    t1.second.first != t2.second.first)
                    merge_fragments(t1.second.first, t2.second.first,
                                    t1.second.second - t2.second.second);
        new_fragments = 0;
    };
    auto find_merge = [&]() {
        for (auto frag2: fragments) {
            for (auto frag1: fragments) {
                if (frag1 == frag2) break;
                if (frag1->traps.size() == 2 && frag2->traps.size() == 2) {
                    merge_fragments(frag1, frag2,
                                    frag1->traps.begin()->first - frag2->traps.begin()->first);
                    return true;
                }
                for (auto &t1: frag1->traps)
                    for (auto &t2: frag2->traps)
                        if (t1.second == t2.second) {
                            merge_fragments(frag1, frag2, t1.first - t2.first);
                            return true;
                        }
            }
        }
        return false;
    };

    auto make_move = [&](int d) {
        cur_pos = cur_pos + dirs[d];
        cur_frag->frontier.erase(cur_pos);
        cur_frag->visited.insert(cur_pos);
        cout << dir_sym[d] << endl;
    };
    auto explore = [&]() {
        queue<frag_pos> Q;
        map<frag_pos, pair<frag_pos, int>> back;
        Q.push(frag_pos(cur_frag, cur_pos));
        back[Q.front()] = make_pair(Q.front(), -1);
        while (!Q.empty()) {
            auto p = Q.front(); Q.pop();
            for (int d = 0; d < 4; ++d) {
                auto np = frag_pos(p.first, p.second + dirs[d]);
                auto frag = p.first;
                if (frag->traps.count(np.second)) {
                    np = frag->traps[np.second];
                    frag = np.first;
                }
                if (frag->frontier.count(np.second)) {
                    vector<int> moves;
                    while (back[p].second >= 0) {
                        moves.push_back(back[p].second);
                        p = back[p].first;
                    }
                    while (!moves.empty()) {
                        make_move(moves.back());
                        moves.pop_back();
                        get_response();
                    }
                    make_move(d);
                    return true;
                } else if (frag->visited.count(np.second) && !back.count(np)) {
                    back[np] = make_pair(p, d);
                    Q.push(np);
                }
            }
        }
        return false;
    };
    
    while (true) {
        get_response();

        if (new_fragments >= 4)
            merge_fragments(fragments[fragments.size()-3],
                            fragments[fragments.size()-1],
                            pos());
        while (find_merge());

        if (!explore()) break;
    }

    if (fragments.size() == 2) {
        pos offs;
        // FIXME prove that the assertions below are correct
        if (!fragments[0]->frontier.empty()) {
            assert(fragments[0]->frontier.size() == 1);
            assert(fragments[1]->frontier.size() == 1);
            assert(fragments[0]->traps.size() == 1);
            assert(fragments[1]->traps.size() == 1);
            offs = *fragments[0]->frontier.begin() - fragments[1]->traps.begin()->first;
        } else {
            assert(fragments[0]->traps.size() == 1);
            assert(fragments[1]->traps.size() == 1);
            offs = fragments[0]->traps.begin()->first - fragments[1]->traps.begin()->first;
        }
        merge_fragments(fragments[0], fragments[1], offs);
    }
    assert(fragments.size() == 1);
    assert(fragments[0]->frontier.empty());
    cout << "done\n";
    fragments[0]->show();
}
