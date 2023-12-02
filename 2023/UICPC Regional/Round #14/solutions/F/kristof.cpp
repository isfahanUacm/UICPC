// @EXPECTED_RESULTS@: CORRECT

#include <iostream>
#include <vector>

using namespace std;

struct Field{
  int x;
  int y;
  
  Field(int x, int y) : x(x), y(y) {
  }
};

struct State{
  vector<Field> fields;
  vector<Field> pegs;
};

struct Result{
  int pegs;
  int moves;
  
  vector<State> states;
};

bool isAdjacent(int x0, int y0, int x1, int y1) {
  if(x0 == x1 && (y0 == y1-1 || y0 == y1+1)) {
    return true;
  } else if(y0 == y1 && (x0 == x1-1 || x0 == x1+1)) {
    return true;
  }
  return false;
}

bool isValidMove(Field peg0, Field peg1, Field destination) {
  if(peg0.x == peg1.x && peg0.x == destination.x) {
    if((peg1.y - peg0.y) == (destination.y - peg1.y)) {
      return true;
    }
  } else if(peg0.y == peg1.y && peg0.y == destination.y) {
    if((peg1.x - peg0.x) == (destination.x - peg1.x)) {
      return true;
    }
  }
  
  return false;
}

void printState(State s) {

  int maxX = 0;
  int maxY = 0;

  for(int i = 0; i < s.fields.size(); i++) {
    if(s.fields[i].x > maxX) {
      maxX = s.fields[i].x;
    }
    if(s.fields[i].y > maxY) {
      maxY = s.fields[i].y;
    }
  }
  for(int i = 0; i < s.pegs.size(); i++) {
    if(s.pegs[i].x > maxX) {
      maxX = s.pegs[i].x;
    }
    if(s.pegs[i].y > maxY) {
      maxY = s.pegs[i].y;
    }
  }
  
  char* f = new char[(maxX+2) * (maxY+2)];
  for(int i = 0; i < (maxX+2) * (maxY+2); i++) {
    f[i] = ' ';
  }
  
  for(int i = 0; i < s.fields.size(); i++) {
    f[s.fields[i].x + s.fields[i].y*(maxX+1)] = '.';
  }
  for(int i = 0; i < s.pegs.size(); i++) {
    f[s.pegs[i].x + s.pegs[i].y*(maxX+1)] = 'o';
  }

  for(int y = 0; y < maxY+1; y++) {
    for(int x = 0; x < maxX+1; x++) {
      cout << f[x + y * (maxX+1)];
    }
    cout << endl;
  }

  delete[] f;
}

Result descend(State s, int moves) {
  Result bestResult;
  bestResult.moves = moves;
  bestResult.pegs = s.pegs.size();
  
  //cout << "Moves: " << moves << endl;
  //printState(s);

  for(int i = 0; i < s.pegs.size(); i++) {
    for(int j = 0; j < s.pegs.size(); j++) {
      if(isAdjacent(s.pegs[i].x, s.pegs[i].y, s.pegs[j].x, s.pegs[j].y)) {
        for(int k = 0; k < s.fields.size(); k++) {
          if(isValidMove(s.pegs[i], s.pegs[j], s.fields[k])) {
            //Create updated state
            State copy = s;
            copy.fields.push_back(copy.pegs[i]);
            copy.fields.push_back(copy.pegs[j]);
            copy.pegs.push_back(copy.fields[k]);
            if(i < j) {
              copy.pegs.erase(copy.pegs.begin() + j);
              copy.pegs.erase(copy.pegs.begin() + i);
            } else {
              copy.pegs.erase(copy.pegs.begin() + i);
              copy.pegs.erase(copy.pegs.begin() + j);
            }
            copy.fields.erase(copy.fields.begin() + k);
            
            if(copy.pegs.size() != s.pegs.size()-1) {
              //cout << "copy: " << copy.pegs.size() << ", s: " << s.pegs.size() << endl;
              throw "";
            }
            
            //Recursive call
            //cout << "step down" << endl;
            Result result = descend(copy, moves+1);
            
            //Update results
            if(bestResult.pegs > result.pegs) {
              bestResult = result;
            } else if (bestResult.pegs == result.pegs && bestResult.moves > result.moves) {
              bestResult = result;
            }
          }
        }
      }
    }
  }
  
  //cout << "step up" << endl;
  bestResult.states.insert(bestResult.states.begin(), s);
  return bestResult;
}

int main() {
  int n;
  
  cin >> n;
  string dummyLine;
  getline(cin, dummyLine);
  
  for(int testcase = 0; testcase < n; testcase++) {
    State initialState;
    initialState.pegs.clear();
    initialState.fields.clear();
    
    string line;
    int x = 0;
    int y = 0;
    do{
      getline(cin, line);
      
      for(int i = 0; i < line.length(); i++) {
        switch(line[i]) {
          case '#':
            break;
          case '.':
            initialState.fields.push_back(Field(x, y));
            break;
          case 'o':
            initialState.pegs.push_back(Field(x, y));
            break;
        }
          
        x++;
      }
      y++;
      x=0;
    }while(line.length() > 0);
    
    //cout << "Found " << initialState.fields.size() << " fields and " << initialState.pegs.size() << " pegs" << endl;
    //printState(initialState);
    
    //Backtracking
    Result result = descend(initialState, 0);

    for(int i = 0; i < result.states.size(); i++) {
      //cout << "Move " << i << endl;
      //printState(result.states[i]);
    }
    
    cout << result.pegs << " " << result.moves << endl;
  }
  
  return 0;
}
