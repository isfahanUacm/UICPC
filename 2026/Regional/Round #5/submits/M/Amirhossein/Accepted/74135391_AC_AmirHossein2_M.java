import java.util.Scanner;

public class Main{
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

                String Ta = input.nextLine().trim();
                String Td = input.nextLine().trim();
                int P = input.nextInt();
                int H = input.nextInt();

                double M = 0.5;
                if ((Ta.equals("F") && Td.equals("G")) ||
                        (Ta.equals("G") && Td.equals("W")) ||
                        (Ta.equals("W") && Td.equals("F"))) {
                    M = 2;
                }

                int damage = (int)(P * M);
                int X = Math.max(0, H - damage);

                if (X == 0)System.out.println("Nocaute!");
                    else System.out.println("Sobraram " + X + " pontos de vida!");

                input.close();

    }//EndMain
}//EndClass