import java.util.Scanner;

public class Main{
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        int n = input.nextInt();

        int sum = 0 ;

        //SIzoja
        if(n%2==0){
            for(int i=0;i<=n;i+=2)sum+=i;
        }//EndSIzoja

        //siFadha
        else{
            for(int i=1;i<=n;i+=2)sum+=i;
        }//EndsiFadha

        System.out.println(sum);
    }//EndMain
}//EndClass