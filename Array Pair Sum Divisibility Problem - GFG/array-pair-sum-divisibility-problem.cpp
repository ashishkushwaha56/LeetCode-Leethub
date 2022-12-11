//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        vector<int> cv(k);
        for(int i = 0;i<nums.size();i++){
            cv[nums[i]%k]++;
        }
        int l = 1;
        int r = k-1;
        while(l<r){
            if(cv[l]!=cv[r]) return false;
            l++;
            r--;
        }
        if((cv[0]&1) or (cv[k/2]&1)) return false;
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends