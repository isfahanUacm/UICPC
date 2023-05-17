#include <iostream>
#include <string>

using namespace std;

int main() {
	string in;
	cin >> in;

	int l = in.size()-2;
	string out = "h";
	for( int i = 0; i < l; i++ )
		out += "ee";
	out += "y";

	std::cout << out << std::endl;

	return 0;
}