import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        String[] listTemp = str.split(" ");
        List<String> list = Arrays.asList(listTemp);
        Set<String> set = new HashSet<>(list);
        if (set.size() < list.size()) System.out.print("no");
        else System.out.print("yes");
    }
}