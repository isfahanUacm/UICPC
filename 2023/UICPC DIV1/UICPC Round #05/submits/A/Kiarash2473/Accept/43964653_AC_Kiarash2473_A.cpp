#include <iostream>
#include <string>
using namespace std;

int main()
{
	string word;
	cin >> word;
	bool is_hiss = false;
	for (int i = 0; i < word.size() - 1; i++)
	{
		if (word[i] == 's' && word[i + 1] == 's')
		{
			is_hiss = true;
			break;
		}
	}

	if (is_hiss == true)
		cout << "hiss";
	else
		cout << "no hiss";
}