//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimizeSum(int N, vector<int> arr) {
        int ans = 0;
        priority_queue<int,vector<int>,greater<int>> q;
        int b;
        for(int i =0;i<N;i++){
            q.push(arr[i]);
        }
        while(q.size()>=2){
            b = q.top();
            q.pop();
            b+=q.top();
            q.pop();
            ans+=b;
            q.push(b);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minimizeSum(n, arr) << "\n";
    }
}
// } Driver Code Ends