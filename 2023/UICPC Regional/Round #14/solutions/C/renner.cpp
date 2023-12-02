// @EXPECTED_RESULTS@: CORRECT

#include <iostream>
using namespace std;

int rx[] = { 1,  1 };
int ry[] = { 1, -1 };
        

bool check(char x1, char y1, int dx, int dy, int i, int j) {
  int a, b;
  b = (ry[i] * dx - rx[i] * dy) / (ry[i] * rx[j] - rx[i] * ry[j]);
  a = (dx - rx[j] * b) / (-rx[i]);

  // inside field?
  char xi = x1 + a * rx[i];
  char yi = y1 + a * ry[i];
  if (xi >= 'A' && xi <= 'H' && yi >= '1' && yi <= '8')
  {
    cout << "2 "
         << x1 << " " << y1 << " "
         << xi << " " << yi << " "
         << (char)(x1 - dx) << " " << (char)(y1 - dy) << endl;
    return true;
  }

  return false;
}

int main() {
  int C;
  cin >> C;
  while (C--) {
    char x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int dx, dy;
    dx = x1 - x2;
    dy = y1 - y2;

    // same color (possible?)
    if ((dx + dy) % 2) {
      cout << "Impossible" << endl;
      continue;
    }

    // same position?
    if (dx == 0 && dy == 0) {
      cout << "0 " << x1 << " " << y1 << endl;
      continue;
    }
    
    // one step?
    if (dx == dy || dx == -dy) {
      cout << "1 " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
      continue;
    }

    // same color -> possible in two steps
    if (! check(x1, y1, dx, dy, 0, 1)) {
      check(x1, y1, dx, dy, 1, 0);
    }
  }

  return 0;
}
