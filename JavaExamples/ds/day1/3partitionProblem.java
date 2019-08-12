import java.util.Arrays;

class ThreePartition
{
	// Helper function for solving 3 partition problem
	// It return true if there exists three subsets with given sum
	public static boolean subsetSum(int[] S, int n, int a, int b, int c)
	{
		// return true if subset is found
		if (a == 0 && b == 0 && c == 0) {
			return true;
		}

		// base case: no items left
		if (n < 0) {
			return false;
		}

		// Case 1. current item becomes part of first subset
		boolean A = false;
		if (a - S[n] >= 0) {
			A = subsetSum(S, n - 1, a - S[n], b, c);
		}

		// Case 2. current item becomes part of second subset
		boolean B = false;
		if (!A && (b - S[n] >= 0)) {
			B = subsetSum(S, n - 1, a, b - S[n], c);
		}

		// Case 3. current item becomes part of third subset
		boolean C = false;
		if ((!A && !B) && (c - S[n] >= 0)) {
			C = subsetSum(S, n - 1, a, b, c - S[n]);
		}

		// return true if we get solution
		return A || B || C;
	}

	// Function for solving 3-partition problem. It return true if given
	// set S[0..n-1] can be divided into three subsets with equal sum
	public static boolean partition(int[] S)
	{
		if (S.length < 3) {
			return false;
		}

		// get sum of all elements in the set
		int sum = Arrays.stream(S).sum();

		// return true if sum is divisble by 3 and the set can can
		// be divided into three subsets with equal sum
		return (sum % 3) == 0 &&
				subsetSum(S, S.length - 1, sum/3, sum/3, sum/3);
	}

	public static boolean subsetSum_(int S[], int n, int a, int b, int c,int[] arr)
	{
		// return true if subset is found
		if (a == 0 && b == 0 && c == 0) {
			return true;
		}

		// base case: no items left
		if (n < 0) {
			return false;
		}

		// Case 1. current item becomes part of first subset
		boolean A = false;
		if (a - S[n] >= 0)
		{
			arr[n] = 1;		// current element goes to first subset
			A = subsetSum_(S, n - 1, a - S[n], b, c, arr);
		}

		// Case 2. current item becomes part of second subset
		boolean B = false;
		if (!A && (b - S[n] >= 0))
		{
			arr[n] = 2;		// current element goes to second subset
			B = subsetSum_(S, n - 1, a, b - S[n], c, arr);
		}

		// Case 3. current item becomes part of third subset
		boolean C = false;
		if ((!A && !B) && (c - S[n] >= 0))
		{
			arr[n] = 3;			// current element goes to third subset
			C = subsetSum_(S, n - 1, a, b, c - S[n], arr);
		}

		// return true if we get solution
		return A || B || C;
	}

	// Function for solving 3-partition problem. It prints the subset if
	// given set S[0..n-1] can be divided into three subsets with equal sum
	public static void print_partition(int[] S)
	{
		// get sum of all elements in the set
		int sum = Arrays.stream(S).sum();

		// construct an array to track the subsets
		// (A[i] = k) represents i'th item of S is part of k'th subset
		int[] A = new int[S.length];

		// set result to true if sum is divisible by 3 and the set S can
		// be divided into three subsets with equal sum

		boolean res = (S.length >= 3) &&
					(sum % 3) == 0 &&
					subsetSum_(S, S.length - 1, sum/3, sum/3, sum/3, A);

		if (!res) {
			System.out.print("3-Partition of set is not Possible");
			return;
		}

		// print the partitions
		for (int i = 0; i < 3; i++)
		{
			System.out.print("Partition " + i + " is: ");
			for (int j = 0; j < S.length; j++) {
				if (A[j] == i + 1) {
					System.out.print(S[j] + " ");
				}
			}
			System.out.print(System.lineSeparator());
		}
	}

	// main function for 3-partition problem
	public static void main(String[] args)
	{
		// Input: set of integers
		int[] S = { 7, 3, 2, 1, 5, 4, 8 };

		if (partition(S)) {
			System.out.println("Yes");
			print_partition(S);
		} else {
			System.out.println("No");
		}
	}
}
