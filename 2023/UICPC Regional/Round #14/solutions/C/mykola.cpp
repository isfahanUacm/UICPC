// @EXPECTED_RESULTS@: CORRECT
#include <stdio.h>

#define N 8
#define M 4

typedef struct{
  int x;
  int y; } pos_t;

inline int abs(int x){
  return x < 0 ? -x:x;
}

inline bool legal(int x){
    return x >= 0 && x < N;
}

inline bool oneMove(pos_t p1, pos_t p2){
    return ( abs(p2.x-p1.x) == abs(p2.y-p1.y) );
}

inline bool eq(pos_t p1, pos_t p2){
    return p1.x == p2.x && p1.y == p2.y;
}

inline void prn(pos_t p){
  //printf(" %d %d", p.x, p.y);
  printf(" %c %c", p.x + 'A', p.y + '1');
}

inline int solve(pos_t moves[M], pos_t trgt){
  //printf("%d,%d -->  %d,%d\n", moves,y1,x2,y2);
  if ( eq(moves[0], trgt) ) return 0;
  if ( ((moves[0].x + moves[0].y) & 1) != ((trgt.x+trgt.y) & 1) ) return -1;
  
  if ( oneMove(moves[0], trgt) ) {
      moves[1] = trgt;
      return 1;
  }
  
  // find a move
  for ( int d = -7; d < 7; d++ ){
      if ( ! legal(moves[0].x + d) ) continue;
      pos_t np;
      np.x = moves[0].x + d;
      np.y = moves[0].y + d;
      
      if ( legal(np.y) && oneMove(np, trgt) ){
	  moves[1] = np;
      }
      np.y = moves[0].y - d;
      if ( legal(np.y) && oneMove(np, trgt) ){
	  moves[1] = np;
      }
  }
  moves[2] = trgt;
  return 2;
}

int main(){
  int cases;
  scanf("%d", &cases);
  getchar();//\n
  
  while(cases-->0){
    int num[M];
    pos_t moves[M];
    pos_t trgt;
    int n_moves = 0;
    
    for (int i = 0; i < 4; ){
	  char ch = getchar();
	  if ( ch == ' ' || ch == '\t' || ch == '\n' ) continue;
	  num[i] = ch - ( (i & 1) == 0 ? 'A':'1');
	  i++;
    }
    moves[0].x = num[0];
    moves[0].y = num[1];
    trgt.x = num[2];
    trgt.y = num[3];
    int n = solve(moves, trgt);
    if ( n < 0 ) {
      printf("Impossible\n");
      continue;
    }
    printf("%d", n);
    for ( int i = 0; i < n + 1; i++ ){
	prn(moves[i]);
    }
    printf("\n");
  }
}
