// @EXPECTED_RESULTS@: CORRECT
#include <stdio.h>

#define N 10
#define M 10

typedef char board_t[M][N];

void test_prn(board_t board, int p){
   for ( int i = 0; i < M; i++ ){
    int j = 0;
    for (; j < N; j++ ){
      if ( board[i][j] == 0 ) break;
      printf("%c", board[i][j]);
    }
    printf("\n");
    if ( board[i][j] == 0 ) break;
  }
  printf("%d\n", p);
}

bool move(board_t board, int x, int y, int dx, int dy){
    int nx = x + dx;
    int ny = y + dy;
    
    int jx = x + dx/2;
    int jy = y + dy/2;
    
    
    if ( nx < 0 || nx >= N || ny < 0 || ny >= M || board[ny][nx] != '.' || board[y][x] != 'o' || board[jy][jx] != 'o' ) return false;
    
    //printf("jump from %d,%d (%c)  to %d,%d (%c)  over %d,%d (%c)\n", x,y, board[y][x], nx,ny, board[ny][nx], jx,jy, board[jy][jx]);
    board[jy][jx] = '.';
    board[y][x] = '.';
    board[ny][nx] = 'o';
    return true;
}

void undo_move(board_t board, int x, int y, int dx, int dy){
    // jump back
    int nx = x + dx;
    int ny = y + dy;
    
    int jx = x + dx/2;
    int jy = y + dy/2;
    
    board[jy][jx] = 'o';
    board[y][x] = 'o';
    board[ny][nx] = '.';
}


void convert(int &dx, int &dy, int dir){
    switch (dir){
      case 1: dx = 2; dy = 0;
	      break;
      case 2: dx = -2; dy = 0;
	      break;
      case 3: dx = 0; dy = 2;
	      break;
      case 4: dx = 0; dy = -2;
	      break;
    };
}


int solve_rec(board_t board, int p){
  if ( p <= 1 ) return p;
  //test_prn(board, p);
  
  int min_p = p;
  
  for ( int y = 0; y < M; y++ ){
    int x = 0;
    for (; x < N; x++ ){
      if ( board[y][x] == 0 ) break;
      if ( board[y][x] != 'o' ) continue;
      // make a move
      for ( int dir = 1; dir <= 4; dir++ ){
	int dx = 0;
	int dy = 0;
	convert(dx,dy, dir);
	if (  move(board, x, y, dx, dy) ) {
	  int np = solve_rec(board, p - 1);
	  if ( np < min_p ) {
	      min_p = np;
	  }
	  undo_move(board, x, y, dx, dy);
	}
      } // dir
    }//x
    
    if ( board[y][x] == 0 ) break;
  }//y
  return min_p;
}

void init(board_t board){
    for ( int i = 0; i < M; i++ ){
      
      for ( int j = 0; j < N; j++ ){
	board[i][j] = 0;
	
      }
    }
}

int main(){
  int n_cases;
  scanf("%d", &n_cases);
  getchar();//\n
  while( n_cases-->0 ){
    
    board_t board;
    init(board);
    int p = 0;

    // input
    for ( int i = 0; i < M; i++ ){
      int j = 0;
      for ( ; j < N; j++ ){
	char ch = getchar();
	if ( ch == '\n' || feof(stdin) ) {
	  if ( j > 0 ) board[i][j] = '#';
	  break;
	}
	if ( ch == 'o' ) p++;
	board[i][j] = ch;
      }
      if ( j == 0 ) {
	board[i][j] = '0';
	break;
      }
    }
    
    // solve
    int lp = solve_rec(board, p);
    
    
    // output
    printf("%d %d\n", lp, p - lp);
  }
}
