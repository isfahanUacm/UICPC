#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int board[1000][1000];
int eclass[1<<20];
int ans[100001];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

struct stroke {
  int x1,y1,x2,y2;
} strokes[100000];

int classof(int a) {
  if (eclass[a]==a) return a;
  return eclass[a]=classof(eclass[a]);
}

int join(int a, int b) {
  a = classof(a);
  b = classof(b);
  if (a==b) return 0;
  if (a>b) swap(a,b);
  eclass[b]=a;
  // cerr << "Joined " << (a>>10) << "," << (a&0x3ff) << " " << (b>>10) << "," << (b&0x3ff) << endl;
  return 1;
}

int n,m,q;

int uncover(int x, int y, int target) {
  if (board[x][y]!=target) return 0;
  // cerr << "Uncovering " << x << " " << y << endl;
  board[x][y]=0;
  int diff=1;
  for (int k=0;k<4;++k) {
    int nx=x+dx[k];
    int ny=y+dy[k];
    if (nx<0 or nx>=m or ny<0 or ny>=n or board[nx][ny]) continue;
    diff-=join((x<<10)|y,(nx<<10)|ny);
  }
  return diff;
}

int main() {
  scanf("%d %d %d",&n,&m,&q);
  memset(board,0,sizeof(board));
  for (int i=0;i<q;++i) {
    stroke& s=strokes[i];
    scanf("%d %d %d %d",&s.y1, &s.x1, &s.y2, &s.x2);
    --s.x1;--s.y1;--s.x2;--s.y2;
    if (s.x1>s.x2) swap(s.x1,s.x2);
    if (s.y1>s.y2) swap(s.y1,s.y2);
  }
  for (int i=q;i>0;--i) {
    const stroke& s=strokes[i-1];
    if (s.x1==s.x2) {
      for (int y=s.y1;y<=s.y2;++y) {
        board[s.x1][y]=i;
      }
    }
    else {
      for (int x=s.x1;x<=s.x2;++x) {
        board[x][s.y1]=i;
      }
    }
  }
  for (int i=0;i<(1<<20);++i) eclass[i]=i;
  int beauty=0;
  for (int x=0;x<m;++x) {
    for (int y=0;y<n;++y) {
      beauty+=uncover(x,y,0);
    }
  }
  // cerr << beauty << endl;
  for (int i=q;i>0;--i) {
    ans[i]=beauty;
    const stroke& s=strokes[i-1];
    if (s.x1==s.x2) {
      for (int y=s.y1;y<=s.y2;++y) {
        beauty+=uncover(s.x1,y,i);
      }
    }
    else {
      for (int x=s.x1;x<=s.x2;++x) {
        beauty+=uncover(x,s.y1,i);
      }
    }
  }
  for (int i=1;i<=q;++i) printf("%d\n",ans[i]);
}
