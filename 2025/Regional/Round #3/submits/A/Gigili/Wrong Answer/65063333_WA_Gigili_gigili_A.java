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
        String f = String.valueOf(final_percentage);
//        String str = "";
//
//        for (int i = f.length() - 1; i >=0; i--)
//        {
//            if (f.charAt(i) != '0')
//            {
//                for (int j = 0; j <= i; j++)
//                    str  += f.charAt(j);
//                break;
//            }
//        }
      //  System.out.format(str);

        System.out.format("%-16f", final_percentage);
    }
}