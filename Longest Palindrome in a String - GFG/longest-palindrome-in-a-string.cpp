//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int ans = 1;
    int l = 0;
    int r = 0;
    void check(string &s, int i, int j){
        while(i>=0 and j<s.size() and s[i]==s[j]){
            i--;
            j++;
        }
        if(ans<j-i-1){
            ans = j-i-1;
            l = i+1;
            r = j-1;
        }
    }
    string longestPalin (string &s) {
        for(int i = 0;i<s.size()-1;i++){
            check(s,i,i);
            check(s,i,i+1);
        }
        return (s.substr(l,(r-l+1)));
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends