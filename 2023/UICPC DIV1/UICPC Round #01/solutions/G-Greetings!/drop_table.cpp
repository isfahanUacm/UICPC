#include <iostream>
#include <string.h>

using namespace std;
int main(){
	char s[2001];
	cin.get(s, 1001);
	for(int i=1; i < strlen(s); ++i){
		if(strchr("e", s[i])){
			for(int j = strlen(s)+1; j > i; --j){
				s[j] = s[j-1];
			}
			++i;
		}
	}
	cout << s << '\n';
	return 0;
}
