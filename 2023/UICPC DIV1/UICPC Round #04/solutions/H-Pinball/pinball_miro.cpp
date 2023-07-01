//Solution by Miroslav Baláž
#include<iostream>
#include<complex>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);++i)

typedef complex<long long int> T;
typedef pair<T, T> TT;
bool compare(const TT &a, const TT &b) {
    // Return if a<b; ordering is such that  a<b iff a is below b on part where their projection on x axis intersects,
    long long int left=max(real(a.first),real(b.first));
    long long int right=min(real(a.second), real(b.second));
    if(left>=right) return false; //  No overlap incomparable
    if(left==real(a.first)) {  // At least one of left endpoints is inside overlap(not necessery strictly inside, but since lines does not intersect, that points lies on the same side as other points in overlap),
        return imag((b.second-b.first)*conj(a.first-b.first))>0;
    } else {
        return imag((a.second-a.first)*conj(b.first-a.first))<0;
    }
}
vector<TT> segments;
typedef pair<int, int> E; //-1 out 1 in
bool compare_event(const E &a, const E &b) {
    // Returns true if event a is to the left of event b. For same coordinate remove(-1) must go before add(1)
    // so there will be no nonoverlaping segments in set
    const TT &A(segments[a.second]);
    const TT &B(segments[b.second]);
    int xa=real(a.first==-1?A.second:A.first);
    int xb=real(b.first==-1?B.second:B.first);
    if(xa<xb) return true;
    if(xa>xb) return false;
    return a<b;
}

class CompareWrapper{
    public:
        bool operator()(const TT &a, const  TT &b) {
            bool result = compare(a,b);
            return result;
        }
};

vector<vector<int> > edges;  // Will hold graph used for topological ordering
vector<int> order;  // Will hold permutation of topological order
vector<int> seen;  // Used in topological sort, to mark visited vertices

void go(int x) {
    // Computes topological ordering
    if(seen[x]) return;
    seen[x]=1;
    REP(i, edges[x].size()) go(edges[x][i]);
    order.push_back(x);
}

bool compare_complex(T a, T b){
    // Returns true if a is lexicographically smaller than b
    // There is no ordering defined for complex number in mathematics!
    if(real(a)<real(b)) return true;
    if(real(a)>real(b)) return false;
    return imag(a)<imag(b);
}

bool compare_segments(TT a,TT b) {
    // Returns true if a is  lexicographically smaller than b
    if (compare_complex(a.first,b.first)) return true;
    if (compare_complex(b.first,a.first)) return false;
    return compare_complex(a.second,b.second);
}

int main() {
    int n;  cin>>n;
    REP(i,n)  {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2) {swap(x1,x2); swap(y1,y2);}
        segments.push_back(TT(T(x1, y1), T(x2, y2)));
    }
    int x0;  // Initial position fo the ball
    cin>>x0;
    // Sort segments so we can binary search them
    sort(segments.begin(), segments.end(),ptr_fun(compare_segments));

    // Build graph that will be used to topologically sort lines
    edges = vector< vector< int> > (n);

    // We will use sweeping from left to right always maintaining ordered set of segments
    vector<E> events;
    REP(i,n) events.push_back(E(1,i));
    REP(i,n) events.push_back(E(-1,i));

    sort(events.begin(), events.end(), ptr_fun(compare_event));

    set<TT, CompareWrapper> S;  // S will hold set of that intersect each other

    REP(i, events.size()) {

        const E &e(events[i]);
        if(e.first==1) {  // Interval start
            // When we arrive at the start of interval we add it, and also we insert edges in graph from preceeding segment and to following
            S.insert(segments[e.second]);

            set<TT>::iterator it=S.find(segments[e.second]);
            vector<TT> I;

            if(it!=S.begin()) {
                it--;
                I.push_back(*it);  // Preceeding segment
                ++it;
            }

            I.push_back(*it);  // Current segment
            ++it;

            if(it!=S.end()) {
                I.push_back(*it);  // Following segment
            }

            vector<int> K;
            // Decode to index
            REP(j,I.size()) K.push_back(lower_bound(segments.begin(), segments.end(), I[j],ptr_fun(compare_segments))-segments.begin());

            // Add edges
            REP(j,K.size()) if(j){
                edges[K[j-1]].push_back(K[j]);
            }
        } else {  // Interval end
            // When we arrive at the end of interval we remove it
            S.erase(segments[e.second]);
        }

    }

    // Topologicaly sort resulting permutation will be in array order
    seen = vector<int>(n, 0);
    REP(i,n) go(i);

    // Go through segments from top to bottom
    REP(i,n) {
        const TT &s(segments[order[i]]);
        if(x0 >= real(s.first) && x0<=real(s.second)) {
            if(imag(s.first)<imag(s.second)) {
                x0 = real(s.first);
            } else {
                x0 = real(s.second);
            }
        }
    }

    cout<<x0<<endl;
}


// Alternative comaparison of segments: compare height of arbitrary point lying on segments inside overlaping interval
//long long int center=(left+right)/2; // Assuming left and right are even
//T da(a.second-a.first),db(b.second-b.first);
//  return (imag(a.first)+imag(da)*real(db)*(center-real(a))   ) <
//               (imag(b.first)+imag(db)*real(da)*(center-real(b))   )
