#include<iostream>
#include<queue>
#include<utility>
#include<cstdlib>

using namespace std;

const int MAX = 200010;

struct Point{
   int x,y,l,r;
};

int ts[MAX];
Point pl[MAX];

int darea(int x1, int y1, int x2, int y2, int x3, int y3){
   int ans = abs( (x2-x1)*(y3-y1) - (x3 - x1)*(y2 - y1) );
   return ans;
}

pair < int, pair< int, int > > make_tag(int i, int time){
   return make_pair(
      -darea(pl[i].x, pl[i].y,
	    pl[pl[i].l].x, pl[pl[i].l].y,
	    pl[pl[i].r].x, pl[pl[i].r].y), make_pair(-i, time) );	    
}

int main(){
   int n, m;
   cin >> n >> m;
   for(int i = 0; i <= n; i++){
      cin >> pl[i].x >> pl[i].y;
      pl[i].l = i-1;
      pl[i].r = i+1;
   }
   priority_queue< pair < int, pair< int, int > > > pq;
   for(int i = 1; i < n; i++)
     pq.push( make_tag(i, 0) );
   int l = n;
   while(l > m){
      pair< int, pair< int, int> > t = pq.top();
      pq.pop();
      int i = -t.second.first;
      if(t.second.second < ts[i])
	 continue;
      cout << i << endl;
      int j = pl[i].l, k = pl[i].r;
      pl[j].r = k;
      pl[k].l = j;
      if(j != 0){
	 ts[j]++;
	 pq.push( make_tag(j, ts[j]) );
      }
      if(k != n){
	 ts[k]++;
	 pq.push( make_tag(k, ts[k]) );
      }
      l--;
   }
   return 0;
}
