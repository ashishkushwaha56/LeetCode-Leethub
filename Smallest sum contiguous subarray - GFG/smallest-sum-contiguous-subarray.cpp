//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int smallestSumSubarray(vector<int>& a){
     int sum = 0;
     int ok = 0;
     int ans = *min_element(a.begin(),a.end());
     for(int i = 0;i<a.size();i++){
         sum+=a[i];
         if(sum>=0){
             sum = 0;
         }
         if(a[i]<0){
             ok =1;
         }
         ans = min(sum,ans);
     }
     if(!ok){
         ans = *min_element(a.begin(),a.end());
     }
     return ans;
  }
};


//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        
        int ans = ob.smallestSumSubarray(a);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends