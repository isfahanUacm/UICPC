// @EXPECTED_RESULTS@: CORRECT

#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>
#include <iomanip>
#include <cassert>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<vector<double> > vdd;

const int oo = 0x3f3f3f3f;
const double eps = 1e-6;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for(__typeof__((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define mp make_pair
#define pb push_back
#define DBG(...) { if(1) fprintf(stderr, __VA_ARGS__); }
#define DBGDO(X) { if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; }

#define MAX_N 100

double starting [MAX_N];
bool linked [MAX_N][MAX_N];
double res [MAX_N];
int N;
vdd mat;

vdd mult (vdd a, vdd b){
    static vdd tmp (MAX_N, vector<double> (MAX_N));
    FOR(i,0,N) FOR(j,0,N){ 
        tmp[i][j]=0;
        FOR(k,0,N){
            tmp[i][j]+=a[i][k]*b[k][j];
        }
    }
    return tmp;
}

vdd pow(vdd A, int exp) {
    static vdd tmpp (MAX_N, vector<double> (MAX_N));
    FOR(i, 0, N) FOR(j,0,N) tmpp[i][j]=(i==j);
    while (exp) {
        if (exp % 2) tmpp = mult(tmpp,A);
        A=mult(A,A);
        exp /= 2;
    }
    return tmpp;
}

int main (){
    int TC;
    cin >> TC;
    while(TC--){
        memset(linked, false, sizeof(linked));
        memset(res,0,sizeof(res));
        int l,t;
        cin >> N >> l >> t;
        
        mat=vdd (N, vector<double> (N));
             
        FOR(i,0,N){
            mat[i][i]=1;
            linked[i][i]=true;
        }
        
        FOR(i,0,N) cin >> starting[i];
        
        FOR(i,0,l){
            int a,b;
            double d;
            cin >> a >> b >> d;
            mat[b][a]=d;
            mat[a][a]-=d;
            linked[a][b]=true;
            linked[b][a]=true;
        }
        mat=pow(mat,t);
        
        FOR(i,0,N) FOR(j,0,N) res[i]+=mat[i][j]*starting[j];
        
        vi erg;
        double best=oo;
        FOR(i,0,N){
            double act=0;
            FOR(j,0,N){
                if(linked[i][j])
                    act+=res[j];
            }
            if(act<best)
                best=act;
        }
//        DBGDO(best);
        printf("%.9lf\n", best);
    }
	return 0;
}
