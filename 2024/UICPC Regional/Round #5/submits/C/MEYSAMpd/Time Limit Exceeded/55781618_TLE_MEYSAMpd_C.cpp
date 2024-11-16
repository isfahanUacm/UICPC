#include <iostream>
#include <string>

using namespace std;

int main()
{
    int test , tour , up , size , update;
    cin >> test;
    for(int i = 0 ; i < test ; i++){
        cin >> tour >> up;
        size = tour;
        int arr[tour];
        for(int i = 0 ; i < tour ; i ++){
            cin >> arr[i];
        }
        for(int i1 = 0 ; i1 < up ; i1++){
            cin >> update;
            int upd[update/2];
            int index = update/2 - 1;
            for(int j = 0 ; j < update ; j ++){
                if(j % 2 == 0){
                    arr[j] = 0;
                    size --;
                }
                else{
                    if(j < update){
                        upd[index] = arr[j];
                        arr[j] = 0;
                        index--;
                    }
                }
            }
            for(int i = 0 ; i < update / 2 ; i++){
                arr[i] = upd[i];
            }
            for(int j = 1 ; j < tour ; j ++){
                if(arr[j] != 0){
                    while(arr[j - 1] == 0){
                        arr[j - 1] = arr[j];
                        arr[j] = 0;
                        j --;
                    }
                }
            }
        }
        for(int j = 0 ; j < size ; j ++){
            if(arr[j] != 0){
                cout << arr[j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
