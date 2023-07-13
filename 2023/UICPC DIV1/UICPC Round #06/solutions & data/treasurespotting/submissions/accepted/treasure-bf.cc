#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second

typedef long long ll;
typedef pair<ll, ll> pll;

ll dist(pll A, pll B){
   return (A.X - B.X)*(A.X - B.X) + (A.Y - B.Y)*(A.Y - B.Y);
}

ll dot(pll A, pll B, pll C){
   return (C.X - A.X)*(B.X - A.X) + (C.Y - A.Y)*(B.Y - A.Y); 
}

ll cross(pll A, pll B, pll C, pll D){
   pll a = make_pair(B.X - A.X, B.Y - A.Y);
   pll b = make_pair(D.X - C.X, D.Y - C.Y);
   return a.X*b.Y - a.Y*b.X;
}

bool pil(pll A, pll B, pll C){
   return cross(A, B, B, C) == 0
      and C.X <= max(A.X, B.X) and C.X >= min(A.X, B.X)
      and C.Y <= max(A.Y, B.Y) and C.Y >= min(A.Y, B.Y);
}

int par(ll a){
   return (a > 0LL ? 1 : -1);
}

bool intersection(pll A, pll B, pll C, pll D){
   if(pil(A,B,C) or pil(A,B,D))
      return true;
   ll c1 = cross(A,B,B,D), c2 = cross(A,B,B,C),
      c3 = cross(C,D,D,B), c4 = cross(C,D,D,A);
   if(c1 == 0 or c2 == 0 or c3 == 0 or c4 == 0)
      return false;
   return par(c1)*par(c2) == -1 and par(c3)*par(c4) == -1;
}

int main(){
   int W, P; cin >> W >> P;
   pll T; cin >> T.X >> T.Y;
   vector<pair<pll, pll> > Wall(W);
   vector<pair<pll, pll> > Pirate(P);
   vector<bool> see; see.resize(P,true);
   for(auto & x : Wall)
      cin >> x.X.X  >> x.X.Y >> x.Y.X >> x.Y.Y;
   for(int i = 0; i < P; i++){
      auto &x = Pirate[i];
      cin >> x.X.X  >> x.X.Y >> x.Y.X >> x.Y.Y;
      if(dist(x.X, x.Y) < dist(x.X, T)){
	 //cerr << "not close enough to treasure" << endl;
	 see[i] = false;
      }
      else if(dot(x.X, x.Y, T) < 0LL){
	 //cerr << "treasure not in semi-circle" << endl;
	 see[i] = false;
      }
   }
   for(int i = 0; i < P; i++){
      for(int j = 0; j < P and see[i]; j++){
	 if(i == j) continue;
	 auto x = Pirate[i];
	 auto y = Pirate[j];
	 if(pil(x.X,T,y.X)){
	    see[i] = false;
	    //cerr << "person " << j << " in way of person " << i << endl;
	    break;
	 }
      }
   }
   for(int i = 0; i < P; i++){
      for(int j = 0; j < W and see[i]; j++){
	 auto x = Pirate[i];
	 auto y = Wall[j];
	 if(intersection(x.X, T, y.X, y.Y)){
	    //cerr << "wall " << j << " in way of person " << i << endl;
	    see[i] = false;
	    break;
	 }
      }
   }
   for(int i = 0; i < P; i++){
      cout << (see[i] ? "" : "not ") << "visible" << endl;
   }
   return 0;
}
