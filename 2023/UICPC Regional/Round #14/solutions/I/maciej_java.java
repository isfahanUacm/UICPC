// @EXPECTED_RESULTS@: CORRECT

import java.util.Scanner;


public class maciej_java {

	/**
	 * @param args
	 */
	static int MaxLength=101; 
	public static void main(String[] args) {
		int NumberOfCases;
		long value_M, temp_value_M, value_Z, temp_value_Z;
		long suffix_M, suffix_Z, powers;
		int[] M = new int[MaxLength];
		int[] Z = new int[MaxLength];
		int r;
		long[] F = new long[MaxLength];
		long[] S = new long[MaxLength];
		int c,n,i,j,k,digit;
		long temp;

		Scanner sc = new Scanner(System.in);

		NumberOfCases = sc.nextInt();
		for (c = 1; c <= NumberOfCases; c++) {
			value_M = Long.parseLong(sc.next());
			value_Z = Long.parseLong(sc.next());
			r = Integer.parseInt(sc.next());
			value_M--;

			// compute decimal representaions M[n]...M[2]M[1] and Z[n]...Z[2]Z[1]
			n=0;
			temp_value_M=value_M; 
			temp_value_Z=value_Z;
			do {
				n++;
				digit =(int)( temp_value_M % 10);
				M[n] = digit;
				temp_value_M /= 10;
				digit =(int)( temp_value_Z % 10);
				Z[n] = digit;
				temp_value_Z /= 10;
			} while( temp_value_M > 0);

			// compute an auxiliary function F:
				// F(k), with k=1,...,n, counts the number of different strings of length k which 
			// are *not* r-matched by Z[k]...Z[1] (in fact, this value does not depend from Z)
			// it is not difficult to see that F(k) = sum_{i=1}^r 9*F(k-i)
			// with termination conditions: F(k)=0 for k < -1, F(-1) = 1/9  and  F(0) = 1

			for (k = 0; k <= n; k++) { 
				temp=0;
				for (i = 1; i <= r; i++) {
					if ((k-i) == -1) temp = temp+1;
					if ((k-i) == 0)  temp = temp+9;
					if ((k-i) > 0)   temp = temp+9*F[k-i];
				}
				F[k]=temp;
			}

			// compute function S:
			// S(k) = #{w: |w|=k, w <= M[k]...M[1], and Z[k]...Z[1] does not r-match w}
			// the number of selected tickets is: number of submissions - S(n)

			// basis: values S[1],..., S[r]

			powers=10;
			for (i = 1; i <= r-1; i++) {
				suffix_M = (long)( value_M % powers);
				S[i] = (suffix_M + 1);
				powers=powers*10;
			}
			suffix_M = (long)( value_M % powers);
			suffix_Z = (long)( value_Z % powers);
			if (suffix_M < suffix_Z) {
				S[r] = (suffix_M + 1);
			}
			else {
				S[r]= (suffix_M + 1) - 1;
			}

			// recurrence for S[r+1],...,S[n]

			for (k = r+1; k <= n; k++) { 
				temp=0;
				if (Z[k] > M[k]) temp = M[k]*F[k-1] + S[k-1];
				if (Z[k] < M[k]){
					temp = (M[k]-1)*F[k-1] + S[k-1];
					for (i = 2; i <= r; i++) {
						temp = temp + 9*F[k-i];
					}
				}
				if (Z[k] == M[k]){
					temp = M[k]*F[k-1];  
					for (i = 2; i <= r; i++) {
						if (Z[k-i+1] > M[k-i+1]) {
							temp = temp + M[k-i+1]*F[k-i] + S[k-i];
							break; //break loop
						}
						if (Z[k-i+1] < M[k-i+1]) {
							temp = temp + (M[k-i+1]-1)*F[k-i]+S[k-i];
							for (j = i+1; j <= r; j++) {
								temp = temp + 9*F[k-j];
							}
							break; //break loop
						}
						if (Z[k-i+1] == M[k-i+1]) {
							temp = temp + M[k-i+1]*F[k-i];
						}
					}
				}
				S[k]=temp;
			}
			System.out.println(value_M+1-S[n]);
		}
	}

}
