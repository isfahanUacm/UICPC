import java.util.Scanner;
import java.util.stream.IntStream;

public class GameRank_Jimmy {
    public static void main(String[] args) {
        int starsPerRank[] = IntStream.range(0, 26).map(rank -> Math.min(5, 6 - (rank - 1) / 5)).toArray();
        String s = new Scanner(System.in).next();
        int rank = 25, stars = 0, cw = 0;
        for (int i = 0; i < s.length() && rank > 0; i++) {
            if (s.charAt(i) == 'W') {
                stars++;
                if (rank > 5 && ++cw >= 3) stars++;
                if (stars > starsPerRank[rank]) {
                    stars -= starsPerRank[rank];
                    rank--;
                }
            } else {
                cw = 0;
                if (rank <= 20) {
                    stars--;
                    if (stars < 0) {
                        if (rank == 20) {
                            stars = 0;
                        } else {
                            rank++;
                            stars = starsPerRank[rank] - 1;
                        }
                    }
                }
            }
        }
        System.out.println(rank == 0 ? "Legend" : rank);
    }
}
