//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){
      unordered_set<int> rows,columns;
      int count_rows = 0,count_columns =0;
      long long zero = n*n;
      vector<long long> ans;
      for(int i = 0;i<arr.size();i++){
          if(rows.find(arr[i][0])==rows.end()){
              zero-=(n-count_columns);
              rows.insert(arr[i][0]);
              count_rows++;
          }
          if(columns.find(arr[i][1])==columns.end()){
              zero-=(n-count_rows);
              columns.insert(arr[i][1]);
              count_columns++;
          }
          ans.push_back(zero);
      }
      return ans;
  }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    
    return 0;
}


// } Driver Code Ends