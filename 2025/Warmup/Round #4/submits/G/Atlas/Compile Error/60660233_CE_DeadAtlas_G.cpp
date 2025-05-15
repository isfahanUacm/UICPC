import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Integer> list = new ArrayList<Integer>(n);
        ArrayList<Integer> answer = new ArrayList<Integer>();
        for (int i = 0; i < n; i++) {
            list.add(sc.nextInt());
        }
        ArrayList<Integer> list2 = new ArrayList<Integer>(list);

        Collections.sort(list);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((list.get(i) < list.get(j)) && (list2.indexOf(list.get(i))<list2.indexOf(list.get(j)))
                        && (gcd(list.get(i), list.get(j))) != 1) {
                    if(!answer.contains(list.get(i))){
                        answer.add(list.get(i));
                    }
                    if(!answer.contains(list.get(j))){
                        answer.add(list.get(j));
                    }
                }
            }
        }
        ArrayList<Integer> answer2 = new ArrayList<Integer>();

        for (int i : answer) {
            answer2.add(list2.indexOf(i)+1);
        }
        if (answer2.isEmpty()) {
            System.out.println(1);
            System.out.println(1);
        }
        else {System.out.println(answer2.size());
            for(int i : answer2){
                System.out.print(i+" ");
            }
        }





    }
    public static int gcd(int a, int b) {
        if (b==0) return a;
        return gcd(b,a%b);
    }
}