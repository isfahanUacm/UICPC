// O(N log^2 N) solution with slow recursive segment tree (but decently fast hashing)
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define trav(a, x) for (auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// KACTL hashing (arithmetic mod 2^64-1).
typedef uint64_t ull;
struct H {
	ull x; H(ull x=0) : x(x) {}
	H operator+(H o) { return x + o.x + (x + o.x < x); }
	H operator-(H o) { return *this + ~o.x; }
	H operator*(H o) { auto m = (__uint128_t)x * o.x;
		return H((ull)m) + (ull)(m >> 64); }
	ull get() const { return x + !~x; }
	bool operator==(H o) const { return get() == o.get(); }
	bool operator<(H o) const { return get() < o.get(); }
};
static const H C = (ll)1e11+3; // (order ~ 3e9; random also ok)

struct Node {
	Node *left, *right;
	int lo, hi;
	H h, p;
	Node(int lo, int hi) : lo(lo), hi(hi) {
		if (hi - lo != 1) {
			int mid = (hi + lo) / 2;
			left = new Node(lo, mid);
			right = new Node(mid, hi);
			p = left->p * right->p;
		} else {
			p = C;
		}
	}

	void set(int i, H val) {
		if (i < lo || i >= hi) return;
		if (hi - lo == 1) {
			h = val;
		} else {
			left->set(i, val);
			right->set(i, val);
			h = left->h * right->p + right->h;
		}
	}

	pair<H, H> query(int L, int R) {
		if (L >= hi || R <= lo) return {0, 1};
		if (L <= lo && hi <= R) return {h, p};
		auto A = left->query(L, R);
		auto B = right->query(L, R);
		return {A.first * B.second + B.first, A.second * B.second};
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, Q;
	cin >> N >> Q;
	vector<vi> comps(N);
	Node *tr = new Node(0, N*2);

	rep(i,0,N) {
		tr->set(i, i);
		tr->set(2*N-1 - i, i);
		comps[i] = {i, 2*N-1 - i};
	}

	auto setEq1 = [&](int A, int B) -> void {
		if (sz(comps[A]) < sz(comps[B])) swap(A, B);
		comps[A].insert(comps[A].end(), all(comps[B]));
		trav(x, comps[B])
			tr->set(x, A);
		comps[B].clear();
	};

	auto checkEq = [&](int A, int B, int len) -> bool {
		auto x = tr->query(A, A + len);
		auto y = tr->query(B, B + len);
		assert(x.second == y.second);
		return x.first == y.first;
	};

	auto setEq = [&](int A, int B, int len) -> void {
		for (;;) {
			if (checkEq(A, B, len))
				break;
			int lo = 0, hi = len;
			while (lo + 1 < hi) {
				int mid = (lo + hi) / 2;
				if (checkEq(A, B, mid))
					lo = mid;
				else
					hi = mid;
			}
			auto a = tr->query(A + lo, A + lo + 1).first.get();
			auto b = tr->query(B + lo, B + lo + 1).first.get();
			assert(a != b);
			assert(a < (ull)N);
			assert(b < (ull)N);
			setEq1((int)a, (int)b);
			A += hi;
			B += hi;
			len -= hi;
		}
	};

	rep(qi,0,Q) {
		int t;
		cin >> t;
		if (t == 1) {
			int L, R;
			cin >> L >> R;
			--L;
			setEq(L, 2*N-R, R - L);
		} else {
			int L1, R1, L2, R2;
			cin >> L1 >> R1 >> L2 >> R2;
			--L1, --L2;
			if (R1 - L1 != R2 - L2) {
				cout << "Not equal" << endl;
			} else {
				int len = R1 - L1;
				if (checkEq(L1, L2, len)) {
					cout << "Equal" << endl;
				} else {
					cout << "Unknown" << endl;
				}
			}
		}
	}
	exit(0);
}
