// C++ program to get largest palindrome changing
// atmost K digits
#include <bits/stdc++.h>
using namespace std;

// Returns maximum possible palindrome using k changes
string maximumPalinUsingKChanges(string str, int k) {
	string palin = str;

	// Iinitialize l and r by leftmost and
	// rightmost ends
	int l = 0;
	int r = str.length() - 1;

	// first try to make string palindrome
	while (l < r)
	{
		// Replace left and right character by
		// maximum of both
		if (str[l] != str[r])
		{
			palin[l] = palin[r] = max(str[l], str[r]);
			k--;
		}
		l++;
		r--;
	}

	// If k is negative then we can't make
	// string palindrome
	if (k < 0)
		return "Not possible";

	l = 0;
	r = str.length() - 1;

	while (l <= r)
	{
		// At mid character, if K>0 then change
		// it to 9
		if (l == r)
		{
			if (k > 0)
				palin[l] = '9';
		}

		// If character at lth (same as rth) is
		// less than 9
		if (palin[l] < '9'){
			if (k >= 2 && palin[l] == str[l] && palin[r] == str[r]){
				k -= 2;
				palin[l] = palin[r] = '9';
			}

			/* If one of them is changed in the previous
				loop then subtract 1 from K (1 more is
				subtracted already) and make them 9 */
			else if (k >= 1 && (palin[l] != str[l] || palin[r] != str[r])){
				k--;
				palin[l] = palin[r] = '9';
			}
		}
		l++;
		r--;
	}

	return palin;
}

// Driver code to test above methods
int main()
{
	string str = "43435";
	int k = 3;
	cout << maximumPalinUsingKChanges(str, k);
	return 0;
}
