//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
	bool wifiRange(int N, string S, int X) {
		vector<int> v;
		for (int i = 0; i < N; i++) {
			if (S[i] == '1') v.push_back(i);
		}
		int k = N ;
// 		debug(v)
		for (int i = v.size() - 1; i >= 0; i--) {
// 			debug(k)
			if (v[i] + X + 1 < k) return false;
			k = min(k, v[i] - X);
		}
		if (k > 0) return false;
		return true;
	}
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends