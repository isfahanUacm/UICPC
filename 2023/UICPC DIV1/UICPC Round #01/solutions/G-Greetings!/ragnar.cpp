#include <iostream>
using namespace std;
int main(){
	string s;
	cin >> s;
	cout << s.front() << string((s.size()-2)*2, s[1]) << s.back() << endl;
}
