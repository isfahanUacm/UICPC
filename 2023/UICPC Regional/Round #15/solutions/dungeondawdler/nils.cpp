#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);
uniform_int_distribution<> DD(0, 1000000000);

ll random(ll r){
    return (1000000000 * ll(DD(eng)) + DD(eng))%r;
}

struct cell{
    int x,y;
};

int h(cell c){
    return c.x*1000 + c.y;
}

bool operator<(const cell &a, const cell &b){
    return h(a) < h(b);
}

string NESW = "NESW";
int DX[4] = {-1,0,1,0};
int DY[4] = {0,1,0,-1};
int steps = 0;

bool DEBUG = 0;
int n,m;
char grid[503][503];
cell start;
cell current;
cell trap_dest[2];

// Values:
// 1 - wall
// 2 - unstepped space
// 3 - stepped space
// 4 - trap (any)
// 5 - trap (same)
// 6 - trap (different)

bool consistent(map<cell,int> & M1, map<cell,int> & M2){
    trav(u, M1){
        cell y = u.first;
        if(M2.find(y) == M2.end())continue;
        if(M1[y] == M2[y])continue;
        if(M1[y] == 2 && (M2[y] == 3 || M2[y] == 4 || M2[y] == 5 || M2[y] == 6))continue;
        if(M2[y] == 2 && (M1[y] == 3 || M1[y] == 4 || M1[y] == 5 || M1[y] == 6))continue;
        if(M1[y] == 4 && (M2[y] == 5 || M2[y] == 6))continue;
        if(M2[y] == 4 && (M1[y] == 5 || M1[y] == 6))continue;
        return 0;
    }
    return 1;
}

map<cell,int> unify(map<cell,int> & M1, map<cell,int> & M2){
    map<cell,int> result;
    trav(u,M1){
        cell y = u.first;
        if(result.find(y) == result.end())result[y] = M1[y];
        result[y] = max(result[y], M1[y]);
    }
    trav(u,M2){
        cell y = u.first;
        if(result.find(y) == result.end())result[y] = M2[y];
        result[y] = max(result[y], M2[y]);
    }
    return result;
}

void print_map(map<cell,int> & M, cell spawn = {0,0}, cell a_dest = {-32132,-32132}, cell b_dest = {-32132,-32132}){
    int lx = 10000;
    int rx = -10000;
    int ly = 10000;
    int ry = -10000;
    trav(u, M){
        cell y = u.first;
        lx = min(lx, y.x);
        rx = max(rx, y.x);
        ly = min(ly, y.y);
        ry = max(ry, y.y);
    }
    cout << "done\n";
    cout << rx-lx+1 << " " << ry-ly+1 << "\n";
    rep(x,lx,rx+1){
        rep(y,ly,ry+1){
            if(M.find({x,y}) == M.end()){
                cout << "#";
            }
            else{
                if(x == spawn.x && y == spawn.y){
                    cout << "S";
                    continue;
                }
                if(x == a_dest.x && y == a_dest.y){
                    cout << "a";
                    continue;
                }
                if(x == b_dest.x && y == b_dest.y){
                    cout << "b";
                    continue;
                }
                int a = M[{x,y}];
                if(a == 4 || a == 5){
                    cout << "A";
                }
                if(a == 6){
                    cout << "B";
                }
                if(a == 1){
                    cout << "#";
                }
                if(a == 2 || a == 3){
                    cout << ".";
                }
            }
        }
        cout << "\n";
    }
    fflush(stdout);
}

vector<cell> potential_traps;
set<cell> trap_set;

bool prev_trap = 0;
bool input_last = 0;

bool input(map<cell,int> & M, cell now){

    if(input_last && !prev_trap){
        return 0;
    }

    bool trap = 0;
    bool around[4] = {0};

    if(DEBUG){
        trap = (grid[current.x][current.y] == 'A' || grid[current.x][current.y] == 'B');
        rep(c1,0,4){
            around[c1] = (grid[current.x + DX[c1]][current.y + DY[c1]] == '#');
        }
        if(grid[current.x][current.y] == 'A'){
            current = trap_dest[0];
        }
        if(grid[current.x][current.y] == 'B'){
            current = trap_dest[1];
        }
    }
    else{
        string s1;
        cin >> s1;
        rep(c1,0,4){
            char ch = s1[c1];
            around[c1] = (ch == '#');
        }

        if(!prev_trap){
            string s;
            cin >> s;
            trap = (s[0] == 't');
        }
        else{
            trap = 0;
        }
    }

    rep(c1,0,4){
        cell temp = {now.x + DX[c1], now.y + DY[c1]};
        int a = around[c1];
        if(a == 0)a = 2;
        if(M.find(temp) == M.end()){
            M[temp] = a;
        }
    }
    if(trap){
        M[now] = 4;
        if(trap_set.find(now) == trap_set.end()){
            trap_set.insert(now);
            potential_traps.push_back(now);
        }
    }
    else{
        M[now] = 3;
    }

    if(trap){
        prev_trap = 1;
    }
    else{
        prev_trap = 0;
    }
    input_last = 1;
    return trap;
}

void make_move(map<cell,int> & M, cell & now, int dir){
    if(!DEBUG)cout << NESW[dir] << "\n";
    fflush(stdout);
    now = {now.x + DX[dir], now.y + DY[dir]};
    steps++;
    if(DEBUG){
        current = {current.x + DX[dir], current.y + DY[dir]};
    }
    input_last = 0;
}

set<cell> blocked;
set<cell> temp_block;

bool dfs(map<cell,int> & M, cell & now, bool temp_clear = 0){
    bool temp = input(M, now);
    if(temp)return 0;
    vector<pii> dirs;
    if(temp_clear){
        temp_block.insert(now);
    }
    rep(c1,0,4){
        cell temp = {now.x + DX[c1], now.y + DY[c1]};
        int weight = random(100);
        if(M[temp] == 2 && blocked.find(temp) == blocked.end()){
            dirs.push_back({weight, c1});
        }
        if(M[temp] == 3 && temp_clear && temp_block.find(temp) == temp_block.end()){
            dirs.push_back({weight, c1});
        }
    }
    if(sz(dirs) == 0)return 1;
    sort(all(dirs));
    rep(c1,0,sz(dirs)){
        make_move(M, now, dirs[c1].second);
        bool res = dfs(M, now, temp_clear);
        if(!res)return 0;
        make_move(M, now, (dirs[c1].second + 2)%4);
        input(M, now);
    }
    return 1;
}

map<cell,int> random_walk(bool block = 1){
    blocked.clear();
    if(block){
        trav(c, potential_traps){
            if(random(2) == 0){
                blocked.insert(c);
            }
        }
    }
    map<cell,int> res;
    cell now = {0,0};
    bool ans = dfs(res,now);
    if(ans){
        blocked.clear();
        temp_block.clear();
        dfs(res,now,1);
    }
    return res;
}

map<cell,int> initial;
vector<map<cell,int> > maps;

bool one_trap(){
    map<cell,int> A;
    bool fail = 0;
    trav(M, maps){
        if(!consistent(A, M))return 0;
        A = unify(A, M);
    }
    cell spawn = {0,0};
    trav(y, initial){
        if(y.second == 4)spawn = y.first;
    }
    trav(y, A){
        if(y.second == 4){
            spawn.x = y.first.x - spawn.x;
            spawn.y = y.first.y - spawn.y;
        }
    }
    print_map(A,spawn,{0,0});
    return 1;
}

bool two_traps(bool same_a, bool same_b){
    map<cell,int> A;
    map<cell,int> B;
    bool pos = 0;
    bool used_a = 0;
    bool used_b = 0;
    bool fail = 0;
    trav(M, maps){
        if(pos == 0){
            if(!consistent(A, M))return 0;
            A = unify(A, M);
            trav(u, A){
                cell y = u.first;
                if(A[y] == 4){
                    if(!used_a){
                        used_a = 1;
                        A[y] = 5+same_a;
                    }
                    else{
                        A[y] = 6-same_a;
                    }
                }
            }
            trav(u, M){
                cell y = u.first;
                if(M[y] == 4){
                    pos ^= (A[y]-5);
                    break;
                }
            }
        }
        else{
            if(!consistent(B, M))return 0;
            B = unify(B, M);
            trav(u, B){
                cell y = u.first;
                if(B[y] == 4){
                    if(!used_b){
                        used_b = 1;
                        B[y] = 5+same_b;
                    }
                    else{
                        B[y] = 6-same_b;
                    }
                }
            }
            trav(u, M){
                cell y = u.first;
                if(M[y] == 4){
                    pos ^= (B[y]-5);
                    break;
                }
            }
        }

    }

    int main_chamber = -1;
    cell main_to_same = {0};

    trav(u, A){
        cell y = u.first;
        if(A[y] == 5){
            main_chamber = 0;
            main_to_same = y;
            break;
        }
    }

    if(main_chamber == -1){
        trav(u, B){
            cell y = u.first;
            if(B[y] == 5){
                main_chamber = 1;
                main_to_same = y;
                break;
            }
        }
    }

    if(main_chamber == -1){
        main_chamber = 0;
        trav(u, A){
            cell y = u.first;
            if(A[y] == 2){
                A[y] == 5;
                main_to_same = y;
                break;
            }
        }
    }

    cell s_to_A = {0,0};
    trav(u, initial){
        cell y = u.first;
        if(initial[y] == 4){
            s_to_A = y;
            break;
        }
    }

    map<cell,int> M;
    cell spawn = {0,0};
    cell b_dest = {0,0};

    if(main_chamber == 0){
        cell D = {0,0};
        trav(u, B){
            cell y = u.first;
            if(B[y] == 6){
               D.x = main_to_same.x - y.x;
               D.y = main_to_same.y - y.y;
            }
        }
        map<cell,int> B2;
        trav(u, B){
            cell y = u.first;
            B2[{y.x + D.x, y.y + D.y}] = B[y];
            if(B[y] == 5){
                B2[{y.x + D.x, y.y + D.y}] = 6;
            }
            else{
                if(B[y] == 6){
                    B2[{y.x + D.x, y.y + D.y}] = 5;
                }
            }
        }
        M = unify(A,B2);
        spawn = {main_to_same.x - s_to_A.x, main_to_same.y - s_to_A.y};
        b_dest = D;
    }
    else{
        cell D = {0,0};
        trav(u, A){
            cell y = u.first;
            if(A[y] == 6){
               D.x = main_to_same.x - y.x;
               D.y = main_to_same.y - y.y;
            }
        }
        map<cell,int> A2;
        trav(u, A){
            cell y = u.first;
            A2[{y.x + D.x, y.y + D.y}] = A[y];
            if(A[y] == 5){
                A2[{y.x + D.x, y.y + D.y}] = 6;
            }
            else{
                if(A[y] == 6){
                    A2[{y.x + D.x, y.y + D.y}] = 5;
                }
            }
        }
        M = unify(A2,B);
        cell main_to_diff = {0,0};
        trav(u, B){
            cell y = u.first;
            if(B[y] == 6){
                main_to_diff = y;
                break;
            }
        }

        spawn = {main_to_diff.x - s_to_A.x, main_to_diff.y - s_to_A.y};
        b_dest = D;
    }

    print_map(M, spawn, {0,0}, b_dest);

    return 1;
}

void solve(){
    cell now = {0,0};

    bool temp = dfs(initial, now);
    if(temp){
        print_map(initial);
        return;
    }
    while(steps < 90000){
        maps.push_back(random_walk());
    }

    if(one_trap())return;
    if(two_traps(0,0))return;
    if(two_traps(0,1))return;
    if(two_traps(1,0))return;
    if(two_traps(1,1))return;

}

int main() {
   // ios_base::sync_with_stdio(0);
    //cin.tie(0);

    ll a,b,c;

    if(DEBUG){
        cin >> n >> m;
        rep(c1,0,n){
            string s;
            cin >> s;
            rep(c2,0,m){
                grid[c1][c2] = s[c2];
                if(s[c2] == 'S'){
                    start = {c1,c2};
                    current = {c1,c2};
                }
                if(s[c2] == 'a'){
                    trap_dest[0] = {c1,c2};
                }
                if(s[c2] == 'b'){
                    trap_dest[1] = {c1,c2};
                }
            }
        }
    }

    solve();

    return 0;
}

