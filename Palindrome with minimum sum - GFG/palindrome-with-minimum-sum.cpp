//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool check(string &s){
        int l = 0;
        int r = s.size()-1;
        while(l<r){
            if(s[l] == '?' or s[r] == '?'){
                if(s[l] == '?'){
                    s[l] = s[r];
                }
                else{
                    s[r] = s[l];
                }
            }
            else if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    int minimumSum(string s) {
        // code here
        if(!check(s)) return -1;
        int mid;
        if(s.size()&1){
            mid = s.size()/2+1;
        }
        else{
            mid = s.size()/2;
        }
        int i = 0;
        int j = 1;
        string ans = s;
        int ave = 0;
        while(j<mid){
            while(i<mid and s[i] !='?'){
                i++;
            }
            if(i>0){
                i--;
            }
            j = i+1;
            // cout<<i<<" "<<j<<endl;
            // cout<<mid<<endl;
            while(j<mid and s[j] == '?'){
                j++;
            }
            if(j == mid){
                if(j-1>=0){
                    if(ans[j-1]=='?'){
                        ave = (s[i]-'a');
                        i++;
                        while(i<=j-1){
                            ans[i] = (ave+'a');
                            ans[s.size()-i-1] = (ave+'a');
                            i++;
                        }
                    }
                }
                else{
                    s[0] = 'a';
                }
            }
            else{
                // cout<<i<<" "<<j<<endl;
                if(s[i] != '?'){
                    ave = ((s[i]-'a')+(s[j]-'a'))/2;
                    i++;
                }
                else{
                    ave = (s[j]-'a');
                }
                // cout<<ave<<endl;
               
               
               while(i<=j-1){
                    ans[i] = (ave+'a');
                    ans[s.size()-i-1] = (ave+'a');
                    i++;
               }
            //   cout<<ans<<endl;
            }
        }
        int cnt= 0;
        for(int i = 0;i<s.size()-1;i++){
            cnt+=abs((ans[i+1]-'a')-(ans[i]-'a'));
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends