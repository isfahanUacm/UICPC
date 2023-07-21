import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

public class wordle_da {

    private void work(){
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int n = sc.nextInt();
        int w = sc.nextInt();

        char[][] gs = new char[n][];
        char[][] rs = new char[n][];

        for(int i = 0; i < n; i++){
            gs[i] = sc.next().toCharArray();
            rs[i] = sc.next().toCharArray();
        }

        while(w-- > 0){
            char[] word = sc.next().toCharArray();
            boolean ok = true;
            for(int i = 0; i < n; i++){
                char[] r = getResult(gs[i] , word);
                if(!same(rs[i], r)){
                    ok = false;
                    break;
                }
            }

            if(ok) System.out.println(new String(word));
        }
    }

    private boolean same(char[] a, char[] b){
        for(int i = 0; i < 5; i++){
            if(a[i] != b[i]) return false;
        }

        return true;
    }

    private char[] getResult(char[] w0, char[] w1){
        char[] res = new char[5];
        Arrays.fill(res, '-');

        boolean[][] used = new boolean[2][5];
        for(int i = 0; i < 5; i++){
            if(w0[i] == w1[i]){
                res[i] = 'G';
                used[0][i] = used[1][i] = true;
            }
        }

        for(int i = 0; i < 5; i++){
            if(used[0][i]) continue;
            for(int j = 0; j < 5; j++){
                if(used[1][j]) continue;
                if(w0[i] == w1[j]){
                    res[i] = 'Y';
                    used[0][i] = true; // meh
                    used[1][j] = true;
                    break;
                }
            }
        }

        return res;
    }

    public static void main(String[] args) {
        new wordle_da().work();
    }
}
