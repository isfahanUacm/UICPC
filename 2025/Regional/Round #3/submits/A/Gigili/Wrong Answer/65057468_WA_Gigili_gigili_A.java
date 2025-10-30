import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int day = sc.nextInt();
        int alcohol_v = sc.nextInt();
        int liquids_v = sc.nextInt();

        int alcohol_ev = sc.nextInt();
        int liquids_ev = sc.nextInt();

        double alcohol_r = (alcohol_v * Math.pow(10,6)) - (day * (alcohol_ev *(Math.pow(10,6))));
        double liquids_r = (liquids_v * Math.pow(10,6)) - (day * (liquids_ev) * Math.pow(10,6));

        double total = (alcohol_r + liquids_r);
        double result = (alcohol_r / total);
        double final_percentage = result * 100;
        System.out.format( "%-16.14f",final_percentage);
     }
}