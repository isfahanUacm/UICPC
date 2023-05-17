#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
	string s, t;
	cin >> s;
	cout << regex_replace( s, regex("e"), "ee" ); 
}
