import java.util.Arrays;

class ProductOfLeftRightSubArrays
{
	// Recursive function to replace each element of the array with product
	// of every other element without using division operator
	public static int findProduct(int[] A, int n, int left, int i)
	{
		// base case: no elements left on right side
		if (i == n) {
			return 1;
		}

		// take back-up of current element
		int curr = A[i];

		// calculate product of the right sub-array
		int right = findProduct(A, n, left * A[i], i + 1);

		// replace current element with product of left and right sub-array
		A[i] = left * right;

		// return product of right sub-array including current element
		return curr * right;
	}
// iterative function
	public static void findProduct_i(int[] A)
	{
		int n = A.length;

		// use two auxiliary arrays
		int[] left = new int[n];
		int[] right = new int[n];

		// left[i] stores the product of all elements in the sub-array[0..i-1]
		left[0] = 1;
		for (int i = 1; i < n; i++) {
			left[i] = A[i - 1] * left[i - 1];
		}

		// right[i] stores the product of all elements in sub-array[i+1..n-1]
		right[n - 1] = 1;
		for (int j = n - 2; j >= 0; j--) {
			right[j] = A[j + 1] * right[j + 1];
		}

		// replace each element with product of its left and right sub-array
		for (int i = 0; i < n; i++) {
			A[i] = left[i] * right[i];
		}
	}

	// main function
	public static void main(String[] args)
	{
		int[] A = { 5, 3, 4, 2, 6, 8 };

        //findProduct(A, A.length, 1, 0);
        findProduct_i(A);

		// print the modified array
		System.out.println(Arrays.toString(A));
	}
}