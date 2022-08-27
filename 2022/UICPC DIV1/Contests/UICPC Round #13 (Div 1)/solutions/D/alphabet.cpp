/*
   Racing Around the Alphabet
   Ivor Page
*/
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <cstdio>

using namespace std;

int charToDec(char c) {
    if(c==' ')
	return 0;
    if(c=='\'')
	return 1;
    return c - 'A' + 2;
}

int findDistance(int posn1, int posn2) {
    int fwdDistance = posn2 - posn1;
    if(fwdDistance<0)
	fwdDistance = 28 + fwdDistance;
    int revDistance = posn1 - posn2;
    if(revDistance<0)
	revDistance = 28 + revDistance;
    return  min(fwdDistance, revDistance);
}

int main() {
    string line;
    int num;
    cin >> num;
    getline(cin,line);
    double spacing = 60*M_PI/28.0; // 6.731984257692414
    double timePerSpace = spacing/15.0; // 0.448798950512828
    double pickupTime = 1.0;
    double time = 0.0;
    for(int i=0;i<num;i++) {
      getline(cin,line);
      int len = line.length();
      int totDistance = 0;
      for(int j=0;j<len-1;j++) {
	int posn1 = charToDec(line[j]);
	int posn2 = charToDec(line[j+1]);
	int distance = findDistance(posn1, posn2);
	//		System.out.println("distance = " + distance);
	totDistance += distance;
      }
      time = totDistance*timePerSpace + pickupTime*len;
      printf("%.10f\n", time);
    }
}
