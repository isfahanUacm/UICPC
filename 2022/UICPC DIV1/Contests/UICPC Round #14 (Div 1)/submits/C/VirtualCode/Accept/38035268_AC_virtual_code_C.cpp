#include <iostream>
using namespace std;
string str[10];
bool flag;
int n;
int d[8][2] = { 2, 1, 1, 2, -1, 2, -2, 1, -2, -1, -1, -2, 1, -2, 2, -1 };
bool B(int x, int y) {
    int i = 0;
	while (i < 8) {
		int xx = x + d[i][0];
		int yy = y + d[i][1];
		if (xx >= 0 && yy >= 0 && xx < 5 && yy < 5) {
			if (str[xx][yy] == 'k'){
                return true;
            } 
		}
        i++;
	}
	return false; 
}
void get(int i){
    cin >> str[i];
}
void P(){
    n++;
}
void dis(){
    cout << "invalid" << endl;
}
void dist(){
    cout << "valid" << endl;
}
int main()
{
    int i = 0;
	while(i < 5){
		get(i);
        int j = 0;
		while(j < 5) {
			if (str[i][j] == 'k'){
                P();
            } 
            j++;
		}
        i++;
	}
	if (n != 9){
        dis();
    }else {
        int k =0;
		while (k < 5) {
            int b = 0;
			while(b < 5) {
				if (str[k][b] == 'k' && B(k, b)) {
					flag = 1;
					break;
				}
                b++;
			}
            k++;
		}
		if (flag){
            dis();
        }else{ 
            dist();
        }
	}
	return 0;
}