// @EXPECTED_RESULTS@: CORRECT

#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>

using namespace std;

const double PI = 3.141592653589793238463;

struct FlowerPot {
  double a;
  double b;
  double h;
};

double function(const FlowerPot& pot, double x) {
  double value = pot.a * exp(-x*x) + pot.b * sqrt(x);
  return value * value * PI;
}

double integrateSimpson(const FlowerPot& pot) {
  int numberOfSteps = ceil(pot.h / 1e-4);
  double dx = pot.h/(double)numberOfSteps;
  double volume = 0.0;
  
  double value0 = function(pot, 0.0);
  for(int step = 0; step < numberOfSteps; step++) {
    double x0 = step * dx;
    double x1 = x0 + dx/2.0;
    double x2 = x0 + dx;
    double value1 = function(pot, x1);
    double value2 = function(pot, x2);
    double value = (value0 + 4.0 * value1 + value2) /6.0;
    volume += value * dx;
    
    value0 = value2;
  }

  //cout << setprecision(12) << "volume: " << volume << endl;
  
  return volume;
}

int main() {

  double v;
  cin >> v;
  int n;
  cin >> n;

  double bestVolume = -numeric_limits<double>::max();
  int bestIndex = -1;
  
  for (int i = 0; i < n; i++) {
    FlowerPot pot;
    cin >> pot.a;
    cin >> pot.b;
    cin >> pot.h;
    
    double volume = integrateSimpson(pot);
    
    if(abs(volume - v) < abs(bestVolume -v)) {
      bestVolume = volume;
      bestIndex = i;
    }
  }
  
  cout << bestIndex << endl;

  return 0;
}

