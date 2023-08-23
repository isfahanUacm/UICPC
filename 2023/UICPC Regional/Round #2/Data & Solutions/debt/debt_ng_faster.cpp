#include <algorithm>
#include <cassert>
#include <cstdio>

using namespace std;

const bool DEBUG = false;
const int INF = 1 << 20;

const int P = 3; // Number of people
const int D = 6; // Number of coin types
const int MAX_MON = 1000; // Max total money
const int MAX_COI = 30; // Max total money
const int DEN[] = {100, 50, 20, 10, 5, 1}; // Money denominations
const int GCD[] = {100, 50, 10, 10, 5, 1}; // GCD of this and all larger denoms

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
        int M[P][D]; // The number of coins and bills each person have
        int S[P] = {0,0,0}; // Start money
        int R[P][D]; // Suffix sums of each persons money
        for (int p = 0; p < P; p++) {
            for (int d = 0; d < D; d++) {
                scanf("%d", &M[p][d]);
                S[p] += M[p][d] * DEN[d];
                R[p][d] = M[p][d] * DEN[d];
            }
            for (int d = D-2; d >= 0; d--) {
                R[p][d] += R[p][d+1];
            }
            assert(R[p][0] == S[p]);
        }
        int T = S[0] + S[1] + S[2]; // Total money
        for (int A = 0; A <= T; A++) {
            for (int B = 0; B <= T; B++) {
                *moves(0, A, B) = *moves(1, A, B) = INF; 
            } 
        }
        int G[3] = {S[0] - AowesB + CowesA, // Goal money
                    S[1] - BowesC + AowesB,
                    S[2] - CowesA + BowesC};
        *moves(0, S[0], S[1]) = 0;
        int r = 0; // Round
        for (int c = 0; c < D; c++) { // Give coin/bill type c
            for (int f = 0; f < P; f++) { // f gives money
                int t1 = (f + 1) % 3; // Receiver 1...
                int t2 = (f + 2) % 3; // and 2
                int U[3] = {G[0], G[1], G[2]}; // First state to consider
                int V[3] = {G[0], G[1], G[2]}; // Last state to consider
                for (int i = 0; i < P; i++) {
                    U[i] -= R[(i+1)%3][c] + R[(i+2)%3][c];
                    U[i] = max(0, U[i]/GCD[c]*GCD[c]); // Get %GCD[c] right
                    V[i] += R[i][c];
                    V[i] = min(T, V[i]);
                }
                U[0] += S[0]%GCD[c]; // Get %GCD[c] right
                U[1] += S[1]%GCD[c];
                // Go through all money distributions
                for (int A = U[0]; A <= V[0]; A += GCD[c]) {
                    for (int B = U[1]; B <= V[1]; B += GCD[c]) {
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
        int* z = moves(r, G[0], G[1]);
        if (*z == INF) printf("impossible\n");
        else           printf("%d\n", *z);
    }
}
