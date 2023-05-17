

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, m;
        n = sc.nextInt();
        m = sc.nextInt();
        int max1 = sc.nextInt();
        for (int i = 1; i < n; i++) {
            int temp = sc.nextInt();
            if (max1 < temp){
                max1 = temp;
            }
        }
        int max2 = sc.nextInt();
        for (int i = 1; i < m; i++) {
            int temp = sc.nextInt();
            if (max2 < temp){
                max2 = temp;
            }
        }
        if (max1 == max2){
            System.out.println("possible");
        } else {
            System.out.println("impossible");
        }
    }
}