// @EXPECTED_RESULTS@: CORRECT
import java.util.Scanner;

// The Solver class solves an instance of the problem for a specific player P.
//
// It works by greedily assuming p wins his remaining matches and all other
// players tie, and then iteratively searches for a path from a player i with
// score[i] > score[p] to a player j with score[j] < score[p] using only
// unplayed games, and then moves one point from i to j, reducing his score.
// This is repeated until either all players have scores less than or equal to
// p (in which case p can win) or there are no more paths (and so p must lose).

class Solver {
    public int N, value[][], score[], maxScore;
    public boolean visited[], fixed[][];

    public Solver(String[] grid, int P) {
        N = grid.length;
        fixed = new boolean[N][N];
        value = new int[N][N];
        score = new int[N];
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                switch (grid[i].charAt(j)) {
                case '.': value[i][j] = i == P ? 2 : j == P ? 0 : 1; break;
                case '0': value[i][j] = 0; fixed[i][j] = true; break;
                case 'd': value[i][j] = 1; fixed[i][j] = true; break;
                case '1': value[i][j] = 2; fixed[i][j] = true; break;
                }
                score[i] += value[i][j];
            }
        }
        maxScore = score[P];
    }

    boolean solve() {
        for (int i = 0; i < N; ++i) {
            while (score[i] > maxScore) {
                visited = new boolean[N];
                if (push(i)) --score[i]; else return false;
            }
        }
        return true;
    }

    boolean push(int i) {
        if (score[i] < maxScore) {
            ++score[i];
            return true;
        }
        visited[i] = true;
        for (int j = 0; j < N; ++j) {
            if (!fixed[i][j] && value[i][j] > 0 && !visited[j] && push(j)) {
                --value[i][j];
                ++value[j][i];
                return true;
            }
        }
        return false;
    }
}

class maks3 {
    public static void main(String... args) {
        Scanner sc = new Scanner(System.in);
        int cases = sc.nextInt();
        for (int c = 0; c < cases; ++c) {
            int N = sc.nextInt();
            String[] grid = new String[N];
            for (int i = 0; i < N; ++i) grid[i] = sc.next();
            String line = "";
            for (int p = 0; p < N; ++p) {
                if (new Solver(grid, p).solve()) {
                    if (line != "") line += " ";
                    line += p + 1;
                }
            }
            System.out.println(line);
        }
    }
}
