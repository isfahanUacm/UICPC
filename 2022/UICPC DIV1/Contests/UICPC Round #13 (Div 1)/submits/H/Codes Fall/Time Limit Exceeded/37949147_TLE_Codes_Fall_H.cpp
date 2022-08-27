#include <iostream>

using namespace std;

int main()
{
	int n, count{};
	char c;
	cin >> n;
	int *x = new int[n];
	for(int i = 0; i < n; i++){
		cin >> c;
		if(c == 'Z')
			x[i] = 0;
		else
			x[i] = 1;
	}
	for(int i = n-1; i >= 0; i--){
		if(x[i] == 1){
			x[i] = 0;
			for(int j = i+1; j <= n-1; j++)
				x[j] = 1;
			i = n;
			count++;
		}

	}

	cout << count << endl;
	return 0;
}


