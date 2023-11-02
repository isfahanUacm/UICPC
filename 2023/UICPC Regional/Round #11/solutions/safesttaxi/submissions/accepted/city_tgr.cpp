#include <iostream>
#include <vector>
#include <cstdlib>
#include <map>
#include <set>
#include <cstring>
using namespace std ;
const int MAXNODES = 16 * 16 * 4 ;
const int MAXLANES = 4 * MAXNODES ;
int R, C, K, S, P ;
int early[MAXLANES*64] ;
const int dca[] = { 1, 0, -1, 0 } ;
const int dra[] = { 0, 1, 0, -1 } ;
int dir(int dr, int dc) {
   return 1 + abs(dr) - (dr + dc) ;
}
int enc(int r0, int c0, int r1, int c1) {
   return r0 + 16 * (c0 + 16 * dir(r1-r0, c1-c0)) ;
}
struct node {
   int t, k, typ[3], seen ;
} nodes[MAXNODES] ;
int getturn(char c) {
   if (c == 'L')
      return 1 ;
   if (c == 'S')
      return 2 ;
   if (c == 'R')
      return 4 ;
   return -1 ; // can't be reached
}
void addnode(int nid, int t, int k) {
   auto &n = nodes[nid] ;
   n.t = t ;
   n.k = k ;
   n.seen = 1 ;
   string s ;
   for (int i=k-1; i>=0; i--) {
      cin >> s ;
      for (auto c : s)
         n.typ[i] |= getturn(c) ;
   }
}
struct edge {
   int dst, cost ;
   char isleft, isshift ;
} ;
vector<vector<edge>> edges(MAXLANES) ;
void connectup() {
   for (int i=0; i<MAXNODES; i++)
      if (nodes[i].seen) {
         int dir = i >> 8 ;
         int r0 = i & 15 ;
         int c0 = (i >> 4) & 15 ;
         int r1 = r0 + dra[dir] ;
         int c1 = c0 + dca[dir] ;
         int his = 0 ;
         for (int lan=0; lan<nodes[i].k; lan++)
            if (nodes[i].typ[lan] & 2)
               his = lan+1 ;
         for (int lan=0; lan<nodes[i].k; lan++) {
            for (int dl=-1; dl<=1; dl += 2)
               if (lan+dl >= 0 && lan + dl < nodes[i].k)
                  edges[4*i+lan].push_back({4*i+lan+dl, 0, 0, 1}) ;
            for (int turn=0; turn<3; turn++) {
               if (nodes[i].typ[lan] & (1 << turn)) {
                  int ndir = (dir+turn-1)&3 ;
                  int r2 = r1 + dra[ndir] ;
                  int c2 = c1 + dca[ndir] ;
                  int j = enc(r1, c1, r2, c2) ;
                  int destlanes = 1 << lan ;
                  if (turn == 0) { // left turn
                     if (lan > 0 && (nodes[i].typ[lan-1] & 1))
                        destlanes = 1 << (nodes[j].k - nodes[i].k + lan) ;
                     else
                        destlanes = (2 << (nodes[j].k - nodes[i].k + lan)) - 1 ;
                  } else if (turn == 1) { // straight; same as left
                     if (lan > 0 && (nodes[i].typ[lan-1] & 2))
                        destlanes = 1 << (nodes[j].k - his + lan) ;
                     else
                        destlanes = (2 << (nodes[j].k - his + lan)) - 1 ;
                  } else if (turn == 2) { // right turn
                     if (lan + 1 < nodes[i].k && (nodes[i].typ[lan+1] & 4))
                        destlanes = 1 << lan ;
                     else
                        destlanes = (1 << nodes[j].k) - (1 << lan) ;
                  }
                  for (int k=0; k<3; k++)
                     if ((destlanes >> k) & 1) {
                        edges[4*i+lan].push_back({4*j+k, nodes[i].t + nodes[j].t, turn==0, 0}) ;
                     }
               }
            }
         }
      }
}
int senc(int node, int left, int lane) {
   return lane + 8 * (left + 8 * node) ;
}
int main(int argc, char *argv[]) {
   cin >> R >> C >> K >> S ;
   for (int i=0; i<S; i++) {
      int r0, c0, r1, c1, t ;
      cin >> r0 >> c0 >> r1 >> c1 >> t ;
      addnode(enc(r0, c0, r1, c1), t, K) ;
   }
   connectup() ;
   cin >> P ;
   for (int i=0; i<P; i++) {
      int r0, c0, r1, c1, r2, c2, r3, c3, left, lane ;
      cin >> r0 >> c0 >> r1 >> c1 >> r2 >> c2 >> r3 >> c3 >> left >> lane ;
      int start = enc(r0, c0, r1, c1) * 4 ;
      int dest = enc(r2, c2, r3, c3) * 4 ;
      set<pair<int, int>> pq ;
      int estart = senc(start, left, lane) ;
      pq.insert({0, estart}) ;
      memset(early, -1, sizeof(early)) ;
      early[estart] = 0 ;
      int r = -2 ;
      while (!pq.empty()) {
         auto it = pq.begin() ;
         int time = it->first ;
         int es = it->second ;
         pq.erase(it) ;
         if (early[es] != time)
            continue ;
         int n = es >> 6 ;
         int lane = es & 7 ;
         int left = (es >> 3) & 7 ;
         if (n == dest) {
            r = time ;
            break ;
         }
         for (auto &b : edges[n]) {
            if (b.isleft > left || b.isshift > lane)
               continue ;
            int ntim = time + b.cost ;
            int ed = senc(b.dst, left-b.isleft, lane-b.isshift) ;
            if (early[ed] < 0 || early[ed] > ntim) {
               early[ed] = ntim ;
               pq.insert({ntim, ed}) ;
            }
         }
      }
      cout << (0.5*r) << endl ;
   }
}
