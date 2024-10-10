#include <bits/stdc++.h>
using namespace std;

string tostr(unsigned long long int a ) {
    unsigned long long int value = 1;
    int pow = 0;
    while (value < a){
        value *= 10;
        pow ++;
    }

    string res = string();

    if (a / value)
        res+= a/value + '0' ;
    else {
        value /= 10;
        pow--;
    }

    for (int i = pow ; i >= 0;i-- ){

            res += a/value +'0' ;
            a %= value;

        value /= 10;
    }

    return res;

}

unsigned long long int tonum(string s){

    unsigned long long int value = 1;
    unsigned long long int res = 0;

    for(int i= 0 ; i < s.length();i++){
        res += (s[i]-'0') * value;

        value *= 10;

    }

    return res;
}






int main() {
    long int t ;
    cin >> t;

    for (int i = 0 ; i < t ; i++) {
        int a,b,len,prime;


            cin>>a>>b>>len>>prime;
            unsigned long long counter=0;
            unsigned long long num=( (double)a/(double)b ) * pow(10,len);
            string number= tostr(num);
            unsigned long long size= (number.length()*(number.length()+1))/2;
            string arr[size];

            int index = 0;

            for (int j = 0 ; j < number.length();j++){
                arr[index] = number[j];
                index++;
                for(int k = 1 ; k < (number.length()-j);k++) {
                    arr[index] = arr[index-1] + number[j+k];
                    index++;
                }
            }
            for (int k = 0; k < size; ++k) {
                if(tonum(arr[k])%prime==0)
                    counter++;
            }
            cout<<counter;

       if (i != t-1)
           cout<<endl;
    }
    return 0;
}
