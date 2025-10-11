
import java.util.*;

public class Main {
    public static void main(String[] args) {
        int t,n;
        Scanner sc=new Scanner(System.in);

        t= sc.nextInt();
        n= sc.nextInt();


        Set<Integer> sums = new HashSet<>();
while (t>0) {
    for (int i = 0; i < n; i++) {
        int value = sc.nextInt();
        sums.add(value);
    }
t--;
}
//        while(t>0){
//            while(n>0){
//                int a= sc.nextInt();
//                sum.add(a);
//            }
//        }
        Set<Integer> tas1=new HashSet<>();
        Set<Integer> tas2=new HashSet<>();

        for(int i=1; i<=6; i++){
            for(int j=1; j<=6; j++){
                int sum=i+j;
                if(sums.contains(sum)){
                    tas1.add(i);
                    tas2.add(j);
                }

            }
        }
        for(int vajh:tas1){
            System.out.print(vajh+" ");
        }
        System.out.print("\n");
        for(int vajh2 :tas2){
            System.out.print(vajh2 +" ");
        }
    }
}