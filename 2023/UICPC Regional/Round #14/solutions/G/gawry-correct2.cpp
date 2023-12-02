// @EXPECTED_RESULTS@: CORRECT
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    for(int tst=0;tst<T;tst++)
    {
        int m,n;
        scanf("%d%d",&m,&n);
        vector<pair<int,int> > segm;
        for(int i=0;i<n;i++)
        {
            int st,en;
            scanf("%d%d",&st,&en);
            if(st<=en)
            {
                segm.push_back(make_pair(st,en));
                segm.push_back(make_pair(st+m,en+m));
            }
            else
                segm.push_back(make_pair(st,en+m));
        }
        if(n>m)
        {
            puts("NO");
            continue;
        }
        sort(segm.begin(),segm.end());
        int T=0;
        int i=0;
        set<pair<int,int> > que;
        bool ok = true;
        while(true)
        {
            if(que.empty())
            {
                if(i==segm.size())
                    break;
                else
                    T = segm[i].first;
            }
            while(i<segm.size() && segm[i].first==T)
            {
//                printf("T=%d  %d-%d\n",T,segm[i].first,segm[i].second);
                que.insert(make_pair(segm[i].second,i));
                i++;
            }
            int ind = que.begin()->second;
            que.erase(que.begin());
//            printf("pop %d %d\n",segm[ind].first,segm[ind].second);
            if(!(T>=segm[ind].first && T<=segm[ind].second))
            {
                ok = false;
                break;
            }
            T++;
        }
        puts(ok?"YES":"NO");
    }
}

