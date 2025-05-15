import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner sc=new Scanner(System.in);

        int tedad=sc.nextInt();

        int placeVal1=sc.nextInt();
        int placeProb1=sc.nextInt();

        int placeVal2=sc.nextInt();
        int placeProb2=sc.nextInt();

        if(placeVal1==placeVal2)
            System.out.println(placeProb2-placeProb1);

        else {

            int differ=tedad-placeProb1;
            int d2=(placeVal2-placeVal1-1)*tedad;
            System.out.println(differ+d2+placeProb2+(placeVal2-placeVal1));
        }



    }

}