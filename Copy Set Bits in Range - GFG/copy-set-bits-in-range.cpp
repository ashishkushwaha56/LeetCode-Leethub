//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
    public:
    int setSetBit(int x, int y, int l, int r){
        // code here
        string a = "";
        string b = "";
        while(x>0){
            if(x&1){
                a+='1';
            }
            else a+='0';
            x>>=1;
        }
        while(y>0){
            if(y&1){
                b+='1';
            }
            else b+='0';
            y>>=1;
        }
        while(a.size()<32){
            a+='0';
        }
        while(b.size()<32){
            b+='0';
        }
        for(int i = l-1;i<r;i++){
            if(b[i] == '1'){
                a[i] = '1';
            }
        }
        // reverse(a.begin(),a.end());
        long long i = 1;
        long long ans = 0;
        for(int j = 0;j<a.size();j++){
            if(a[j]=='1'){
                ans+=i;
            }
            i*=2;
        }
        return ans;
        // reverse(a.begin(),a.end());
        
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int x, y, l, r;
        cin>>x>>y>>l>>r;
        
        Solution ob;
        cout<<ob.setSetBit(x, y, l, r)<<"\n";
    }
    return 0;
}
// } Driver Code Ends