#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

int inf = 1000000000;

// Some random hillclimbing, uses quite a lot of moves

struct pt{
    int x, y;
};

pt mp(int x, int y){
    pt p;
    p.x = x;
    p.y = y;
    return p;
}

bool eq(pt p1, pt p2){
    return (p1.x == p2.x && p1.y == p2.y);
}

int DX[4] = {0,-1,0,1};
int DY[4] = {1,0,-1,0};
string dir[4] = {"up", "left", "down", "right"};
int n = 0;

pt incinerator, robot;
vector<pt> G;

vector<string> ANS;

pt add(pt p, int d){
    p.x += DX[d];
    p.y += DY[d];
    return p;
}

int dist(pt p1, pt p2){
    return abs(p1.x-p2.x) + abs(p1.y-p2.y);
}

bool inbounds(pt p){
    return p.x > -10000;
}

int score(){
    if(!inbounds(robot))return inf;
    int tot_dist = 0;
    int min_dist = inf;
    rep(c1,0,n){
        tot_dist += dist(G[c1], incinerator);
        min_dist = min(min_dist, dist(G[c1], robot));
    }
    if(tot_dist == 0)return 0;
    return tot_dist * 200 + min_dist - dist(robot, incinerator);
}

void move_to(pt p, int d){
    if(eq(p,incinerator))return;
    rep(c1,0,n){
        if(eq(G[c1], p)){
            move_to(add(G[c1], d), d);
            G[c1] = add(G[c1], d);
            return;
        }
    }
    return;
}


bool play(){
    int score_first = score();
    if(score_first == 0)return 0;
    vector<pt> G2 = G;
    pt robot2 = robot;
    int tries = 0;
    while(1){
        int ma = 3 + tries/100;
        int len = rand()%ma+1;
        vi commands;
        rep(c1,0,len){
            int d = rand()%4;
            robot = add(robot, d);
            if(eq(robot, incinerator))robot.x = -inf;
            move_to(robot, d);
            commands.push_back(d);
        }
        int new_score = score();
        if(new_score < score_first){
            trav(y, commands){
                ANS.push_back(dir[y]);
            }
            break;
        }
        else{
            G = G2;
            robot = robot2;
        }
        tries++;
    }
    return 1;
}

int main() {
    cin >> n;
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    robot = mp(a, b);
    incinerator = mp(c, d);

    rep(c1,0,n){
        cin >> a >> b;
        G.push_back(mp(a, b));
    }

    while(play()){}

    //cerr << sz(ANS) << "\n";

    trav(s, ANS){
        cout << s << "\n";
    }

    return 0;
}
