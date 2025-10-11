#include <iostream>
#include <string>
using namespace std;

int pow(int number , int power) {
    int ans = 1;

    for (int i=0; i<power; i++) {
        ans *= number;
    }

    return ans;
}

int number(string str) {
    int ans = 0;
    for (int i=str.size()-1; i>=0; i--) {
        ans += (int)(str[i] - '0')*pow(10 , i);
    }

    return ans;
}

string f(int Egept , int Ghana) {
    if (Ghana + 6 > Egept + 1) {
        return "NO";
    }
    else if (Egept + 1 > Ghana + 6) {
        return "YES";
    }
    else if (Egept + 2 > Ghana*2 + 6) {
        return "YES";
    }
    else if (Egept + 2 < Ghana*2 + 6) {
        "NO";
    }
        return "PENALTIES";
}

int main() {
    freopen("ghanophobia.in" , "r" , stdin);
    int t;
    cin >> t;
    string ans[10000];
    for (int i=0; i<t; i++) {
        string strE = "" , strG = "" , score;
        cin >> score;

        int j=0; while (j<10) {
            strE += score[j];
            j++;
            if (score[j] == ':') break;
        }
        for (++j; j<score.size(); j++) {
            strG += score[j];
        }

        ans[i] = f(number(strE) , number(strG));
    }

    for (int i=0; i<t; i++) {
        cout << "Case " << i+1 << ": " << ans[i] << endl;
    }
    return 0;
}