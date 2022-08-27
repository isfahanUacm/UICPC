#include <stdio.h>
#include <stdlib.h>

void getter(int &ctr){
scanf("%d\n", &ctr);
}
void get2(char &curr){
scanf("%c\n", &curr);
}
void Do(int ctr){
    char str[ctr], curr;
    int i = 0;
    while (i < ctr)
    {
        get2(curr);
		str[i] = curr == 'Z' ? '0' : '1';
        i++;
    }
	str[ctr] = '\0';
	printf("%ld", strtol(str, NULL, 2));
}
int main(void) {
	int ctr = 0;
	getter(ctr);
    Do(ctr);
}