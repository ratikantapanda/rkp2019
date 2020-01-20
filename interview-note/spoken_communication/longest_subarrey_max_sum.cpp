#include <bits/stdc++.h>
using namespace std;

// Function to find maximum length sub-array with sum S present
// in the given array
void maxLengthSubArray(int arr[], int n, int S)
{
	// create an empty multi-map to store ending index of first sub-array
	// having some sum
	unordered_map<int, int> map;

	// insert (0, -1) pair into the set to handle the case when sub-array
	// with sum S starts from index 0
	map[0] = -1;

	int sum = 0;

	// len stores the maximum length of sub-array with sum S
	int len = 0;

	// stores ending index of maximum length sub-array having sum S
	int ending_index = -1;

	// traverse the given array
	for (int i = 0; i < n; i++)
	{
		// sum of elements so far
		sum += arr[i];

		// if sum is seen for first time, insert sum with its index into the map
		if (map.find(sum) == map.end())
			map[sum] = i;

		// update length and ending index of maximum length sub-array having sum S
		if (map.find(sum - S) != map.end() && len < i - map[sum - S])
		{
			len =  i - map[sum - S];
			ending_index = i;
		}
	}

	// print the sub-array
	cout << "[" << (ending_index - len + 1) << ", " << ending_index << "]";
}

int main()
{
	int arr[] = { 5, 6, -5, 5, 3, 5, 3, -2, 0 };
	int sum = 8;

	int n = sizeof(arr) / sizeof(arr[0]);

	maxLengthSubArray(arr, n, sum);

	return 0;
}
