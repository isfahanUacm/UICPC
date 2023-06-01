import java.util.*;

import static java.lang.Math.abs;
import static java.lang.Math.min;
import static java.util.Arrays.sort;
public class J {
    public static void main(String[]args){
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int L = scanner.nextInt();
        int P = scanner.nextInt();
        int[] passengers_x = new int[P];
        int train_length = N*L;
        for(int i=0;i<P;i++){
            passengers_x[i] = scanner.nextInt();
            passengers_x[i] = train_length - passengers_x[i];
        }
        sort(passengers_x);

        int[] doors_x = new int[N];
        for(int j=0;j<N;j++){
            doors_x[j] = (((2*j)+1)*L)/2;
        }
        ArrayList<Integer> min_distances = new ArrayList<>();
        int[] distance =new int[N] ;
        for (int h=0;h<P;h++) {
            for (int g=0;g<N;g++) {
                distance[g] = Math.abs(passengers_x[h] - doors_x[g]);
            }
            sort(distance);
            min_distances.add(distance[0]);
        }
        Collections.sort(min_distances);
        int[] distance2 = new int[N];
        for (int q=0;q<N;q++){
            for(int w=0;w<P;w++){
                distance2[q] = Math.abs(passengers_x[w] - doors_x[w]);
            }

        }






        System.out.println(min_distances.get(P-1));
        System.out.println(1);





    }
}
