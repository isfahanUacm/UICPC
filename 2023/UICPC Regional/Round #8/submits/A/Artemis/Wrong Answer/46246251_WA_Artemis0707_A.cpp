#include<bits/stdc++.h>
using namespace std;
using ll = long long;

char play1[40][40], play2[40][40];

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
                cin>>play1[i][j];
                if(play1[i][j] == '#') ship_num1++;
            }
        }
        for(int j=h-1;j>=0;j--){
            for(int i=0;i<w;i++){
                cin>>play2[i][j];
                if(play2[i][j] == '#') ship_num2++;
            }
        }
        for(int i=0;i<shots;i++)
            cin>>sht_cor[i].first >> sht_cor[i].second;
        
        int numtrn_play1 =0 , numtrn_play2=0;
        int turn =0;
        bool fnd =0;
        
        for(int i=0;i<shots;i++){
            if(numtrn_play1 == numtrn_play2 && numtrn_play1!=0){
                if(ship_num1 == 0 && ship_num2==0){
                    cout<<"draw"<<endl;
                    break;
                }
                else if(ship_num1 == 0){
                    cout<<"player two wins\n";
                    fnd =1;
                    break;
                }
                else if (ship_num2 == 0){
                    cout<<"player one wins\n";
                    fnd =1;
                    break;
                }
            }
            if(turn == 0){
                numtrn_play1++;
                if(play2[sht_cor[i].first][sht_cor[i].second] != '#'){
                    turn = 1;
                }
                else{
                    ship_num2--;
                    play2[sht_cor[i].first][sht_cor[i].second] = '_';
                }
            }
            else if( turn ==1){
                numtrn_play2++;
                if(play1[sht_cor[i].first][sht_cor[i].second] != '#'){
                    turn = 0;
                }
                else{
                    ship_num1--;
                    play1[sht_cor[i].first][sht_cor[i].second] = '_';
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
    }
    
    return 0;
}