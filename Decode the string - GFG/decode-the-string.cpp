//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
	string decodedString(string &s) {
		stack<char> ans;
		int i = 0;
		int n = s.size();
		string h, g, k;
		int a = 0;
		while (i < n) {
			if (s[i] == ']') {
				h = "";
				// debug(ans)
				while (!ans.empty() and ans.top() >= 'a' and ans.top() <= 'z') {
					h += ans.top();
					ans.pop();
				}
				ans.pop();
				// debug(h)
				reverse(h.begin(), h.end());
				k = "";
				while (!ans.empty() and ans.top() >= '0' and ans.top() <= '9') {
				// 	debug(ans.top())
					k += ans.top();
					ans.pop();
				}
				// debug(k)
				reverse(k.begin(), k.end());
				a = 0;
				for (int j = 0; j < k.size(); j++) {
					a = a * 10 + (k[j] - '0');
				}
				g = "";
				for (int j = 0; j < a; j++) {
					g += h;
				}
				for (int j = 0; j < g.size(); j++) {
					ans.push(g[j]);
				}
				// debug(ans)
			}
			else {

				ans.push(s[i]);
			}
			i++;
		}
		string res = "";
		while (!ans.empty()) {
			res += ans.top();
			ans.pop();
		}
		reverse(res.begin(), res.end());
		return res;
	}
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends