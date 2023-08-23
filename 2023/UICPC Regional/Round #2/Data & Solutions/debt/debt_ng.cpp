#include <cstdio>

const bool DEBUG = false;
const int INF = 1 << 20;

const int P = 3; // Number of people
const int D = 6; // Number of coin types
const int DEN[] = {100, 50, 20, 10, 5, 1};
const int MAX_MON = 1000; // Max total money

int M[P][D]; // The number of coins and bills each person have
// Cost: For each "round", a map from A's and B's balance to num moves
int C[2][MAX_MON+1][MAX_MON+1];

int* moves(int round, int A, int B) { 
    return &C[round%2][A][B]; 
}

int main() {
    int n; scanf("%d", &n);
    while (n--) {
        int AowesB, BowesC, CowesA;
        scanf("%d %d %d", &AowesB, &BowesC, &CowesA);
        int S[3] = {0,0,0}; // Start money
        for (int p = 0; p < P; p++) {
            for (int d = 0; d < D; d++) {
                scanf("%d", &M[p][d]);
                S[p] += M[p][d] * DEN[d];
            }
        }
        int T = S[0] + S[1] + S[2]; // Total money
        for (int A = 0; A <= T; A++) {
            for (int B = 0; B <= T; B++) {
                *moves(0, A, B) = *moves(1, A, B) = INF; 
            } 
        }
        *moves(0, S[0], S[1]) = 0;
        int r = 0; // Round
        //for (int c = 0; c < D; c++) { // Give coin/bill type c
        for (int c = D-1; c >= 0; c--) { // Give coin/bill type c
            for (int f = 0; f < P; f++) { // f gives money
                int t1 = (f + 1) % 3; // Receiver 1...
                int t2 = (f + 2) % 3; // and 2
                // Go through all money distributions
                for (int A = 0; A <= T; A++) {
                    for (int B = 0; A + B <= T; B++) {
                        int* s = moves(r, A, B);
                        if (*s < INF) {
                            // Distribute money
                            for (int g1 = 0; g1 <= M[f][c]; g1++) { 
                                for (int g2 = 0; g1 + g2 <= M[f][c]; g2++) { 
                                    int E[3] = {A, B, T-(A+B)}; // New money amounts
                                    E[f]  -= (g1 + g2) * DEN[c];
                                    E[t1] += (g1     ) * DEN[c];
                                    E[t2] += (     g2) * DEN[c];
                                    int* t = moves(r+1, E[0], E[1]);
                                    if (*s + g1 + g2 < *t) {
                                        *t = *s + g1 + g2;
                                    }
                                }
                            }
                        }
                    }
                }
                r++;
            }
        }
        int* z = moves(r, S[0] - AowesB + CowesA, S[1] - BowesC + AowesB);
        if (*z == INF) printf("impossible\n");
        else           printf("%d\n", *z);
    }
}
