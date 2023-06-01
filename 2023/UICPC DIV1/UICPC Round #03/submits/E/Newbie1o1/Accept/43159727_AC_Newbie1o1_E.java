import java.util.Scanner;

public class E {
    public static void main(String[]args){
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int P = scanner.nextInt();
        int S = scanner.nextInt();


        for(int i=0;i<S;i++){
            int cnt =0;
            int x = scanner.nextInt();
            int[] temp = new int[x];
            for (int j=0;j<x;j++){
                temp[j] = scanner.nextInt();
            }
            for (int l=0;l< temp.length;l++){
                if (temp[l] == P){
                    cnt++;
                }
            }
            if(cnt == 1){
                System.out.println("Keep");
            }
            else{
                System.out.println("Remove");
            }

        }
    }
}
