import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * @author Torstein Strømme
 */
public class Torstein {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int lawn = sc.nextInt(), options = sc.nextInt(); sc.nextLine();

        List<String> bestChoices = new ArrayList<>();
        int bestPrice = 1000*1000;

        for (int i = 0; i < options; i++) {
            String[] line = sc.nextLine().split(",");
            int price = Integer.parseInt(line[1]);
            if (price <= bestPrice && lawn <= lawnPerWeek(Integer.parseInt(line[2]),
                                                          Integer.parseInt(line[3]),
                                                          Integer.parseInt(line[4]))) {
                
                if (price < bestPrice) {
                    bestPrice = price;
                    bestChoices.clear();
                }
                
                bestChoices.add(line[0]);
            }
        }

        if (bestChoices.isEmpty()) {
            System.out.println("no such mower");
        }
        else {
            for (String mower : bestChoices) {
                System.out.println(mower);
            }
        }

    }

    private static double lawnPerWeek(int cut_capacity, int cut_time, int charge_time) {
        double cycles = 60.0 * 24 * 7 / (cut_time + charge_time);
        return cycles * cut_time * cut_capacity;
    }
}
