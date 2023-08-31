
import java.awt.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.sql.ClientInfoStatus;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        int a = sc.nextInt();
        sc.nextLine();
        ArrayList<Code> codes = new ArrayList<>();
        for (int i = 0; i < a; i++) {
            codes.add(new Code(sc.nextLine()));
        }
        Code main = new Code("main");
        ArrayList<Integer> ans = new ArrayList<>();
        int max = Integer.MIN_VALUE;
        for(Code c : codes) {
            int  tmp = main.myRate(c);
            if (tmp > max)
                max=tmp;
            ans.add(tmp);
        }
        System.out.print(max + " ");
        for (int i = 0; i < codes.size(); i++) {
            if (ans.get(i) == max){
                System.out.print(codes.get(i).fileName + " ");
            }
        }
    }
}

class Code{
    static int simRate(Code a, Code b, int i, int j) {
        int ans=0;
        while (true) {
            if (i >= a.text.size() || j >=  b.text.size())
                break;
            if (a.text.get(i).size() != b.text.get(j).size())
                break;
            for (int k = 0; k < a.text.get(i).size(); k++) {
                if(!a.text.get(i).get(k).equals(b.text.get(j).get(k)))
                    break;
            }
            ans++;
            i ++;j++;
        }
        return ans;
    }
    public Code(String fileName) {
        this.fileName = fileName;
        while (true) {
            String tmp = Main.sc.nextLine();
            if (tmp.isEmpty())
                continue;
            if (tmp.equals("***END***"))
                break;
            ArrayList<String> line = new ArrayList<>();
            Scanner sc2 = new Scanner(tmp);

            while (sc2.hasNext()) {
                String s = sc2.next();
                if(!s.isEmpty())
                    line.add(s);
            }
            text.add(line);
        }
    }
    String fileName;
    ArrayList<ArrayList<String>> text = new ArrayList<>();

    int myRate(Code c) {
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < this.text.size(); i++) {
            for (int j = 0; j < c.text.size(); j++) {
                int tmp = simRate(this, c, i, j);
                if (tmp > max){
                    max = tmp;
                }
            }
        }
        return max;
    }
}