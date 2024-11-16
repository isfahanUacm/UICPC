#include <bits/stdc++.h>


using namespace std;

int main()
{
    int n;
    cin >> n;
    string text[4] , answer[4];
    int index = int('a');
    for(int i = 0 ; i < n ; i++){
        text[0] += char(index);
        index++;
        if(index > int('z')){
            index = int('a');
        }
    }
    index = int('h');
    for(int i = 0 ; i < n ; i++){
        text[1] += char(index);
        index++;
        if(index > int('z')){
            index = int('a');
        }
    }
    index = int('n');
    for(int i = 0 ; i < n ; i++){
        text[2] += char(index);
        index++;
        if(index > int('z')){
            index = int('a');
        }
    }
    index = int('v');
    for(int i = 0 ; i < n ; i++){
        text[3] += char(index);
        index++;
        if(index > int('z')){
            index = int('a');
        }
    }
    for(int i = 0 ; i < 4 ; i++){
        cout << "? " << text[i] << endl;
    }
    cout.flush();
    for(int i = 0 ; i < 4 ; i++){
        cin >> answer[i];
    }
    cout << "! ";
    int arr[n];
    for(int i = 0 ; i < n ; i++){
        arr[i] = 0;
    }
    for(int k = 0 ; k < 4 ; k++){
        for(int i = 0 ; i < n ; i++){
            if(answer[k][i] == text[k][i] ){
                if(arr[i] == 0){
                    arr[i] = i + 1;
                }
            }
            else{
                for(int j = i + 1 ; j < n ; j++){
                    if(answer[k][i] == text[k][j]){
                        arr[i] = j + 1;
                        arr[j] = i + 1;
                    }
                }
            }
        }
    }
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
