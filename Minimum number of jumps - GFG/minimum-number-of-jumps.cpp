//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution {
public:
	int minJumps(int arr[], int n) {
		int i = 0;
		if(n==1) return 0;
		if (arr[i] == 0) return -1;
		int j = arr[i];
		int diff = j - i;
		int ans = 0;
		
		while (i < n - 1) {
			int maxlen = 0;
			j = i + arr[i];
			if(j>=n) { ans++; break;}
			if (j == i) return -1;
			int t = j;
			int k = j;
			while (t > i ) {
				if (arr[t] + t - i > maxlen) {
					maxlen  = arr[t] + t - i;
					k = t;
				}
				t--;
			}
			i = k;
			ans++;
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
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends