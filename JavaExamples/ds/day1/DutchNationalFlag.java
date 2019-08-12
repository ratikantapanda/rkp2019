import java.util.Arrays;

class DutchNationalFlag
{
	// Utility function to swap two elements A[i] and A[j] in the array
	private static void swap(int[] A, int i, int j) {
		int temp = A[i];
		A[i] = A[j];
		A[j] = temp;
	}

	// Linear-time partition routine to sort an array containing 0, 1 and 2
	// It similar to three-way Partitioning for Dutch national flag problem
	public static void threeWayPartition(int[] A)
	{
		int start = 0, mid = 0, end=A.length-1;
		int pivot = 1;

		while (mid <= end)
		{
			if (A[mid] < pivot)		 // current element is 0
			{
				swap(A, start, mid);
				++start;
				++mid;
			}
			else if (A[mid] > pivot)	// current element is 2
			{
				swap(A, mid, end);
				--end;
			}
			else						// current element is 1
				++mid;
		}
	}
	public static  void sortBinaryArray(int[] A)
	{
		//two-way partition.
		int start=0, mid=0, end=A.length-1;
		int pivot=1;
		while( mid <= end)
		{
			if(A[mid] < pivot)
			{
				swap(A,start,mid);
				++start;
				++mid;
			}
			else 
				++mid;
		}

	}

	public static void binary_sort(int[] A)
	{
		// k stores index of next available position
		int k = 0;

		// do for each element
		for (int i = 0; i < A.length; i++)
		{
			// if current element is zero, put 0 at next free
			// position in the array
			if (A[i] == 0) {
				A[k++] = 0;
			}
		}

		// fill all remaining indices by 1
		for (int i = k; i < A.length; i++) {
			A[k++] = 1;
		}
	}
	
	// Sort an array containing 0’s, 1’s and 2’s
	public static void main (String[] args)
	{
		int A[] = { 0, 1, 2, 2, 1, 0, 0, 2, 0, 1, 1, 0 };

		threeWayPartition(A);
		System.out.println(Arrays.toString(A));
		int[] A2={1,0,0,1,1,0,1,1,0};
		sortBinaryArray(A2);
		System.out.println(Arrays.toString(A2));
		int[] A3={1,0,0,1,1,0,1,1,0};
		binary_sort(A3);
		System.out.println(Arrays.toString(A3));
	}
}