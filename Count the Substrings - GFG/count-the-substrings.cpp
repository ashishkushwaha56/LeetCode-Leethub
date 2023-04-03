//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
	int countSubstring(string s)
	{
		int i = 1;
		int k;
		int ans = 0;
		int small = 0, large = 0;
		while (i < s.size()) {
			k = 0;
			small = large = 0;
			// debug(i)
			while (k <= i) {
				if (s[k] >= 'a' and s[k] <= 'z') {
					small++;
				}
				else if (s[k] >= 'A' and s[k] <= 'Z') {
					large++;
				}
				k++;
			}
			// debug(k)
			// debug(mp(large, small))
			while (k < s.size()) {
				if (large == small and large != 0 and small != 0) {
					ans++;
				}
				if (s[k] >= 'a' and s[k] <= 'z') small++;
				else if (s[k] >= 'A' and s[k] <= 'Z') large++;
				if (s[k - (i + 1)] >= 'a' and s[k - (i + 1)] <= 'z') small--;
				else if (s[k - (i + 1)] >= 'A' and s[k - (i + 1)] <= 'Z') large--;
				k++;
			}
			if (small == large and large != 0 and small != 0) ans++;
			// debug(mp(large, small))
			// debug(ans)
			i += 2;
		}
		return ans;
	}
};


//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends