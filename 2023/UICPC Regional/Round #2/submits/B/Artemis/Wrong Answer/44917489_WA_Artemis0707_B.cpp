#include <iostream>
#include <vector>
using namespace std;


struct Word {
  int h1;
  int h2; 
};


vector<Word> read_input(int n, int m) {
  vector<Word> words(n); 
  for (int i = 0; i < n; i++) {
    cin >> words[i].h1 >> words[i].h2; 
    words[i].h1 %= m; 
    words[i].h2 %= m;
  }
  return words; 

}
bool insert(Word w, vector<int>& table, vector<bool>& visited) {
  int pos = w.h1; 
  for (int i = 0; i < 2; i++) { 
    if (table[pos] == -1) { 
      table[pos] = w.h1 + w.h2;
      return true;
    }
    else if (visited[pos]) { 
      return false; 
    }
    else { 
      visited[pos] = true; 
      int temp = table[pos];
      table[pos] = w.h1 + w.h2;
      w.h1 = temp - w.h2; 
      w.h2 = temp - w.h1;
      pos = w.h2; 
    }
  }
  return false; 
}


bool check(vector<Word>& words, int m) {
  vector<int> table(m, -1);
  vector<bool> visited(m, false); 
  for (Word w : words) { 
    if (!insert(w, table, visited)) { 
      return false; 
    }
  }
  return true; 
}


void print_output(int n, int m) {
  vector<Word> words = read_input(n, m); 
  if (check(words, m)) { 
    cout << "successful hashing" << endl; 
  }
  else {
    cout << "rehash necessary" << endl; 
  }
}


int main() {
  int t; 
  cin >> t;
  while (t--) { 
    int n, m; 
    cin >> n >> m;
    print_output(n, m);
  }
  return 0;
}
