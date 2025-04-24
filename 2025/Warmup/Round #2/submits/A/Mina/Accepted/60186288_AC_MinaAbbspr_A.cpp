#include <bits/stdc++.h>

#define input(n) long long n; cin >> n
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define Endl cout << endl
#define For(i , n) for(int i = 0 ; i < n ; i ++)
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
#define all(v) v.begin(),v.end()

using namespace std;

void Main() {
    input(n);
    input(c);
    vi arr(n);
    For(i , n){
        cin >> arr[i];
    }
    int temp = c , sum = 1;
    For(i , n){
        if(arr[i] < temp){
            temp -= arr[i];
        }
        else{
            sum += 1;
            temp = c;
        }
    }
    cout << sum;
    Endl;
}

int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int test = 1;
    cin >> test;
    for(int i = 0 ; i < test ; i ++){
        Main();
    }

    return 0;
}