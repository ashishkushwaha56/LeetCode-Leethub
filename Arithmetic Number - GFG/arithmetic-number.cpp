//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int inSequence(int A, int B, int c){
        if(A == B) return 1;
        if(c == 0) return (A==B);
        else if(c<0){
            if(B>A) return 0;
            if(c == -1) return B<A;
            return (A-B)%c == 0;
        }
            if(A>B) return 0;
            if(c == 1) return A<B;
            return (B-A)%c == 0;
        
        // return (C==0)?(A == B):((C<0?((C == -1)?(B<A):((A-B)%C == 0):0)):((C == 1)?(A<B):((B-A)%C == 0)));
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int A, B, C;
        cin>>A>>B>>C;
        
        Solution ob;
        cout<<ob.inSequence(A, B, C)<<endl;
    }
    return 0;
}
// } Driver Code Ends