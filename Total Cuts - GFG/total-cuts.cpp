//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int N,int K,vector<int> &A){
        // Code here
        vector<pair<int,int>> v(N);
        int mine = A[N-1];
        int maxe = A[0];
        for(int i = 0;i<N;i++){
            maxe = max(maxe,A[i]);
            mine = min(mine,A[N-i-1]);
            v[i].first = maxe;
            v[N-i-1].second = mine;
        }
        int ans = 0;
        for(int i = 0;i<N-1;i++){
            if(v[i].first+v[i+1].second>=K) ans++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends