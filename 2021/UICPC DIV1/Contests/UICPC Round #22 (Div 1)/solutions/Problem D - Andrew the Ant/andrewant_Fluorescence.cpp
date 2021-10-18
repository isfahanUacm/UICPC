#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<int,char> pr;

int l,a;
int main()
{
    while (cin>>l>>a)
    {
        pr ants[a];
        int loc;
        char dir;
        for (int i = 0; i < a; i++)
        {
            cin>>loc>>dir;
            ants[i].first=loc;
            ants[i].second=dir;
        }
        sort(ants,a+ants);
        /**for (int i = 0; i < a; i++)
        {
            cout<<ants[i].first<<"  "<<ants[i].second<<'\n';
        }**/
        int maxi = -1;
        int res[2]; res[0]=-1;res[1]=-1;
        int indx =-1;
        for (int i = 0; i < a; i++)
        {
            dir = ants[i].second;
            loc = ants[i].first;
            if (dir=='L')
            {
                maxi = max(maxi,loc);
            }
            else if (dir=='R')
            {
                maxi = max(maxi,(l-loc));
                
            }
            else cout<<"ERROR11\n";
        }
        for (int i = 0; i < a; i++)
        {
            dir = ants[i].second;
            loc = ants[i].first;
            if (dir=='L' and loc==maxi)
            {
                indx++;
                res[indx]=i;
                for (int j = i-1; j >=0; j--)
                {
                    char odir = ants[j].second;
                    if (odir == 'R')
                    {
                        res[indx]--;
                    }
                }
            }
            else if (dir=='R' and (l-loc)==maxi)
            {
                indx++;
                res[indx]=i;
                for (int j = i+1; j < a; j++)
                {
                    char odir = ants[j].second;
                    if (odir == 'L')
                    {
                        res[indx]++;
                    }
                }
            }
        }
        sort(res,res+2);
        if (indx==0)
        {
            int theant=res[1]; 
            cout<<"The last ant will fall down in "<<maxi<<" seconds - started at "<<ants[theant].first<<".\n";
        }
        else if (indx==1)
        {
            int ant1=res[0];
            int ant2=res[1]; 
            cout<<"The last ant will fall down in "<<maxi<<" seconds - started at "<<ants[ant1].first<<" and "<<ants[ant2].first<<".\n";
        }
        else cout<<"ERROR22\n";
    }
}