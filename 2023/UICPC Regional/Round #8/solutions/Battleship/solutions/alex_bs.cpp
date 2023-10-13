// @EXPECTED_RESULTS@: CORRECT
#include <iostream>

using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)

string feld[2][50];
int W,H,N,S[2];
int checkWin(){
	int res = 3;
	FOR(p,0,2)if(S[p]) res &= 1<<p;
	return res;
}
int main() {
	int tc, win, x, y;
	cin >> tc;
	while(tc--){
		cin >> W >> H >> N;
		FOR(p,0,2)FORD(i,0,H)cin >> feld[p][i];
		S[0] = S[1] = 0;
		FOR(p,0,2)FOR(h,0,H)FOR(w,0,W)if(feld[p][h][w] == '#')++S[p];
		win = checkWin();
		while(N>0 && win == 0){
			FOR(p,0,2){
				while(N-->0){
					cin >> x >> y;
					if(feld[p^1][y][x] == '#'){
						feld[p^1][y][x] = ' ';
						if(0==--S[p^1])break;
					} else break;
				}
			}
			if(win == 0)win = checkWin();
		}
		while(N-->0)cin >> x >> y;
		if(win == 0 || win == 3)cout << "draw\n";
		else if(win == 1)cout << "player one wins\n";
		else cout << "player two wins\n";
	}
	return 0;
}
