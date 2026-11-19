import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String s = input.nextLine();

        if(s.length()%2 == 0) System.out.println(":)");
        else System.out.println(s.charAt(s.length()/2));
        //abcde
        //s.length = 5
        // 5/2=2


    }//end of Main

}//End of Class