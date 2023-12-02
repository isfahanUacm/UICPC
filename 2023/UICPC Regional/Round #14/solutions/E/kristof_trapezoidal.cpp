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

double integrateTrapezoidal(const FlowerPot& pot) {
  int numberOfSteps = ceil(pot.h / 1e-5);
  double dx = pot.h/(double)numberOfSteps;
  double volume = 0.0;
  
  double oldValue = function(pot, 0.0);
  
  for(int step = 1; step < numberOfSteps + 1; step++) {
    double x = step * dx;
    double newValue = function(pot, x);
    double value = (oldValue + newValue) / 2.0;
    volume += value * dx;
    
    oldValue = newValue;
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
    
    double volume = integrateTrapezoidal(pot);
    
    //std::cout << "volume= " << setprecision(12) << volume << std::endl;
    
    if(abs(volume - v) < abs(bestVolume -v)) {
      bestVolume = volume;
      bestIndex = i;
    }
  }
  
  cout << bestIndex << endl;

  return 0;
}

