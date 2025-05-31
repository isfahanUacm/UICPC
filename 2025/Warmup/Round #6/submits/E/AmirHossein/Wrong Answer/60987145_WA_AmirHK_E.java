import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        boolean valid = true;
        for (int i = 0; i < n; i++) {
            ArrayList<Character> char1 = new ArrayList<>();
            ArrayList<Character> char2 = new ArrayList<>();
            int a = sc.nextInt();
            int b = sc.nextInt();
            sc.nextLine();
            String s1 = sc.nextLine();
            String s2 = sc.nextLine();
            for (int j = 0; j < a; j++) {
                char1.add(s1.charAt(j));
            }
            for (int j = 0; j < a; j++) {
                char2.add(s2.charAt(j));
            }
            for (int j = 0; j < a; j++) {
                if (char1.contains(char2.get(j))) {
                    if (char1.get(j) != char2.get(j)) {
                        if (j + b < a && char1.get(j+b).equals(char2.get(j))) {
                            char1.set(j, char1.get(j + b));
                        } else {
                            if (j - b >= 0 && char1.get(j-b).equals(char2.get(j))) {
                                char1.set(j, char2.get(j - b));
                            } else  {
                                valid = false;
                                System.out.println("No");
                                break;
                            }
                        }

                    }
                }

            }
            if (valid) {
                System.out.println("Yes");
            }

        }


    }
}
