#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
#include <set>

using namespace std;

bool cpSec(const pair<int,int> &left, const pair<int,int> &right) {
    return left.second < right.second;
}

int main() {
  int n;
  cin >> n;
  vector<int> tx(n), ty(n), sx(n), sy(n);

  // Read in the tutors' and students' x and y coordinates.
  for(int i = 0; i < n; i++)
    cin >> tx[i] >> ty[i];
  for(int i = 0; i < n; i++)
    cin >> sx[i] >> sy[i];

  // Create a complete directed graph out of the locations of the tutors
  // and students. lo and hi are the limits for the binary search.
  vector<vector<pair<int,int>>> tutors(n);

  set<int> dists;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      tutors[i].push_back(make_pair(j,abs(sx[i]-tx[j])+abs(sy[i]-ty[j])));
      dists.insert(tutors[i][j].second);
    }
  }

  // Sort the adjacency lists by weights for convenience.
  for(int i = 0; i < n; i++) {
    sort(tutors[i].begin(),tutors[i].end(),cpSec);
  }
  
  // We keep track of the partial matching for the smallest n we have
  // tried. The tutor of stl[i] >= 0, then it is the tutor of student i.
  // If tsl[i] >= 0, then it is the student of tutor i.
  vector<int> stl(n,-1);
  vector<int> tsl(n,-1);

  vector<int> prev(n);

  int result;

  // We do a binary search over the possible answers.
  for(int mid : dists) {
    result = mid;
    // Try to construct a matching with edges of weight at most mid.

    // We start with a maximal matching using edges of weight at most
    // lo.
    vector<int> stm = stl, tsm = tsl;
    bool changed = true;
    while(changed) {
      changed = false;
      // We try to find augmenting paths for our matching using a depth
      // first search
      stack<int> s;
      for(int i = 0; i < n; i++) {
        if(stm[i] == -1) {
          s.push(i);
          prev[i] = -1;
        }
        else {
          prev[i] = -2;
        }
      }
      while(!s.empty() && !changed) {
        int student = s.top(); s.pop();
        for(int i = 0; i < n && tutors[student][i].second <= mid; i++) {
          int tutor = tutors[student][i].first;

          if (tsm[tutor] == -1) {
            // We have found an augmenting path (a path that ends in an
            // unassigned tutor). So we update our matching.
            changed = true;
            int tmp = stm[student];
            stm[student] = tutor;
            tsm[tutor] = student;

            while(tmp != -1) {
              student = prev[student];
              tutor = tmp;
              tmp = stm[student];
              stm[student] = tutor;
              tsm[tutor] = student;
            }

            break;
          }
          else {
            int nstd = tsm[tutor];
            if(prev[nstd] == -2) {
              // prev keeps track of the augmenting path.
              prev[nstd] = student;
              s.push(nstd);
            }
          }
        }
      }
    }
    bool matched = true;
    for(int i = 0; i < n; i++) {
      if(stm[i] == -1) {
        matched = false;
        break;
      }
    }
    if(matched) {
      break;
    }
  }

  cout << result << endl;
  return 0;
}
