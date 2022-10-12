//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
          unordered_map<char,int> mb;
          for(int i = 0;i<n;i++){
              mb[x[i]] = b[i];
          }
          vector<int> vb(w.size());
          for(int i = 0;i<w.size();i++){
              if(mb.find(w[i])!=mb.end()){
                  vb[i]  = mb[w[i]];
              }
              else{
                  vb[i] = (int)w[i];
              }
          }
          map<int,pair<int,int>> nb;
          int l = 0;
          int sum = 0;
          for(int i = 0;i<w.size();i++){
              sum+=vb[i];
              if(sum<0){
                  nb[sum]= make_pair(l,i);
                  sum = 0;
                  l = i+1;
              }
              else{
                  nb[sum] = make_pair(l,i);
              }
          }
          auto it = nb.end();
          it--;
          string ans = w.substr((*it).second.first,(*it).second.second-(*it).second.first+1);
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
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends