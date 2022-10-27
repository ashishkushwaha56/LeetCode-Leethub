//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leafNodes(int arr[],int n) {
        vector<int> ans;
        stack<int> s;
        int cnt = 0;
        int d = 0;
        for(int i = 0;i<n;i++){
            d = 0;
            cnt = 0;
            while(!s.empty() and s.top()<arr[i]){
                if(d == 0)
                    d = s.top();
                s.pop();
                cnt++;
            }
            if(cnt>=2)
                ans.push_back(d);
            s.push(arr[i]);
        }
        ans.push_back(s.top());
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
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends