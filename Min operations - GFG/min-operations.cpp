//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int a, int b) {
        // cout<<(a&b)<<endl;
        if((a&b) == a and (a&b) == b) return 0;
        if(a<b){
            if(((b-a)&(a)) == 0) return 1;
            else return 2;
        }
        else {
            if(((a-b)&(b)) == 0) return 1;
            else return 2;
        }
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int a;
        scanf("%d",&a);
        
        
        int b;
        scanf("%d",&b);
        
        Solution obj;
        int res = obj.solve(a, b);
        
        printf("%d\n", res);
        
    }
}

// } Driver Code Ends