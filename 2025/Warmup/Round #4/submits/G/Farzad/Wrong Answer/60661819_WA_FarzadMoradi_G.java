import java.util.*;

public class Main {
    public static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int[] arr = new int[n];
        List<Integer> list = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            arr[i] = input.nextInt();
        }

        int[] temp = arr.clone();
        Arrays.sort(temp);

        int base = 0;
        int x = 0;

        for(int i = 0; i < n - 1; i++){
            if(temp[i] == 1 || temp[i] == temp[i+1]){
                continue;
            } else {
                base = temp[i];
                x = i;
                break;
            }
        }

        if(base == 0){
            base = temp[n - 1];
            x = n - 1;
        }

        list.add(base);

        for(int i = x + 1; i < n; i++){
            if(gcd(base, temp[i]) != 1 && temp[i] > base){
                base = temp[i];
                list.add(base);
            }
        }

        System.out.println(list.size());

        Set<Integer> used = new HashSet<>();
        for (int value : list) {
            for (int i = 0; i < n; i++) {
                if (arr[i] == value && !used.contains(i)) {
                    System.out.print((i + 1) + " ");
                    used.add(i);
                    break;
                }
            }
        }
    }
}
