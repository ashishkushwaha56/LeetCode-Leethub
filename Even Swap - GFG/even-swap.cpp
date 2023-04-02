//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
	vector <int> lexicographicallyLargest(vector <int> &a, int n)
	{
		vector<int> ans = a;
		int l = 0;
		int flag = (ans[0] & 1);
		int i;
		for (i = 0; i < n; i++) {

			if (flag) {
				if (!(ans[i] & 1)) {
				// 	debug(mp(l, i))
					sort(ans.rbegin() + n - i, ans.rbegin() + n - l);
				// 	debug(ans)
					l = i;
					flag = 0;
				}

			}
			else if (flag == 0) {
				if ((ans[i] & 1)) {
				// 	debug(mp(l, i))
					sort(ans.rbegin() + n - i, ans.rbegin() + n - l);
				// 	debug(ans)
					l = i;
					flag = 1;
				}
			}

		}
		sort(ans.rbegin() + n - i, ans.rbegin() + n - l);
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
        int n;
        cin>>n;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        vector <int> b=s.lexicographicallyLargest(a,n);
        for(auto i:b)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends