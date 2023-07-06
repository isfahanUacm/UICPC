#include<iostream>
#include<cctype>
#include<algorithm>
#include<string>
#include<utility>
using namespace std;

const int MAX=1010;
const int MAX2 = 100;

int N;

pair< string, pair< string, string> > Name[MAX];
int DP[MAX][MAX2];

string form(string ln, string fn, int use){
   string ret;
   ret += ln[0];
   for(int i = 1; use > 0 and i < ln.size(); i++){
      ret += ln[i];
      use--;
   }
   ret += fn[0];
   for(int i = 1; use > 0; i++){
      ret += fn[i];
      use--;
   }
   return ret;
}

int solve(int pos, int prev_used){
   if(DP[pos][prev_used] != -1){
      return DP[pos][prev_used];
   }
   int mini = 1000000;
   string s1 = form(Name[pos-1].second.first, Name[pos-1].second.second, prev_used);
   for(int k = 0; k <= (int)Name[pos].first.size() - 2; k++){
      string s2 = form(Name[pos].second.first, Name[pos].second.second, k);
      if(s1 < s2){
	 if(pos == N){
	    mini = min(mini, k);
	 }
	 else{
	    mini = min(mini, solve(pos+1, k) + k);
	 }
      }
   }
   return DP[pos][prev_used] = mini;
}

int main(){

   cin >> N;
   for(int i = 0; i < MAX; i++){
      fill(DP[i], DP[i]+MAX2, -1);
   }
   for(int i = 1; i <= N; i++){
      string name[2];
      cin >> name[1] >> name[0];
      for(int j = 0; j <= 1; j++){
	 for(int k = 0; k < (int)name[j].size(); k++){
	    name[j][k] = tolower(name[j][k]);
	 }
      }
      Name[i] = make_pair(name[0] + name[1], make_pair(name[0], name[1]));
   }
   sort(Name, Name+N+1);
   /*
   for (int i = 0; i <= N; i++) {
     cout << Name[i].first << endl;
     //<< ' ' << Name[i].second.first << ' '
     //	  << Name[i].second.second << endl;
     }
   */
   cout << solve(1, 0) << endl;
   
   return 0;
}
