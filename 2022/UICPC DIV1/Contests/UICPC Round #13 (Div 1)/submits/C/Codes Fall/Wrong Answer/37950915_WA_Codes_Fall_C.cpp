#include <iostream>
#include <math.h>

using namespace std;

int main(){
	int n, c = 1;
	cin >> n;
	int *x = new int[n];
	int *y = new int[n];
	string *na = new string[n];
//	int *tmp = new int[n];
	for(int i = 0; i < n; i++)
		cin >> x[i] >> y[i] >> na[i];

	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n; j++){
			if(na[i] == na[j]){
				if(x[i]+y[i] < x[j]+y[j]){
					x[j] = x[n-c];
					y[j] = y[n-c];
					na[j] = na[n-c];
				}
				else{
					x[j] = x[n-c];
					y[j] = y[n-c];
					na[j] = na[n-c];
				}
				c++;
			}
		}
	}
	n -= c;

	int xnow{}, ynow{}, mindis, alldis{}, tnow;
	for(int i = 0; i < n; i++){
		mindis = abs(x[0]-xnow)+abs(y[0]-ynow);
		tnow = 1;
		for(int j = 1; j < n; j++){
			if(abs(x[j]-xnow)+abs(y[j]-ynow) < mindis){
				mindis = abs(x[j]-xnow)+abs(y[j]-ynow);
				tnow = j;
			}
		}
		alldis += mindis;
		xnow = x[tnow];
		ynow = y[tnow];
	}
	alldis += x[0] + y[0];
	cout << alldis << endl;
	return 0;
}


