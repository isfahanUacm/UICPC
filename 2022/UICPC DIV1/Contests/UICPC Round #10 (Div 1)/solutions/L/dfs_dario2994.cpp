#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define SZ(x) ((int)((x).size()))
#define all(x) (x).begin(), (x).end()

// Returns the time elapsed in nanoseconds from 1 January 1970, at 00:00:00.
LL get_time() {
    return chrono::duration_cast<chrono::nanoseconds>(
        chrono::steady_clock::now().time_since_epoch())
        .count();
}

// Returns a random integer from the range [l, r].
LL randint(LL l, LL r) {
	#if DEBUG && !ONLINE_JUDGE
	static mt19937_64 gen; // Deterministic on the local machine.
	#else
	static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
	#endif
	return uniform_int_distribution<LL>(l, r)(gen);
}

template <typename Iterator>
string print_iterable(Iterator begin, Iterator end, string bef, string aft,
        function<string(typename iterator_traits<Iterator>::value_type)>* f = nullptr) {
    stringstream res;
    res << bef;
    bool is_first = true;
    for (Iterator it = begin; it != end; ++it) {
        if (!is_first) res << ", ";
        if (f != nullptr) res << (*f)(*it);
        else res << *it;
        is_first = false;
    }
    res << aft;
    return res.str();
}

template <typename S, typename T>
ostream& operator <<(ostream& out, const pair<S, T>& p) {
    out << "{" << p.first << ", " << p.second << "}";
    return out;
}

#define _define_print_container(Container, bef, aft)        \
template <typename T>                                       \
ostream& operator <<(ostream& out, const Container<T>& v) { \
    out << print_iterable(v.begin(), v.end(), bef, aft);    \
    return out;                                             \
}                                                           \

_define_print_container(vector, "[", "]");
_define_print_container(set, "{", "}");
_define_print_container(unordered_set, "{", "}");
_define_print_container(multiset, "{", "}");
_define_print_container(unordered_multiset, "{", "}");
_define_print_container(deque, "[", "]");

#define _define_print_dictionary(Dictionary, bef, aft)                      \
template <typename T1, typename T2>                                         \
ostream& operator <<(ostream& out, const Dictionary<T1, T2>& v) {           \
    out << print_iterable(v.begin(), v.end(), bef, aft);                    \
    return out;                                                             \
}                                                                           \

_define_print_dictionary(map, "{", "}");
_define_print_dictionary(unordered_map, "{", "}");

#define _define_print_container_adaptor(Adaptor, OP)                        \
template <typename T>                                                       \
ostream& operator <<(ostream& out, Adaptor<T> a) {                          \
    vector<T> v;                                                            \
    while (!a.empty()) v.push_back(a.OP()), a.pop();                        \
    out << v;                                                               \
    return out;                                                             \
}                                                                           \

_define_print_container_adaptor(stack, top)
_define_print_container_adaptor(queue, front)
_define_print_container_adaptor(priority_queue, top)

template<class TH>
void _dbg(const char* name, TH val){
    clog << name << ": " << val << endl;
}
template<class TH, class... TA>
void _dbg(const char* names, TH curr_val, TA... vals) {
    while(*names != ',') clog << *names++;
    clog << ": " << curr_val << ", ";
    _dbg(names+1, vals...);
}

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    #define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
    #define dbg_arr(x, len) \
    clog << #x << ": " << print_iterable(x, x+len, "[", "]") << endl;
    #define dbg_arr1(x, len) \
    clog << #x << ": " << print_iterable(x+1, x+len+1, "[", "]") << endl;
#else
    #define dbg(...)
    #define dbg_arr(x, len)
    #define dbg_arr1(x, len)
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

void dfs(const vector<set<int>>& aa, vector<bool>& visited, int v) {
    if (visited[v]) return;
    visited[v] = true;
    for (int a: aa[v]) dfs(aa, visited, a);
}

void solve() {
    auto nextangle = [&](int theta) { return (theta+1) % 360; };
    auto prevangle = [&](int theta) { return (theta+359) % 360; };
    auto cell2id = [&](int r, int theta) { return 360*r + theta; };

    vector<set<int>> aa(cell2id(20, 359) + 1);

    for (int r = 0; r <= 20; r++) {
        for (int theta = 0; theta < 360; theta++) {
            int id = cell2id(r, theta);
            int id1 = cell2id(r, nextangle(theta));
            int id2 = cell2id(r, prevangle(theta));
            int id3 = cell2id(r-1, theta);
            int id4 = cell2id(r+1, theta);
            aa[id].insert(id1);
            aa[id].insert(id2);
            if (r > 0) aa[id].insert(id3);
            if (r < 20) aa[id].insert(id4);
        }
    }
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char t;
        cin >> t;
        if (t == 'C') {
            int r, theta1, theta2;
            cin >> r >> theta1 >> theta2;
            for (int theta = theta1; theta != theta2; theta = nextangle(theta)) {
                int id1 = cell2id(r-1, theta);
                int id2 = cell2id(r, theta);
                aa[id1].erase(id2);
                aa[id2].erase(id1);
            }
        } else {
            int r1, r2, theta;
            cin >> r1 >> r2 >> theta;
            for (int r = r1; r < r2; r++) {
                int id1 = cell2id(r, prevangle(theta));
                int id2 = cell2id(r, theta);
                aa[id1].erase(id2);
                aa[id2].erase(id1);
            }
        }
    }

    vector<bool> visited(aa.size(), false);
    dfs(aa, visited, cell2id(0, 0));

    if (visited[cell2id(20, 0)]) cout << "YES\n";
    else cout << "NO\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int t;
    cin >> t;
    while (t--) solve();
}
