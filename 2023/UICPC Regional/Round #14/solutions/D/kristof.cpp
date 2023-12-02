// @EXPECTED_RESULTS@: CORRECT

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>

using namespace std;

struct Position {
  int x;
  int y;
  bool visited;
  
  vector<int> reachables;
};

double getDistance(Position& p1, Position& p2) {
  return abs(p1.x-p2.x) + abs(p1.y-p2.y);
}

int main() {

  int testcases;
  cin >> testcases;
  
  Position positions[200];
  
  for(int testcase = 0; testcase < testcases; testcase++) {
    int n;
    cin >> n;
    
    cin >> positions[0].x;
    cin >> positions[0].y;
    
    for(int i = 1; i < n+1; i++) {
      cin >> positions[i].x;
      cin >> positions[i].y;
    }
    
    cin >> positions[n+1].x;
    cin >> positions[n+1].y;
    
    for(int i = 0; i < n+2; i++) {
      positions[i].visited = false;
      positions[i].reachables.clear();
          
      for(int j = 0; j < i; j++) {
        if(getDistance(positions[i], positions[j]) <= 1000.00001) {
          Position& pI = positions[i];
          pI.reachables.push_back(j);
          Position& pJ = positions[j];
          pJ.reachables.push_back(i);
        }
      }
    }
    
    //cout << "----------------------" << endl;
    
    //BFS
    bool foundSolution = false;
    queue<int> q;
    q.push(0);
    
    while(!q.empty()) {
      int currentIndex = q.front();
      q.pop();
      Position& p = positions[currentIndex];
      p.visited = true;
      
      //cout << "Visiting " << p.x << ", " << p.y << endl;
      
      if(p.x == positions[n+1].x && p.y == positions[n+1].y) {
        foundSolution = true;
        break;
      }
      
      for(int i = 0; i < p.reachables.size(); i++) {
        if(!positions[p.reachables[i]].visited) {
          //cout << "Pushing " << p.reachables[i] << ": " << positions[p.reachables[i]].x << ", " << positions[p.reachables[i]].y << endl;
        
          q.push(p.reachables[i]);
        }
      }
    }
    
    if(foundSolution) {
      cout << "happy" << endl;
    } else {
      cout << "sad" << endl;
    }
  }

  return 0;
}
