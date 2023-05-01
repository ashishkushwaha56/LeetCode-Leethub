//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string>  ans;
    void dfs(vector<vector<int>>&v,string &s, int m,int n,int i,int j){
        if(i<0 or i>=n or j<0 or j>=m){
            return;
        }
        if(v[i][j] == 0) return;
        if(i == n-1 and j == m-1){
            ans.push_back(s);
            return;
        }
        v[i][j] = 0;
        if(j+1<m and v[i][j+1] == 1){
            s+='R';
            dfs(v,s,m,n,i,j+1);
            s.pop_back();
        }
        if(i+1<n and v[i+1][j] == 1){
            s+='D';
            dfs(v,s,m,n,i+1,j);
            s.pop_back();
        }
        if(i-1>=0 and v[i-1][j] == 1){
            s+='U';
            dfs(v,s,m,n,i-1,j);
            s.pop_back();
        }
        if(j-1>=0 and v[i][j-1] == 1){
            s+='L';
            dfs(v,s,m,n,i,j-1);
            s.pop_back();
            
        }
        v[i][j] = 1;
    }
    vector<string> findPath(vector<vector<int>> &v, int n) {
        // Your code goes here
        string  s = "";
        int m = v[0].size();
        int b=v.size();
        // int i = 0,j = 0;
        // if(j+1<m and v[i][j+1] == 1){
        //     s+='R';
        //     dfs(v,s,m,b,i,j+1);
        //     s.pop_back();
        // }
        // if(i+1<n and v[i+1][j] == 1){
        //     s+='D';
        //     dfs(v,s,m,b,i+1,j);
        //     s.pop_back();
        // }
        // if(i-1>=0 and v[i-1][j] == 1){
        //     s+='U';
        //     dfs(v,s,m,b,i-1,j);
        //     s.pop_back();
        // }
        // if(j-1>=0 and v[i][j-1] == 1){
        //     s+='L';
        //     dfs(v,s,m,b,i,j-1);
        //     s.pop_back();
            
        // }
        dfs(v,s,m,b,0,0);
        // if(ans.size() == 0) return {
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends