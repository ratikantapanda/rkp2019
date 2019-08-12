import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Arrays;

class PowerSet
{
	// Function to generate power set of given set S
	public static void findPowerSet(int[] S, Deque<Integer> set, int n)
	{
		// if we have considered all elements
		if (n == 0) {
			System.out.println(set);
			return;
		}

		// consider nth element
		set.addLast(S[n - 1]);
		findPowerSet(S, set, n - 1);

		// or don't consider nth element
		set.removeLast();
		findPowerSet(S, set, n - 1);
	}
    public static void findDistictSubSets(int[] S, Deque<Integer> out, int i)
	{
		// if all elements are processed, print the current subset
		if (i < 0) {
			System.out.println(out);
			return;
		}

		// include current element in the current subset and recur
		out.addLast(S[i]);
		findDistictSubSets(S, out, i-1);

		// exclude current element in the current subset
		out.removeLast();

		// remove adjacent duplicate elements
		while (i > 0 && S[i] == S[i-1]) {
			i--;
		}

		// exclude current element in the current subset and recur
        	findDistictSubSets(S, out, i-1);
	}
	public static void main(String[] args)
	{
		int[] S = { 1, 2, 3 };
        Deque<Integer> set = new ArrayDeque<>(); 
        findPowerSet(S, set, S.length);
        System.out.println("===========================");        
        int[] S1 = { 1, 3, 1 };
        //sort the set
		Arrays.sort(S1);          
		// create an empty list to store elements of a subset
		Deque<Integer> out = new ArrayDeque<>();          
		findDistictSubSets(S, out, S1.length-1) ;
	}
}