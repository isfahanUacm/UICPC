#include <iostream>
#include <string>
using namespace std;

int main()
{
	string row[5];
	for (int i = 0; i < 5; i++)
	{
		getline(cin, row[i]);
	}

	int digit_num = (row[0].size() / 4) + 1;

	int result = 0;
	for (int i = 0; i < row[0].size(); i += 4)
	{
		if (row[0][i] == '*' && row[0][i + 1] == '*' && row[0][i + 2] == '*' && row[1][i] == '*' && row[1][i + 1] == ' ' && row[1][i + 2] == '*' && row[2][i] == '*' && row[2][i + 1] == ' ' && row[2][i + 2] == '*' && row[3][i] == '*' && row[3][i + 1] == ' ' && row[3][i + 2] == '*' && row[4][i] == '*' && row[4][i + 1] == '*' && row[4][i + 2] == '*')
		{
			result *= 10;
			result += 0;
		}
		else if (row[0][i] == ' ' && row[0][i + 1] == ' ' && row[0][i + 2] == '*' && row[1][i] == ' ' && row[1][i + 1] == ' ' && row[1][i + 2] == '*' && row[2][i] == ' ' && row[2][i + 1] == ' ' && row[2][i + 2] == '*' && row[3][i] == ' ' && row[3][i + 1] == ' ' && row[3][i + 2] == '*' && row[4][i] == ' ' && row[4][i + 1] == ' ' && row[4][i + 2] == '*')
		{
			result *= 10;
			result += 1;
		}
		else if (row[0][i] == '*' && row[0][i + 1] == '*' && row[0][i + 2] == '*' && row[1][i] == ' ' && row[1][i + 1] == ' ' && row[1][i + 2] == '*' && row[2][i] == '*' && row[2][i + 1] == '*' && row[2][i + 2] == '*' && row[3][i] == '*' && row[3][i + 1] == ' ' && row[3][i + 2] == ' ' && row[4][i] == '*' && row[4][i + 1] == '*' && row[4][i + 2] == '*')
		{
			result *= 10;
			result += 2;
		}
		///////////////////////////////////////////////////////////////////////
		else if (row[0][i] == '*' && row[0][i + 1] == '*' && row[0][i + 2] == '*' && row[1][i] == ' ' && row[1][i + 1] == ' ' && row[1][i + 2] == '*' && row[2][i] == '*' && row[2][i + 1] == '*' && row[2][i + 2] == '*' && row[3][i] == ' ' && row[3][i + 1] == ' ' && row[3][i + 2] == '*' && row[4][i] == '*' && row[4][i + 1] == '*' && row[4][i + 2] == '*')
		{
			result *= 10;
			result += 3;
		}
		else if (row[0][i] == '*' && row[0][i + 1] == ' ' && row[0][i + 2] == '*' && row[1][i] == '*' && row[1][i + 1] == ' ' && row[1][i + 2] == '*' && row[2][i] == '*' && row[2][i + 1] == '*' && row[2][i + 2] == '*' && row[3][i] == ' ' && row[3][i + 1] == ' ' && row[3][i + 2] == '*' && row[4][i] == ' ' && row[4][i + 1] == ' ' && row[4][i + 2] == '*')
		{
			result *= 10;
			result += 4;
		}
		else if (row[0][i] == '*' && row[0][i + 1] == '*' && row[0][i + 2] == '*' && row[1][i] == '*' && row[1][i + 1] == ' ' && row[1][i + 2] == ' ' && row[2][i] == '*' && row[2][i + 1] == '*' && row[2][i + 2] == '*' && row[3][i] == ' ' && row[3][i + 1] == ' ' && row[3][i + 2] == '*' && row[4][i] == '*' && row[4][i + 1] == '*' && row[4][i + 2] == '*')
		{
			result *= 10;
			result += 5;
		}
		///////////////////////////////////////////////////////////////////////
		else if (row[0][i] == '*' && row[0][i + 1] == '*' && row[0][i + 2] == '*' && row[1][i] == '*' && row[1][i + 1] == ' ' && row[1][i + 2] == ' ' && row[2][i] == '*' && row[2][i + 1] == '*' && row[2][i + 2] == '*' && row[3][i] == '*' && row[3][i + 1] == ' ' && row[3][i + 2] == '*' && row[4][i] == '*' && row[4][i + 1] == '*' && row[4][i + 2] == '*')
		{
			result *= 10;
			result += 6;
		}
		else if (row[0][i] == '*' && row[0][i + 1] == '*' && row[0][i + 2] == '*' && row[1][i] == ' ' && row[1][i + 1] == ' ' && row[1][i + 2] == '*' && row[2][i] == ' ' && row[2][i + 1] == ' ' && row[2][i + 2] == '*' && row[3][i] == ' ' && row[3][i + 1] == ' ' && row[3][i + 2] == '*' && row[4][i] == ' ' && row[4][i + 1] == ' ' && row[4][i + 2] == '*')
		{
			result *= 10;
			result += 7;
		}
		else if (row[0][i] == '*' && row[0][i + 1] == '*' && row[0][i + 2] == '*' && row[1][i] == '*' && row[1][i + 1] == ' ' && row[1][i + 2] == '*' && row[2][i] == '*' && row[2][i + 1] == '*' && row[2][i + 2] == '*' && row[3][i] == '*' && row[3][i + 1] == ' ' && row[3][i + 2] == '*' && row[4][i] == '*' && row[4][i + 1] == '*' && row[4][i + 2] == '*')
		{
			result *= 10;
			result += 8;
		}
		///////////////////////////////////////////////////////////////////////
		else if (row[0][i] == '*' && row[0][i + 1] == '*' && row[0][i + 2] == '*' && row[1][i] == '*' && row[1][i + 1] == ' ' && row[1][i + 2] == '*' && row[2][i] == '*' && row[2][i + 1] == '*' && row[2][i + 2] == '*' && row[3][i] == ' ' && row[3][i + 1] == ' ' && row[3][i + 2] == '*' && row[4][i] == '*' && row[4][i + 1] == '*' && row[4][i + 2] == '*')
		{
			result *= 10;
			result += 9;
		}
		else
		{
			result = 1;
			break;
		}
	}
	if (result % 6 == 0)
		cout << "BEER!!";
	else
		cout << "BOOM!!";
}