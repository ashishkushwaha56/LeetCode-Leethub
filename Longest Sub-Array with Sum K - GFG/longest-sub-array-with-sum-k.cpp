//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        unordered_map<int,int> mb;
        mb[0] = -1;
        int sum = 0;
        int ans = 0;
        for(int i = 0;i<N;i++){
            sum+=A[i];
            if(mb.find(sum-K) !=mb.end()){
                ans = max(ans,i-mb[sum-K]);
            }
            if(mb.find(sum)==mb.end()){
                mb[sum] = i;
            }
        }
        return ans;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends