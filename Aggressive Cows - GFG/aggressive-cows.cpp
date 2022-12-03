//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    int solve(int n, int k, vector<int> &stalls) {
    
        sort(stalls.begin(),stalls.end());
        int l = 0;
        int r= stalls[stalls.size()-1];
        int ans;
        int c = 0;
        int d;
        while(l<=r){
            int mid = l+(r-l)/2;
            c = 1;
            d = stalls[0];
            auto it = lower_bound(stalls.begin(),stalls.end(),d);
            
            while(it!=stalls.end()){
                it = lower_bound(stalls.begin(),stalls.end(),d+mid);
                if(it==stalls.end()){
                    break;
                }
                d = *it;
                c++;
                if(c == k){
                    break;
                }
            }
            if(c == k){
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
                
            }
            
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends