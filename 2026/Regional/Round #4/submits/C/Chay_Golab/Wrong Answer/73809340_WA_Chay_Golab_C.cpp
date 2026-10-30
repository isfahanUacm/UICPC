#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int a;
        cin>>a;
        int counter = 0;
        int arr[a][2];

        for (int i=0;i<a;i++)
        {
            cin>>arr[i][0]>>arr[i][1];
        }

        for(int i=0 ; i<a-1 ; i++)
        {
            for(int j=i+1;j<a ;j++ )
            {
                float m1 = (((float)(arr[i][1] - arr[j][1])) / ((float)(arr[i][0] - arr[j][0])));
                float m2 = 1/m1;
                float b1 = arr[i][1] - (m1*arr[i][0]);
                float b2 = arr[j][0] - (m2*arr[j][1]);
                if(m1 == 1 || m2 == -1){
                    if(b1 == b2)
                        ++counter;
                }   
                else{
                    float ans = (b2 - b1)/(m1 - m2);
                    if((ans >= arr[i][0] && ans<= arr[j][0]) || (ans <= arr[i][0] && ans>= arr[j][0]) )
                        ++counter;
                }
            }
        }

        cout<<counter<<endl;
    }

}