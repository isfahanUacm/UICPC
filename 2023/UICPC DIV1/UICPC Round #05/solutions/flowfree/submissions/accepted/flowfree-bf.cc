#include<iostream>
#include<stack>
#include<vector>
#include<utility>

using namespace std;

string S = "RGBYW";
int A[4][4];
pair<int, int> B[4][2];
bool F[4];
bool Yellow = false;
int dx[4] = {0,1, 0,-1};
int dy[4] = {1,0,-1, 0};


bool solve(int S[4][4], pair<int, int> cur, pair<int, int> end, int col){
   if(cur == end){
      if(col == 3 or (col == 2 and !Yellow)){
	 bool works = true;
	 for(int i = 0; i < 4; i++){
	    for(int j = 0; j < 4; j++){
	       if(S[i][j] == 4)
		  works = false;
	    }
	 }
	 return works;
      }
      
      return solve(S, B[col+1][0], B[col+1][1], col+1);
   }
   bool works = false;
   for(int i = 0; i < 4; i++){
      pair<int,int> next = make_pair(cur.first + dx[i], cur.second + dy[i]);
      
      if(next.first < 0 or next.first > 3 or next.second < 0 or next.second > 3)
	 continue;
      if(S[next.first][next.second] != 4 and next != end)
	 continue;
      int S2[4][4];
      for(int i = 0; i < 4; i++){
	 for(int j = 0; j < 4; j++){
	    S2[i][j] = S[i][j];
	 }
      }
      S2[next.first][next.second] = col;
      works = (works or solve(S2, next, end, col));
   }
   return works;
}

int main(){   
   for(int i = 0; i < 4; i++){
      for(int j = 0; j < 4; j++){
	 char c; cin >> c;
	 for(int k = 0; k < (int)S.size(); k++){
	    if(c == S[k]){
	       A[i][j] = k;
	       if(k == 3)
		  Yellow = true;
	       if(k != 4){
		  B[k][(F[k] == false ? 0 : 1)] = make_pair(i,j);
		  F[k] = true;
	       }
	       break;
	    }
	 }
      }
   }

   cout << (solve(A, B[0][0], B[0][1], 0) ? "solvable" : "not solvable") << endl;
   return 0;
}
