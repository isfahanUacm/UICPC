#include <iostream>
using namespace std;
int main(){
    int casecount;
    cin>>casecount;
    for (int i = 0; i < casecount; i++)
    {
        int playerCount=0;
        int qCount;
        long int time;
        cin>>playerCount>>qCount>>time;
        int arr[playerCount][qCount];
        for (int j = 0; j < playerCount; j++)
        {
            for (int k = 0; k < qCount; k++)
            {
                cin>>arr[j][k];
            }
        }
for(int k = 0; k<playerCount; k++){
    int temp,j;
            for(int y=1;y<qCount;y++){
        temp=arr[k][y];
        j=y-1;
        while(temp<arr[k][j]){
            arr[k][j+1]=arr[k][j];
            j--;
            if (j<0){
                break;
            }
        }
        arr[k][j+1]=temp;
    } 
}
        


    int arrpoint[playerCount][2];
    int point = 0;
    int penalty = 0;
    for (int j = 0; j < playerCount; j++)
    {
        int passedTime=0;
        arrpoint[j][0]=0;
        arrpoint[j][1]=0;
        for (int k = 0; k < qCount; k++)
        {
            
            passedTime+=arr[j][k];
            if (passedTime>time)
            {
                break;
            }
            arrpoint[j][0]+=1;
            arrpoint[j][1]+=passedTime;
        }
    }
        point=arrpoint[0][0];
        penalty=arrpoint[0][1];

        int m, temp , Ptemp;
        for(int k=1;k<playerCount;k++){
            temp=arrpoint[k][0];
            Ptemp=arrpoint[k][1];
            m=k-1;
            while(temp>arrpoint[m][0]){
                arrpoint[m+1][0]=arrpoint[m][0];
                arrpoint[m+1][1]=arrpoint[m][1];
                m--;
                if (m<0){
                    break;
                }
            }
            arrpoint[m+1][0]=temp;
            arrpoint[m+1][1]=Ptemp;
        }  
        
        for (int k = 0; k<playerCount - 1; k++){
            if(arrpoint[k][0] == arrpoint [k+1][0]){
                if (arrpoint[k+1][1] < arrpoint[k][1]){
                    temp=arrpoint[k][1];
                    arrpoint[k][1]=arrpoint[k+1][1];
                    arrpoint[k+1][1]=temp;
                    temp=arrpoint[k][0];
                    arrpoint[k][0]=arrpoint[k+1][0];
                    arrpoint[k+1][0]=temp;
                }
            }
        }
        
        
        for (int f = 0; f < playerCount; f++)
        {
        if (arrpoint[f][0]==point && arrpoint[f][1]==penalty)
        {
            cout<<f+1<<endl;
            break;
        }
        }
    }
    
    
    return 0;
}