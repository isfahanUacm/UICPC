// @EXPECTED_RESULTS@: CORRECT

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

struct Position {

  Position(int column, int row) : column(column), row(row) {
  }

  Position(char c, int i) {
    if(c >= 'a' && c <= 'z') {
      column = c - 'a' + 1;
    } else {
      column = c - 'A' + 1;
    }
    row = i;
  }
  
  int column;
  int row;
};

Position getIntersection(int as, Position& start, Position& end) {
  int xm = (end.row + as * end.column - start.row + as * start.column) / (2 * as);
  int ym = as * xm + start.row - as*start.column;
  
  return Position(xm, ym);
}

bool isValidPosition(Position& p) {
  return p.column >= 1 && p.column <= 8 && p.row >= 1 && p.row <= 8;
}

int main() {

  int testcases;
  cin >> testcases;
  
  for(int testcase = 0; testcase < testcases; testcase++) {
  
    char startColumn;
    int startRow;
    cin >> startColumn;
    cin >> startRow;
    Position start(startColumn, startRow);
    
    char endColumn;
    int endRow;
    cin >> endColumn;
    cin >> endRow;
    Position end(endColumn, endRow);
    
    if(start.column == end.column && start.row == end.row) {
      cout << "0 " << (char)(start.column + 'A' - 1) << " " << start.row << endl;
      continue;
    }
    
    if((abs(start.column - end.column) + abs(start.row - end.row)) % 2 == 1) {
      cout << "Impossible" << endl;
      continue;
    }
    
    if(abs(start.column - end.column) == abs(start.row - end.row)) {
      cout << "1 " << (char)(start.column + 'A' - 1) << " " << start.row << " "
           << (char)(end.column + 'A' - 1) << " " << end.row << endl;
      continue;
    }
    
    Position p = getIntersection(1, start, end);
    if(!isValidPosition(p)) {
      p = getIntersection(-1, start, end);
    }
    
    cout << "2 " << (char)(start.column + 'A' - 1) << " " << start.row << " "
           << (char)(p.column + 'A' - 1) << " " << p.row << " "
           << (char)(end.column + 'A' - 1) << " " << end.row << endl;
  }

  return 0;
}
