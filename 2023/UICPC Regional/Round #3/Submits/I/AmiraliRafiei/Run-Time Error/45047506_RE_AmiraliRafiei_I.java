import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class BAPCInterpreter {

    public static ArrayList<Integer> BAPCInterpreter(String program, int n, ArrayList<Integer> inputList) {
        ArrayList<Integer> outputList = new ArrayList<>(inputList);

        for (char command : program.toCharArray()) {
            if (command == 'R') {
                Collections.reverse(outputList);
            } else if (command == 'D') {
                if (outputList.isEmpty()) {
                    outputList.clear();
                    outputList.add(-1); // Representing "error"
                    break;
                }
                outputList.remove(0);
            }
        }

        return outputList;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int numTestCases = Integer.parseInt(scanner.nextLine());

        for (int t = 0; t < numTestCases; t++) {
            String program = scanner.nextLine();
            int n = Integer.parseInt(scanner.nextLine());

            String inputListStr = scanner.nextLine();
            ArrayList<Integer> inputList = new ArrayList<>();
            if (n > 0) {
                String[] inputArray = inputListStr.substring(1, inputListStr.length() - 1).split(",");
                for (String numStr : inputArray) {
                    inputList.add(Integer.parseInt(numStr.trim()));
                }
            }

            ArrayList<Integer> result = BAPCInterpreter(program, n, inputList);

            if (result.get(0) == -1) {
                System.out.println("error");
            } else {
                System.out.print("[");
                for (int i = 0; i < result.size(); i++) {
                    System.out.print(result.get(i));
                    if (i < result.size() - 1) {
                        System.out.print(",");
                    }
                }
                System.out.println("]");
            }
        }
    }
}
