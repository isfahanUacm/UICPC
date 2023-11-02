/*
  Sample solution for NCPC 2010: Polyomino
  Author: Marcus Isaksson
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

int h,w;
vector<string> P,T;

bool findFirst(vector<string> &Z, char a, int &r, int &c) {
  for (r=0; r<h; r++)
    for (c=0; c<w; c++)
      if (Z[r][c]==a) return true;
  return false;
}

bool color(int dr, int dc, char from, char to) {
  for (int r=0; r<h; r++)
    for (int c=0; c<w; c++)
      if (T[r][c]==from) {
          int r2=r+dr, c2=c+dc;
          if (r2<0 || r2>=h || c2<0 || c2>=w) return false;
          if (T[r2][c2] != 'X') return false;
          T[r2][c2] = to;
      }
  return true;
}

int tot, k;
vector<int> firstR, firstC;

int floodfill(int r, int c, char from, char to) {
  if (r<0 || c<0 || r>=h || c>=w || T[r][c]!=from) return 0;
  T[r][c]=to;
  return (1+floodfill(r+1,c,from,to)+floodfill(r-1,c,from,to)+
          floodfill(r,c-1,from,to)+floodfill(r,c+1,from,to));
}

bool label() {
  for (int r=0; r<h; r++) 
    for (int c=0; c<w; c++)
      if (T[r][c]=='X') {
        for(int i=0; i<k; i++) {
          int r2=r+firstR[i]-firstR[0];
          int c2=c+firstC[i]-firstC[0];
          if (r2>=h || c2>=w || T[r2][c2] != 'X') return false;
          T[r2][c2]=('1'+i);
        }
      }
  if (floodfill(firstR[0], firstC[0], '1', '0')==tot/k) {
    floodfill(firstR[0], firstC[0], '0', '1');
    return true;
  }
  return false;
}

bool chooseFirstsDFS(int i) {
  if (i==k) {
    if (firstR[1]==0 && firstC[1]==3 &&
        firstR[2]==3 && firstC[2]==0 &&
        firstR[3]==3 && firstC[3]==4) {
    }
    T=P;
    return label();
  }

  int r=firstR[i-1]-1, c=firstC[i-1];
  while (++r<h) {
    while (++c<w) {
      if (P[r][c]=='X') {
        firstR[i]=r; firstC[i]=c;
        if (chooseFirstsDFS(i+1)) return true;
      }
    }
    c=-1;
  }

  return false;
}

bool chooseFirsts() {
  firstR=firstC=vector<int>(k);
  findFirst(P,'X',firstR[0],firstC[0]);
  return chooseFirstsDFS(1);
}

int main() {
  cin >> h >> w;
  P.resize(h);
  tot=0;
  for(int r=0; r<h; r++) {
    cin >> P[r];
    for(int c=0; c<w; c++)
      if (P[r][c]=='X') tot++;
  }

  for(k=2; k<=5; k++)
    if (tot%k==0) {
      if (chooseFirsts()) {
        for(int r=0; r<h; r++) 
          cout << T[r] << endl;
        return 0;
      }
    }

  cout << "No solution" << endl;
}
