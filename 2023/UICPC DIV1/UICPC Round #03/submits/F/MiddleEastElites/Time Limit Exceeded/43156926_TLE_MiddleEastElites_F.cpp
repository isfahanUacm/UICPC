///In the name of Allah
#include<bits/stdc++.h>

using namespace std ;

typedef long long int ll ;

int main(void){
    ios_base::sync_with_stdio(false) ;
    int n , temp;
    cin >> n ;
    vector<int> vect ;
    for(int i=0 ; i<n;  i++){
        cin >> temp ;
        vect.push_back(temp) ;
    }
    ll len = 0 ;
    ll sum = 0 ;
    vector<int> answer ;
    vector<int>del ;
    while (len!=int(vect.size())) {
        del.clear() ;
        len = vect.size() ;
        if(vect.size()>=2){
            if(vect[0]<vect[1])
                del.push_back(0) ;
        }
        for(int i=1 ; i<(int(vect.size())-1) ; i++){
            if(vect[i]<vect[i+1] || vect[i]<vect[i-1])
                del.push_back(i) ;
        }
        if(vect.size()>=2){
            if(vect[vect.size()-1]<vect[vect.size()-2])
                del.push_back(vect.size()-1) ;
        }
        for(int i=0 ; i<int(del.size()) ; i++){
            answer.push_back(vect[del[i]]) ;
        }
        answer.push_back(-1) ;
        for(int i=del.size()-1 ; i>=0 ; i--){
            for(int j=del[i] ; j<int(vect.size())-1 ; j++){
                swap(vect[j],vect[j+1]) ;
            }
            vect.pop_back() ;
        }

        sum ++ ;
    }
    cout << sum-1 << '\n' ;
    for(ll i = 0 ; i<answer.size()-1 ; i++){
        if(answer[i+1]==-1){
             cout << answer[i] << '\n';
             i++ ;
        }
        else
            cout << answer[i] << ' ' ;

    }
    for(int i=0; i<int(vect.size()) ; i++){
        if(i==int(vect.size()-1))
            cout << vect[i] << '\n' ;
        else
            cout << vect[i] << ' ';
    }
    return 0 ;
}
