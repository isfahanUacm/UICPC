#include <map>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>

#define EP 1e-10

using namespace std;

typedef long long ll;
typedef vector<bool> vb;

typedef double T;
typedef vector<T> vt;
typedef vector<vt> vvt;

T GaussJordan(vvt &A) {
    ll m = A.size(), n = A[0].size();
    ll det = 1;
    ll pj = 0;
    for (ll k = 0; k < m; ++k) {
        ll pi = k;
        while (pj < n) {
            for (ll i = k; i < m; ++i) if (abs(A[i][pj]) > abs(A[pi][pj])) pi = i;
            if (abs(A[pi][pj]) > EP) {
                if (pi != k) {
                    swap(A[pi], A[k]);
                    pi = k;
                    det *= -1;
                }
                break;
            }
            for (ll i = k; i < m; ++i) A[i][pj] = 0;
            ++pj;
        }
        if (pj == n) { det = 0; break; }
        T s = 1.0/A[pi][pj];
        for(ll j = pj; j < n; ++j) A[pi][j] *= s;
        det /= s;
        for (ll i = 0; i < m; ++i) if (i != pi) {
            T a = A[i][pj];
            for (ll j = pj; j < n; ++j) A[i][j] -= a*A[pi][j];
        }
        ++pj;
    }
    return det;
}

map<string, ll> mp;

ll ele_to_id(string ele) {
    if (!mp.count(ele)) {
        ll count = mp.size();
        mp[ele] = count;
    }

    return mp[ele];
}

int main() {
    vvt A(10, vt(20, 0));

    char sign;
    ll n_molecules = 0;
    while (cin >> sign && sign != '0') {
        ll one, N;
        cin >> one >> N;

        ll sign_int = sign == '+' ? 1 : -1;

        for (ll i = 0; i < N; ++i) {
            string element;
            ll count;
            cin >> element >> count;

            ll element_id = ele_to_id(element);
            A[element_id][n_molecules] += sign_int * count;
        }
        ++n_molecules;
    }
    
    ll n_elements = mp.size();
    GaussJordan(A);

    /*
    for (ll i = 0; i < n_elements; ++i) {
        for (ll j = 0; j < n_molecules; ++j) {
            cerr << A[i][j] << " ";
        }
        cerr << endl;
    }
    return 0;*/

    vt solution(n_molecules, 0);
    for (ll i = 0; i < n_elements; ++i) {

        ll molecule = n_molecules;
        
        for (ll j = 0; j < n_molecules; ++j) {
            if (abs(A[i][j]-1) < EP) {
                molecule = j;
                break;
            }
        }
        
        for (ll j = molecule+1; j < n_molecules; ++j) {
            solution[molecule] -= A[i][j];
        }
    }

    for (ll i = 0; i < n_molecules; ++i) {
        if (solution[i] == 0) solution[i] = 1;
    }

    for (ll scale = 1; scale <= 1000; ++scale) {
        bool success = true;
        vt solution_new(solution);
        for (ll i = 0; i < n_molecules; ++i) {
            solution_new[i] *= scale;
            if (abs((ll)(solution_new[i]+EP) - solution_new[i]) > EP) {
                success = false;
            }
        }

        if (success) {
            cout << solution_new[0];
            for (ll i = 1; i < n_molecules; ++i) {
                cout << " " << solution_new[i];
            }
            cout << endl;
            break;
        }
    }
}
