#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>

using namespace std;

const int MAX_HEALTH = 6;
const int MAX_MINIONS = 5;
const int HEALTH_SPACE = MAX_HEALTH * 2 + 1;

typedef long long ll;

ll encode(vector<int> &state) {
    ll code = 0;
    for(int i=0;i<state.size();i++) {
        code = code * HEALTH_SPACE;
        code += (state[i] + MAX_HEALTH);
    }
    code *= (MAX_MINIONS * 2 + 1);
    code += state.size();
    return code;
}

vector<int> decode(ll code) {
    int n = code % (MAX_MINIONS * 2 + 1);
    code /= (MAX_MINIONS * 2 + 1);
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        a[n-i-1] = (code % HEALTH_SPACE) - MAX_HEALTH;
        code /= HEALTH_SPACE;
    }
    return a;
}

void show(vector<int> state) {
    cout << '[';
    for(int i=0;i<state.size();i++) {
        if (i > 0) cout << ", ";
        cout << state[i];
    }
    cout << "]" << endl;
}

int main() {
    int m, n, expl;
    cin >> m >> n >> expl;
    vector<int> start(m+n);
    int tot = 0;
    for(int i=0;i<m;i++) {
        cin >> start[i];
        tot += start[i];
    }
    for(int i=0;i<n;i++) {
        cin >> start[i+m];
        tot += start[i+m];
        start[i+m] = -start[i+m];
    }

    if (expl >= tot) {
        cout << 1.0 << endl;
        return 0;
    }

    sort(start.begin(), start.end());

    map<ll, double> q;
    q[encode(start)] = 1.0;

    int no_iter = 0;

    for(int turns = 0; turns < expl; turns++) {
        map<ll, double> nq;
        for(map<ll, double>::iterator qi = q.begin(); qi != q.end(); qi++) {
            vector<int> state = decode(qi->first);
            for(int i=0;i<state.size();i++) {
                no_iter++;
                vector<int> copy = vector<int>(state.begin(), state.end());
                if (copy[i] < 0) {
                    copy[i]++;
                } else {
                    copy[i]--;
                }
                if (copy[i] == 0) {
                    copy.erase(copy.begin()+i, copy.begin()+i+1);
                } else {
                    sort(copy.begin(), copy.end());
                }
                ll new_code = encode(copy);
                nq[new_code] += qi->second / state.size();
            }
        }

        q = nq;
    }

    double tot_prob = 0.0;
    for(map<ll, double>::iterator qi = q.begin(); qi != q.end(); qi++) {
        if (decode(qi->first)[0] > 0) {
            tot_prob += qi->second;
        }
    }

    cout << fixed << setprecision(10) << tot_prob << endl;
    //cout << no_iter << endl;

    return 0;
}
