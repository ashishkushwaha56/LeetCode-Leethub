//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int finLength(int N, vector<int> color, vector<int> radius) {
        stack<pair<int,int>> s;
        pair<int,int> p;
        for(int i = 0;i<color.size();i++){
          p = {color[i],radius[i]};
          if(s.empty()){
            s.push(p);
          }
          else{
            if(s.top().first == p.first and s.top().second == p.second){
              s.pop();
            }
            else s.push(p);
          }
        }
        return s.size();
    }
};


//{ Driver Code Starts.
int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        vector<int> color(n), radius(n);
        for (int i = 0; i < n; i++) cin >> color[i];
        for (int i = 0; i < n; i++) cin >> radius[i];
        int ans = sol.finLength(n, color, radius);
        cout << ans << "\n";
    }

    return 0;
}

// } Driver Code Ends