import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

public class election_da {

    private void work(){
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int n = sc.nextInt();
        int[] a = new int[n];
        for(int i = 0; i < n; i++){
            a[i] = sc.nextInt();
        }

        Arrays.sort(a);
        int answer = 0;
        for(int i = 0; i < n; i++){
            if(i <= n/2) answer += a[i]/2;
            else answer += a[i];
        }

        System.out.println(answer);
    }

    public static void main(String[] args) {
        new election_da().work();
    }
}
