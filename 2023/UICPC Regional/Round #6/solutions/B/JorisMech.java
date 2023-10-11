/*
 * Solution for Battle Simulation.
 */

import java.io.*;
import java.util.*;

public class JorisMech
{

    public static void main(String[] args)
    {
        try {
            BufferedReader ir = new BufferedReader(
                                  new InputStreamReader(System.in));

            // Read input.
            String s = ir.readLine();
            assert (s.length() >= 1 && s.length() <= 1000000);
            assert (s.matches("[RBL]+"));

            // Solve.
            String ans = s.replaceAll("RBL|RLB|BRL|BLR|LRB|LBR", "C");
            ans = ans.replaceAll("R", "S");
            ans = ans.replaceAll("B", "K");
            ans = ans.replaceAll("L", "H");

            // Write output.
            System.out.println(ans);

        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

}

