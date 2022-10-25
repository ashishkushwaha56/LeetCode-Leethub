//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int> ans;
        priority_queue<pair<int,int>>temp;
        for(int i = 0;i<k;i++){
            temp.push(make_pair(arr[i],i));
        }
        ans.push_back(temp.top().first);
        pair<int,int>p;
        for(int i = k;i<n;i++){
            temp.push(make_pair(arr[i],i));
            p = temp.top();
            if(p.second>i-k){
                ans.push_back(p.first);
            }
            else{
                while(temp.top().second<=i-k){
                    temp.pop();
                }
                ans.push_back(temp.top().first);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends