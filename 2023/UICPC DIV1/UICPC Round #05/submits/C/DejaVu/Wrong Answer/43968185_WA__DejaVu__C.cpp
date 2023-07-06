#include<bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define pb push_back
set<int> s;

vector<int> primeFactors(int n)
{
    s.clear();
    vector<int> v;
    while (n % 2 == 0)
    {
        v.pb(2);
        s.insert(2);
        n = n/2;
    }


    for (int i = 3; i <= sqrt(n); i = i + 2)
    {


        while (n % i == 0)
        {
            v.pb(i);
            s.insert(i);
            n = n/i;
        }
    }

    if (n > 2)
        v.pb(n);
        s.insert(n);

    return v;
}

void output(int n,string starter, vector<int> v)
{
    if(s.size()>2)
    {
        cout<<"tie"<<endl;
        return;
    }

    else if(s.size()==2)
    {
        int val;
        val=v[0];
        int i=0;
        int freq = count(v.begin(), v.end(), val);
        //cout<<"frequecy "<<val<<"is"<<freq<<endl;
        while(v[i]==val)
        {
            i++;
        }
        val=v[i];
        int freq2 = count(v.begin(), v.end(), val);
        //cout<<"frequecy "<<val<<"is"<<freq2<<endl;
        if(freq==freq2)
        {
            if(starter=="Alice")
            {
                cout<<"Bob"<<endl;
                return;
            }
            else
            {
                cout<<"Alice"<<endl;
                return;
            }
        }
        else if(abs(freq-freq2)==1)
        {
            cout<<starter<<endl;
        }
        else
        {
            cout<<"tie"<<endl;
        }

    }
    else
    {
        cout<<starter<<endl;
    }
}



int main()
{
    vector<int> v;
    int tst;
    cin>>tst;
    string starter;
    int n;
    for(int j=0; j<tst; j++)
    {
        cin>>n;
        cin>>starter;
        v=primeFactors(n);
        s.erase(1);
        output(n,starter,v);
    }
}
