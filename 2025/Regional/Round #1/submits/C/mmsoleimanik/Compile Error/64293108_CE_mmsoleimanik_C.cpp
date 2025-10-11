#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <fstream>
using namespace std;
freopen("treasures.in" , "r" , stdin);

int f(int Nrow , int Ncolumn  , int (*G)[100][100] , int T , int P[2]) {
    //create  matrix
    int treasers = 0;

    P[0]--; P[1]--;//0-based
    for (int i=0; i<Nrow; i++) {
        for (int j=0; j<Ncolumn; j++) {
            if (abs(P[0] - i) + abs(P[1] - j) < T) {
                treasers += (*G)[i][j];
            }
        }   
    }

    return treasers;
}

int main() {
    int T , Ans[100];
    cin >> T;

    /*int R[1000][1000] = { {1,2,3} , {4,5,6} , {7,8,9}} , l[2]={3,2};
    Ans[0] = f(3,3,R,2,l);*/
    for (int i=0; i<T; i++) {
        int N , M , t , p[2];
        cin >> N >> M >> t >> p[0] >> p[1];

        int G[100][100];
        for (int j=0; j<N; j++) {
            for (int k=0; k<M; k++) {
                cin >> G[j][k];
            }
        }

        Ans[i] = f(N , M , &G , t , p);
    }

    for (int i=0; i<T; i++) {
        cout << "Case " << i+1 << ": " << Ans[i] << endl;
    }

    return 0;
}