//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string S, string T) {
        // code here
        // if(T.size()>S.size()){
        //     return 0;
        // }
        int i = 0;
        int j = 0;
        string a = "";
        int cnt = 0;
        while(j<T.size() and i<S.size()){
            a = "";
            cnt = 0;
            if(T[j]>='0' and T[j]<='9'){
                while(j<T.size() and (T[j]>='0' and T[j]<='9')){
                    a+=T[j];
                    j++;
                }
                cnt = stoi(a);
                if(j>=T.size()){
                    break;
                }
                if(cnt == 0){
                    if(T[j]!=S[i]){
                        return 0;
                    }
                    i++;
                    j++;
                }
                i+=(cnt);
            }
            else{
                if(T[j]!=S[i]){
                    return 0;
                }
                j++;
                i++;
            }
            // cout<<i<<" "<<j<<endl; 
        }
        if(cnt!=0){
            // cout<<i<<endl;
            if(cnt!=(S.size()-i)) return 0;
        }
        return 1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends