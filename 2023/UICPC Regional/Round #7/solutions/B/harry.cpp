#include <iostream> // strings/streams
#include <vector> 
#include <random>
#include <ctime>

using namespace std;

int main()
{
	string s; 
	cin >> s; 
	int n = s.length();
	for(int i = 0; i < n; i++)
	{
		if(i < n - 2 && s[i] + s[i+1] + s[i+2] == 'B' + 'L' + 'R')
		{
			cout << 'C';
			i += 2;
		}
		else if(s[i] == 'B')
			cout << 'K';
		else if(s[i] == 'L')
			cout << 'H';
		else if(s[i] == 'R')
			cout << 'S';		
	}
	cout << endl;

	return 0; 
}