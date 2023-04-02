//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
	long long int minOperations(int N) {
		long long int d = 2 * N - 2;
		// long long v = 0;
		long long steps = N / 2;
		long long ans;
		if (N & 1) {
			ans = (steps * (4 + d)) / 2;
		}
		else {
			ans = (steps * (2 + d)) / 2;
		}
		return ans / 2;
	}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.minOperations(n) << endl;
    }
    return 0;
}
// } Driver Code Ends