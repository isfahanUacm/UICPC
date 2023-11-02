import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Shoes {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int d = sc.nextInt();
		int s = sc.nextInt();
		int t = sc.nextInt();
		int fmin = sc.nextInt();
		int fmax = sc.nextInt();
		
		ArrayList<Integer> cases = new ArrayList<Integer>();
		while(sc.hasNextInt()) {
			cases.add(sc.nextInt());
		}
		
		Integer[] L = cases.toArray(new Integer[cases.size()]);
		int [] results = countCombos(N, d, s, t, fmin, fmax, L);
		for(int result: results) {
			System.out.println(result);
		}
		sc.close();
	}

	static int[] countCombos(int N, int d, int s, int t, int fmin, int fmax, Integer[] L) {
		// number if intermediate shoelaces
		int comboEyelets = N - 2;

		int[] results = new int[L.length];
		for (int whichEyelts = 0; whichEyelts < (1 << comboEyelets); whichEyelts++) {

			// generate the current combo
			ArrayList<Integer> currentCombo = new ArrayList<>();
			int comboIndex = 0;
			int comboRunningValue = whichEyelts;
			while (comboRunningValue > 0) {
				if (comboRunningValue % 2 == 1) {
					currentCombo.add(comboIndex + 1);
				}
				comboRunningValue /= 2;
				comboIndex++;
			}

			ArrayList<ArrayList<Integer>> allPerms = permutation(currentCombo);

			for (ArrayList<Integer> path : allPerms) {
				for (int crossCounter = 0; crossCounter < (1 << path.size()); crossCounter++) {
					int[] curResults = validate(N, d, s, t, fmin, fmax, L, path, crossCounter);
					if (curResults != null) {
						for (int i = 0; i < curResults.length; i++) {
							results[i] += curResults[i];
						}
					}
				}
			}
		}

		// 'one' more case of going directly from the first to the last eyelet
		double totalEyeletLength = 4 * t;
		for (int laceIndex = 0; laceIndex < L.length; laceIndex++) {
			double lace = L[laceIndex];
			double vertical = (double) (N - 1) * (double) (d);
			double sSquared = s * s;
			double crossLength = Math.sqrt(vertical * vertical + sSquared);
			double totalLength = crossLength * 2. + (double) s + totalEyeletLength;
			double remainingLace = (lace - totalLength) / 2;

			if (remainingLace <= fmax && remainingLace >= fmin) {
				results[laceIndex]++;
			}

			if (N == 2) {
				totalLength = s + d + d + totalEyeletLength;
				remainingLace = (lace - totalLength) / 2;

				if (remainingLace <= fmax && remainingLace >= fmin) {
					results[laceIndex]++;
				}
			}
		}

		return results;
	}

	private static int[] validate(int N, int d, int s, int t, int fmin, int fmax, Integer[] L, ArrayList<Integer> path,
			int crossCounter) {
		int runningCross = crossCounter;
		int lastCross = 0;
		double sSquared = s * s;

		double runningTotal = 0;
		int curEyelet = 0;

		for (Integer nextEyelet : path) {
			// same column
			int curCross = runningCross % 2;

			if (lastCross == curCross) {
				if (Math.abs(nextEyelet - curEyelet) > 1) {
					return null;
				}
				runningTotal += d;
			} else {
				double vertical = d * Math.abs(curEyelet - nextEyelet);
				runningTotal += Math.sqrt(vertical * vertical + sSquared);
			}

			curEyelet = nextEyelet;
			lastCross = curCross;
			runningCross /= 2;
		}

		double totalEyeletLength = t * (4 + path.size() * 2);
		int[] result = new int[L.length];
		for (int laceIndex = 0; laceIndex < L.length; laceIndex++) {
			int lace = L[laceIndex];
			int lastEyelet = path.get(path.size() - 1);
			double leftVertical = d * Math.abs((N - 1) - path.get(path.size() - 1));
			double leftAddition = Math.sqrt(sSquared + leftVertical * leftVertical);

			double remainingLace = (lace - ((runningTotal + leftAddition) * 2 + s + totalEyeletLength)) / 2;
			if (remainingLace <= fmax && remainingLace >= fmin) {
				result[laceIndex]++;
			}

			// check for the right only if the path ends on the last eyelet it can
			if (lastEyelet == N - 2) {
				double rightAddition = d;
				remainingLace = (lace - ((runningTotal + rightAddition) * 2 + s + totalEyeletLength)) / 2;
				if (remainingLace <= fmax && remainingLace >= fmin) {
					result[laceIndex]++;
				}
			}
		}

		return result;
	}

	public static ArrayList<ArrayList<Integer>> permutation(List<Integer> s) {
		ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
		if (s.size() == 1) {
			res.add(new ArrayList<Integer>(s));
		} else if (s.size() > 1) {
			res = merge(permutation(s.subList(0, s.size() - 1)), s.get(s.size() - 1));
		}
		return res;
	}

	public static ArrayList<ArrayList<Integer>> merge(List<ArrayList<Integer>> list, Integer c) {
		ArrayList<ArrayList<Integer>> res = new ArrayList<>();
		for (ArrayList<Integer> s : list) {
			for (int i = 0; i <= s.size(); ++i) {
				ArrayList<Integer> ps = new ArrayList<Integer>(s);
				ps.add(i, c);
				res.add(ps);
			}
		}
		return res;
	}
}
