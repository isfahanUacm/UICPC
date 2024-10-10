#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, students;
        cin >> n >> students;
        char results[n]={'?'};
        char a[n]={'O'}, b[n]={'O'}, c[n]={'O'}, d[n]={'O'};
        for (int i = 0; i < students; i++)
        {
            for (int j = 0; j < n; j++)
            {
                char inp;
                char sol;
                cin >> inp;
                cin >> sol;
                switch (inp)
                {
                case 'A':
                    if (a[j] != 'T')
                        a[j] = sol;
                        break;
                case 'B':
                    if (b[j] != 'T')
                        b[j] = sol;
                        break;
                case 'C':
                    if (c[j] != 'T')
                        c[j] = sol;
                        break;
                case 'D':
                    if (d[j] != 'T')
                        d[j] = sol;
                        break;
                default:
                    break;
                }
            }

        }
        for(int i=0;i<n;i++){
            if(a[i]=='T'){
                results[i] = 'A';
            }
            else if(b[i]=='T'){
                results[i] = 'B';
            }
            else if(c[i]=='T'){
                results[i] = 'C';
            }
            else if(d[i]=='T'){
                results[i] = 'D';
            }
            else if(a[i]=='F'&&b[i]=='F'&&c[i]=='F'){
                results[i] = 'D';
            }
            else if(a[i]=='F'&&b[i]=='F'&&d[i]=='F'){
                results[i] = 'C';
            }
            else if(a[i]=='F'&&d[i]=='F'&&c[i]=='F'){
                results[i] = 'B';
            }
            else if(d[i]=='F'&&b[i]=='F'&&c[i]=='F'){
                results[i] = 'A';
            }else results[i]= '?';
        }
        for(int i=0;i<n;i++){
            cout<<results[i]<<" ";
        }cout<<endl;
    }
    return 0;
}