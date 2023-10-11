#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<unsigned long long> stick(n);

  for(int i = 0; i < n; i++)
    cin >> stick[i];

  // Sort our sticks.
  sort(stick.begin(),stick.end());

  // Check for consecutive sticks whether they form a triangle together.
  bool maketriangle = false;
  for(int i = 0; i + 2 < n; i++) {
    unsigned long long longest = max(stick[i],max(stick[i+1],stick[i+2]));
    if(stick[i] + stick[i+1] + stick[i+2] - longest > longest) {
      maketriangle = true;
      break;
    }
  }

  if(maketriangle)
    cout << "possible" << endl;
  else
    cout << "impossible" << endl;
  return 0;
}
