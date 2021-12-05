#include <bits/stdc++.h>
using namespace std;
#define MAX_N 200010
string T; 
int n;
int RA[MAX_N], tempRA[MAX_N];
int SA[MAX_N], tempSA[MAX_N];
int c[MAX_N]; // for counting/radix sort
void countingSort(int k) { 
    int i, sum, maxi = max(300, n);
    memset(c, 0, sizeof c);
    for (i = 0; i < n; i++)
        c[i + k < n ? RA[i + k] : 0]++;
    for (i = sum = 0; i < maxi; i++) {
        int t = c[i];
        c[i] = sum;
        sum += t;
    }
    for (i = 0; i < n; i++)
        tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
    for (i = 0; i < n; i++)
        SA[i] = tempSA[i];
}
void constructSA() {
    int i, k, r;
    for (i = 0; i < n; i++) RA[i] = T[i];
    for (i = 0; i < n; i++) SA[i] = i;
    for (k = 1; k < n; k <<= 1) {
        countingSort(k); // actually radix sort: sort based on the second item
        countingSort(0); // then (stable) sort based on the first item
        tempRA[SA[0]] = r = 0; // re-ranking; start from rank r = 0
        for (i = 1; i < n; i++) // compare adjacent suffixes
            tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;// if same pair => same rank r; otherwise, increase r                    
        for (i = 0; i < n; i++) // update the rank array RA
            RA[i] = tempRA[i];
        if (RA[SA[n-1]] == n-1)
            break; // nice optimization trick
    }
}
int Phi[MAX_N];
int LCP[MAX_N];
int PLCP[MAX_N];

void computeLCP() { // O(3n)
    int i, L;
    Phi[SA[0]] = -1; // default value
    for (i = 1; i < n; i++)
        Phi[SA[i]] = SA[i-1]; // remember which suffix is behind this suffix
    for (i = L = 0; i < n; i++) {
        if (Phi[i] == -1)// special case
        { 
            PLCP[i] = 0;
            continue;
        }
        while (T[i + L] == T[Phi[i] + L])
            L++; // L increased max n times
        PLCP[i] = L;
        L = max(L-1, 0); // L decreased max n times
    }
    for (i = 0; i < n; i++)
        LCP[i] = PLCP[SA[i]]; // put the permuted LCP to the correct position
}
int m, qi;

int main() {
    while(getline(cin, T)){
//        cout << T << endl;
//        T += '$';
        n = T.length();
        constructSA();
        computeLCP();
//        for (int i = 0; i < n; i++)
//                printf("%2d\t%2d\t%s\n", SA[i], LCP[i], T.substr(SA[i], n-i+1).c_str());
        cin >> m;
        for (int i = 0; i < m; ++i) {
            cin >> qi;
            cout << SA[qi] << " ";
        }
        cout << endl;
        cin.ignore();
    }
    return 0;
}
