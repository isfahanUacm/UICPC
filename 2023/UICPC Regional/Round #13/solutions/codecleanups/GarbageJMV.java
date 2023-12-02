import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.StreamTokenizer;

public class GarbageJMV {

    public static void main(String[] args) throws IOException {
        StreamTokenizer in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in), 1 << 20));
        int cleanups = 0, dirtiness = 0, pushes = 0, last = 0;
        for (in.nextToken(); in.nextToken() != StreamTokenizer.TT_EOF; ) {
            if (dirtiness + pushes * (in.nval - last) >= 20) {
                cleanups++;
                dirtiness = 0;
                pushes = 0;
            }
            dirtiness += pushes * (in.nval - last);
            last = (int) in.nval;
            pushes++;
        }
        cleanups++;

        System.out.println(cleanups);
    }

}
