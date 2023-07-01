#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    long long N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
	cin >> a[i];
	a[i]--;
    }
    vector<int> cl(N,-1); //cycle length
    vector<vector<int> > c(N+1); //cycle starts
    for (int i = 0; i < N; ++i) {
	if (cl[i] == -1) {
	    int p = a[i], j = 1;
	    while (p != i) {
		p = a[p];
		++j;
	    }
	    c[j].push_back(i);
	    for (int k = 0; k < j; ++k) {
		cl[p] = j;
		p = a[p];
	    }
	}
    }

    vector<int> sol(N,-1); //solution
    bool fail = false;

    {
	vector<int> factors(0);
	int sr = (int)(sqrt(K)+0.5), r = K;
	for (int j = 2; j <= sr; j++) {
	    if (r%j == 0) {
		factors.push_back(j);
		while (r%j == 0) {
		    r /= j;
		}
		sr = (int)(sqrt(r)+0.5);
	    }
	}
	if (r > 1) {
	    factors.push_back(r);
	}
	vector<int> last(c[1].size()+1,-1);
	last[0] = 0;
	for (int i = 0; i < factors.size(); ++i) {
	    for (int j = factors[i]; j <= c[1].size(); ++j) {
		if (last[j-factors[i]] != -1) {
		    last[j] = factors[i];
		}
	    }
	}
	if (last[c[1].size()] == -1) {
	    last[c[1].size()] = c[1].size();
	}
	int p = c[1].size();
	while (p) {
	    vector<int> cycle(last[p]);
	    for (int i = 0; i < last[p]; ++i) {
		cycle[i] = c[1][c[1].size()-1-i];
	    }
	    for (int j = 0; j < cycle.size(); ++j) {
		sol[cycle[j]] = cycle[(j+1)%cycle.size()];
	    }
	    c[1].erase(c[1].end()-last[p],c[1].end());
	    p -= last[p];
	}
    }

    for (int i = 2; i < N && !fail; ++i) {
	if (c[i].size() == 0)
	    continue;
	vector<int> factors(0);
	int sr = (int)(sqrt(i)+.5), r = i;
	for (int j = 2; j <= sr; j++) {
	    if (r%j == 0) {
		factors.push_back(j);
		r /= j;
		j--;
		sr = (int)(sqrt(r)+0.5);
	    }
	}
	if (r>1) {
	    factors.push_back(r);
	}
	int needed = 1, Kp = K;
	for (int j = 0; j < factors.size(); ++j) {
	    while (Kp % factors[j] == 0) {
		needed *= factors[j];
		Kp /= factors[j];
	    }
	}
	while (c[i].size() > 0) {
	    if (needed > c[i].size() || needed > K) {
		fail = true;
		break;
	    }
	    vector<int> cycle(needed*i);
	    for (int j = c[i].size()-needed; j < c[i].size(); ++j) {
		int p = c[i][j];
		for (int k = 0; k < i; ++k) {
		    cycle[(j+k*K)%(needed*i)] = p;
		    p = a[p];
		}
	    }
	    for (int j = 0; j < cycle.size(); ++j) {
		sol[cycle[j]] = cycle[(j+1)%cycle.size()];
	    }
	    c[i].erase(c[i].end()-needed,c[i].end());
	}
    }
    if (fail) {
	cout << "Impossible" << endl;
    } else {
	for (int i = 0; i < sol.size(); ++i) {
	    cout << sol[i]+1 << " ";
	}
	cout << endl;
    }
}
