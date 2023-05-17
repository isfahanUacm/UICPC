#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string* arr = new string[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int par_counter = 0;
	int max_par = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i][0] == '(')
			par_counter++;
		if (arr[i][0] == ')')
			par_counter--;
		if (par_counter > max_par)
			max_par = par_counter;
	}

	//cout << max_par;

	vector<long long int> result;
	long long int hasel = 0;
	for (int k = max_par; k > 0; k--)
	{
		//cout << k << " kkkkkkkkkkkkk";
		/*
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl << max_par <<endl;
		*/
		
		par_counter = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i][0] == '(')
				par_counter++;
			if (arr[i][0] == ')')
				par_counter--;
			if (par_counter == k && arr[i][0] == '(')
			{
				i++;
				if (k % 2 == 0)
				{
					//cout << arr[5][0];
					long long int tmp = 0;
					while (arr[i][0] != ')')
					{
						//cout << i << " gggggggggggggggggggggg" << endl;
						tmp += stoi(arr[i]);
						tmp %= 1000000007;
						i++;
					}
					result.push_back(tmp);
					//cout << i << " gggggggggggggggggggggg" << endl;
				}
				if (k % 2 == 1)
				{
					long long int tmp = 1;
					while (arr[i][0] != ')')
					{
						tmp *= stoi(arr[i]);
						tmp %= 1000000007;
						i++;
					}
					result.push_back(tmp);
				}
				par_counter--;
			}
		}
		//cout << "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh" << endl;
		///////////////////////////////////////////////////////////
		par_counter = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i][0] == '(')
				par_counter++;
			if (arr[i][0] == ')')
				par_counter--;
			if (par_counter == k && arr[i][0] == '(')
			{
				if (k % 2 == 0)
				{
					while (arr[i][0] != ')')
					{
						arr[i] = "1";
						i++;
					}
					arr[i] = to_string(result[result.size() - 1]);
					result.pop_back();
				}
				if (k % 2 == 1)
				{
					while (arr[i][0] != ')')
					{
						arr[i] = "0";
						i++;
					}
					arr[i] = to_string(result[result.size() - 1]);
					result.pop_back();
				}
				par_counter--;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		hasel += stoi(arr[i]);
		hasel %= 1000000007;
	}

	cout << hasel;
}