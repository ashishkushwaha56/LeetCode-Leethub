//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    int minVal(int a, int b) {
        int cnt = 0;
        while(b){
            if(b&1){
                cnt++;
            }
            b>>=1;
        }
        string s = "";
        while(a){
            if(a&1){
                s+='1';
            }
            else{
                s+='0';
            }
            a>>=1;
        }
        reverse(s.begin(),s.end());
        string c = string(s.size(),'0');
        for(int i = 0;i<s.size();i++){
            if(cnt and s[i] == '1'){
                c[i] = '1';
                cnt--;
            }
        }
        int j = c.size()-1;
        while(j>=0){
            if(cnt == 0) break;
            if(c[j] == '0'){
                c[j] = '1';
                cnt--;
            }
            
            j--;
        }
        j = 1;
        int ans = 0;
        for(int i = c.size()-1;i>=0;i--){
            if(c[i] == '1'){
                ans+=j;
            }
            j*=2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends