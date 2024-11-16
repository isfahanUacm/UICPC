#include <bits/stdc++.h>


using namespace std;

int main()
{
    int n;
    cin >> n;
    string text , answer;
    int index = int('a');
    for(int i = 0 ; i < n ; i++){
        text += char(index);
        index++;
        if(index > int('z')){
            index = int('a');
        }
    }
    cout << "? " << text << endl;
    cout.flush();
    cin >> answer;
    cout << "! ";
    int arr[n];
    for(int i = 0 ; i < n ; i++){
        arr[i] = 0;
    }
    for(int i = 0 ; i < n ; i++){
        if(answer[i] == text[i] ){
            if(arr[i] == 0){
                arr[i] = i + 1;
            }
        }
        else{
            for(int j = i / 2 ; j < n ; j++){
                if(answer[i] == text[j]){
                    arr[i] = j + 1;
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
