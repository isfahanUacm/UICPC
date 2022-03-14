#include <bits/stdc++.h>
using namespace std;

// Bitcoin Toss

int t, i, len, p, j, mask, k, ssize;
char s[20003];
set<int> perms;
bool ans, valid;

int main(){
    scanf("%d\n", &t);
    while(t--){
        scanf("%s\n", s);
        ssize = strlen(s);
        for(i = 10; i > 0; i--){
            ans = false;
            len = (1 << i) * i;
            for(p = 0; p <= ssize - len; p++){
                perms.clear();
                valid = true;
                for(j = 0; j < len; j += i){
                    mask = 0;
                    for(k = 0; k < i; k++)
                        if(s[p + j + k] == 'H')
                            mask += (1 << k);
                    if(perms.find(mask) != perms.end()){
                        valid = false;
                        break;
                    }
                    else
                        perms.insert(mask);
                }
                if(valid){
                    ans = true;
                    break;
                }
            }
            if(ans){
                printf("%d %d\n", i, p);
                break;
            }
        }
    }
}