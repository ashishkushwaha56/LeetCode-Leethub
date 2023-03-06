//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
    int noConseBits(int n) {
        // code 
    if(n <4){
        return n;
    }
        string s = "";
	while (n) {
		if (n & 1) s += '1';
		else s += '0';
		n >>= 1;
	}
	reverse(s.begin(), s.end());
	int i = 0;
	while (i < s.size() - 2) {
		if (s[i] == '1' and s[i + 1] == '1' and s[i + 2] == '1') {
			s[i + 2] = '0';
			i += 3;
		}
		else {
			i++;
		}
	}
	int cnt = 0;
	i = 1;
	for (int j = s.size() - 1; j >= 0; j--) {
		if (s[j] == '1')
			cnt += i;
		i *= 2;
	}
	return cnt;
    }
};


//{ Driver Code Starts.

int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        int ans = sol.noConseBits(n);
        cout << ans << '\n';
    }

    return 0;
}

// } Driver Code Ends