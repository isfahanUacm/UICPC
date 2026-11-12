import java.util.Scanner;

public class contest05 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int b = input.nextInt();
        int h = input.nextInt();
        int l = input.nextInt();

        double hexa = (3*Math.sqrt(3)/2)*l*l;
        double rect = (double) b * h ;
        System.out.print(hexa/rect);
        
    }//EndMain