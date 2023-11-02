// O(N^2*3^N + N*M*2^N) DP solution to codenames.
// Rather than representing state as
// (Board, hint word, turn, #guesses left)
// = O(2^N * M * 2 * N)
// State is represented as
// (Guessable, live, turn, #guesses left)
// = O(3^N * 2 * N)
// The board is such that every position is either
// Currently on the table to be guessed, already guessed,
// Or still live. Slower than the other DP.

import java.io.*;
import java.util.*;

public class Bryce {
    static HashMap<State, Double> memo = new HashMap<State, Double>();
    static int N;
    static char[] identity;
    static char c;
    static int M;
    static int[] hint;

    // returns true if all set bits of live are not of color
    static boolean isWinning(int live, char color) {
        int suf = live;
        while (suf != 0) {
            int high = Integer.highestOneBit(suf);
            int high_log = Integer.numberOfTrailingZeros(high);
            if (identity[high_log] == color) {
                return false;
            }
            suf ^= high;
        }
        return true;
    }

    static double solve(State state) {  // calculate the probability of current player winning the game given the state
        if (memo.containsKey(state)) {
            return memo.get(state);
        }
        
        char other = state.turn == 'R' ? 'B' : 'R';

        // check if winning or losing state
        if (isWinning(state.live, state.turn)) {
            return 1.0;
        }
        if (isWinning(state.live, other)) {
            return 0.0;
        }
       
        // state is a guessing state 
        if (state.guessable != 0) {
            double ans = 0;
            int guessSuf = state.guessable;
            int n_bits = Integer.bitCount(state.guessable);
            ArrayList<State> p = new ArrayList<State>();
            boolean hitsA = false;
            while (guessSuf != 0) {
                int guess = Integer.highestOneBit(guessSuf);
                int guess_log = Integer.numberOfTrailingZeros(guess);
               
                if (identity[guess_log] == 'A') {
                    // do nothing, this is a lose condition
                    hitsA = true;
                } else if (identity[guess_log] == 'I') {    // hit bystander
                    ans += 1.0/n_bits * (1.0-solve(new State(0, state.live^guess, other, 0)));
                    p.add(new State(0, state.live^guess, other, 0));
                } else if (identity[guess_log] == state.turn) { // hit current player's card
                    if (state.guesses > 1) {   // keep guessing
                        ans += 1.0/n_bits * solve(new State(state.guessable^guess, state.live^guess, state.turn, state.guesses-1));
                        p.add(new State(state.guessable^guess, state.live^guess, state.turn, state.guesses-1));
                    } else {    // yield
                        ans += 1.0/n_bits * (1.0-solve(new State(0, state.live^guess, other, 0)));
                        p.add(new State(0, state.live^guess, other, 0));
                    }
                } else {    // hit other player's card
                    ans += 1.0/n_bits * (1.0-solve(new State(0, state.live^guess, other, 0)));
                    p.add(new State(0, state.live^guess, other, 0));
                }

                guessSuf ^= guess;
            }
            memo.put(state, ans);
            return ans;
        } else {    // state is cluegiving state
            double ans = 0;
            for (int i = 0; i < M; ++i) {   // try all clues
                int guessable = hint[i] & state.live;
                int n_bits = Integer.bitCount(guessable);
                for (int j = 1; j <= n_bits; ++j) { // try all values for K
                    State guess = new State(guessable, state.live, state.turn, j);
                    ans = Math.max(ans, solve(new State(guessable, state.live, state.turn, j)));
                }
            }
            memo.put(state, ans);
            return ans;
        }
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        N = in.nextInt();
        c = in.next().charAt(0);

        String[] board = new String[N];
        for (int i = 0; i < N; ++i) {
            board[i] = in.next();
        }
        identity = new char[N];
        for (int i = 0; i < N; ++i) {
            identity[i] = in.next().charAt(0);
        }

        M = in.nextInt();
        hint = new int[M];
        for (int i = 0; i < M; ++i) {
            int Hi = in.nextInt();
            hint[i] = 0;
            for (int j = 0; j < Hi; ++j) {
                String cur = in.next();
                for (int k = 0; k < N; ++k) {
                    if (board[k].equals(cur)) {
                        hint[i] ^= (1 << k);
                        break;
                    }
                }
            }
        }
        System.out.printf("%.10f\n", solve(new State(0, (1 << N)-1, c, 0)));
    }
}
class State {
    int guessable;  // represent the board by a pair of ints
    int live;
    char turn;
    int guesses;

    public State(int guessable, int live, char turn, int guesses) {
        this.guessable = guessable;
        this.live = live;
        this.turn = turn;
        this.guesses = guesses;
    }

    public int hashCode() {
        return Objects.hash(guessable, live, turn, guesses);
    }

    public boolean equals(Object o) {
        State o2 = (State) o;
        return guessable == o2.guessable && live == o2.live  && turn == o2.turn && guesses == o2.guesses;
    }

    public String toString() {
        return String.format("%6s", Integer.toBinaryString(guessable)) + " " + String.format("%6s", Integer.toBinaryString(live)) + " " + turn + " " + guesses;
    }
}
