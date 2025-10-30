import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();

        Map<Character, Integer> charCounts = new HashMap<>();

        for (char c : s.toCharArray()) {
            charCounts.put(c, charCounts.getOrDefault(c, 0) + 1);
        }

        int oddCount = 0;

        for (int count : charCounts.values()) {
            if (count % 2 != 0) {
                oddCount++;
            }
        }
        

        if (oddCount <= 1) {
            System.out.println("yes");
        } else {
            System.out.println("no");
        }
    }
}
