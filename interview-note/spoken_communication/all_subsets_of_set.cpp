#include <bits/stdc++.h>
using namespace std;

// Iterative function to print all distinct subsets of S
void findPowerSet(vector<int> const &S, int n)
{
	// N stores total number of subsets
	int N = pow(2, n);
	unordered_set<string> set;

	// generate each subset one by one
	for (int i = 0; i < N; i++)
	{
		string subset;
		// check every bit of i
		for (int j = 0; j < n; j++)
		{
			// if j'th bit of i is set, append S[j] to subset
			if (i & (1 << j))
				subset += to_string(S[j]) + " ";
		}

		// insert the subset into the set
		set.insert(subset);
	}
	
	// print all subsets present in the set
	for (string subset: set)
		cout << subset << endl;
}

// main function
int main()
{
	vector<int> S = { 11,21,31};
	int n = S.size();

	// sort the set
	sort(S.begin(), S.end());
	
	findPowerSet(S, n);
	
	return 0;
}
