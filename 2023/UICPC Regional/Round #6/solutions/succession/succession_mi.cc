/*
  Sample solution for NCPC 2010: Succession
  Author: Marcus Isaksson
*/

#include <cstring>
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

map<string, pair<string, string> > parents;
map<string, double> blood;
string founder;

double royalBlood(string name) {
  if (blood.find(name) != blood.end())
    return blood[name];

  blood[name]=0.0;
  double& val = blood[name];

  if (name == founder)
    val = 1.0;
  else if (parents.find(name) != parents.end())
    val = (royalBlood(parents[name].first)+royalBlood(parents[name].second))/2;

  return val;
}

int main() {
  int nRelations, nClaims;
  cin >> nRelations >> nClaims >> founder;
  for (int i=0; i<nRelations; i++) {
    string parent1, parent2, child;
    cin >> child >> parent1 >> parent2;
    parents[child] = make_pair(parent1, parent2);
  }
  string mostRelated;
  double mostRelatedBlood=0.0;
  for (int i=0; i<nClaims; i++) {
    string name;
    cin >> name;
    double blood=royalBlood(name);
    if (mostRelatedBlood<blood || mostRelated=="") {
      mostRelatedBlood=blood;
      mostRelated=name;
    }
  }
  cout << mostRelated << endl;
}
