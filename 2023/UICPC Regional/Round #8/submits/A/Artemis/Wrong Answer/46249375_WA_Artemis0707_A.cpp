#include<bits/stdc++.h>
using namespace std;
using ll = long long;

char play1[40][40], play2[40][40];

bool finsih(int ship_num1 , int ship_num2){
        if(ship_num1 == 0 && ship_num2==0){
            cout<<"draw"<<endl;
            return 1;
        }
        else if(ship_num1 == 0){
            cout<<"player two wins\n";
            return 1;
        }
        else if (ship_num2 == 0){
            cout<<"player one wins\n";
            return 1;
        }
    return 0;
}
int main(){
    int t;
    cin>>t;
    int w, h, shots;
    while(t--){
        cin>>w>>h>>shots;
        pair<int,int>sht_cor[shots];
        int ship_num1 =0, ship_num2=0;

        for(int j=h-1;j>=0;j--){
            for(int i=0;i<w;i++){
                cin>>play1[j][i];
                if(play1[j][i] == '#') ship_num1++;
            }
        }
        for(int j=h-1;j>=0;j--){
            for(int i=0;i<w;i++){
                cin>>play2[j][i];
                if(play2[j][i] == '#') ship_num2++;
            }
        }
        for(int i=0;i<shots;i++)
            cin>>sht_cor[i].second >> sht_cor[i].first;
        
        int turn =0;
        bool fnd =0;
        // bool turn1 = 0, turn2 =0;
        
        for(int i=0;i<shots;i++){
            if(turn == 0){
                if(play2[sht_cor[i].first][sht_cor[i].second] != '#'){
                    turn = 1;
                }
                else{
                    ship_num2--;
                    play2[sht_cor[i].first][sht_cor[i].second] = '_';
                }
            }
            else if( turn == 1){
                if(play1[sht_cor[i].first][sht_cor[i].second] != '#'){
                    turn = 0;
                    fnd = finsih(ship_num1 ,  ship_num2);
                    if(fnd) break;
                }
                else{
                    ship_num1--;
                    play1[sht_cor[i].first][sht_cor[i].second] = '_';
                    fnd = finsih(ship_num1 ,  ship_num2);
                    if(fnd)break;
                }
            }
        }
        if(!fnd){
            if(ship_num1 == 0 && ship_num2==0){
                    cout<<"draw"<<endl;
                }
                else if(ship_num1 == 0){
                    cout<<"player two wins\n";
                }
                else if (ship_num2 == 0){
                    cout<<"player one wins\n";
                }
                else {
                    cout<<"draw"<<endl;
                }
        }
        // cerr<<numtrn_play1 <<' ' << numtrn_play2 <<' '<< ship_num1<<' '<< ship_num2<<endl;
    }
    
    return 0;
}