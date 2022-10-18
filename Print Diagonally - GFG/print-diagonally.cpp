//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	
	vector<int> downwardDigonal(int &n, vector<vector<int>> A)
	{
	    vector<int> ans;
	    int j = 0;
	    bool flag = 1;
	    int l,r;
	    for(int i = 0;i<=2*n-1;i++){
	        if(!flag){
	            l = i%n;
	            if(l == 0)
	             continue;
	            r = n-1;
	        }
	        else{
	            l = 0;
	            r = i%n;
	            if(r==n-1){
	                flag = 0;
	            }
	        }
	        while(l<n and r>-1){
	            ans.push_back(A[l][r]);
	            l++;
	            r--;
	        }
	    }
	    return ans;
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends