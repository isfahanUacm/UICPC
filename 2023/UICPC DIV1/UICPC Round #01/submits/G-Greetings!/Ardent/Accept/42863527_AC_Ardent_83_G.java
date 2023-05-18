import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        int len = (str.length() - 2);
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append("h");
        for (int i = 0; i < (len); i++) {
            stringBuilder.append("ee");
        }
        stringBuilder.append("y");
        System.out.println(stringBuilder);
    }
}