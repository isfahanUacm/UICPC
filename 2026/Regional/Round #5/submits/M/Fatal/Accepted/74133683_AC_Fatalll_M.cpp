#include <iostream>
#include <cmath>
using namespace std;
int main(){
    char weapon1, weapon2;
    int p, h;
    cin >> weapon1 >> weapon2;
    cin >> p >> h;
    if(weapon1 == 'W' && weapon2 == 'F'){
        if(max(0, h-(p*2)) == 0){
            cout << "Nocaute!";
            return 0;
        }
        else{
            int x = max(0, h-(p*2));
            cout << "Sobraram " << x << " pontos de vida!";
        }
    }
    else if(weapon1 == 'F' && weapon2 == 'G'){
        if(max(0, h-(p*2)) == 0){
            cout << "Nocaute!";
            return 0;
        }
        else{
            int x = max(0, h-(p*2));
            cout << "Sobraram " << x << " pontos de vida!";
        }
    }
    else if(weapon1 == 'G' && weapon2 == 'W'){
        if(max(0, h-(p*2)) == 0){
            cout << "Nocaute!";
            return 0;
        }
        else{
            int x = max(0, h-(p*2));
            cout << "Sobraram " << x << " pontos de vida!";
        }
    }
    else{
        if(max(0, h-(p/2)) == 0){
            cout << "Nocaute!";
            return 0;
        }
        else{
            int x = max(0, h-(p/2));
            cout << "Sobraram " << x << " pontos de vida!";
        }
    }
}