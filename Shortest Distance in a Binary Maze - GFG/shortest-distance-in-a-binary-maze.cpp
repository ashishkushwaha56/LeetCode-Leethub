//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        queue<pair<int,int>> q;
        q.push(source);
        int l = 1,r = 0;
        int ans = 1;
        bool ok = false;
        while(!q.empty()){
           pair<int,int> p = q.front();
           if(p == destination){
               ok = true;
               break;
           }
           q.pop();
           l--;
           if(p.first>=0 and p.first<grid.size() and p.second+1>=0 and p.second+1<grid[0].size()){
               if(grid[p.first][p.second+1]!=0){
                   grid[p.first][p.second+1] = 0;
                   q.push({p.first,p.second+1});
                   r++;
               }
           }
           if(p.first+1>=0 and p.first+1<grid.size() and p.second>=0 and p.second<grid[0].size()){
               if(grid[p.first+1][p.second]!=0){
                   grid[p.first+1][p.second] = 0;
                   q.push({p.first+1,p.second});
                   r++;
               }
           }
           if(p.first-1>=0 and p.first-1<grid.size() and p.second>=0 and p.second<grid[0].size()){
               if(grid[p.first-1][p.second]!=0){
                   grid[p.first-1][p.second] = 0;
                   q.push({p.first-1,p.second});
                   r++;
               }
           }
           if(p.first>=0 and p.first<grid.size() and p.second-1>=0 and p.second-1<grid[0].size()){
               if(grid[p.first][p.second-1]!=0){
                   grid[p.first][p.second-1] = 0;
                   q.push({p.first,p.second-1});
                   r++;
               }
           }
           if(l == 0){
               ans++;
               l = r;
               r = 0;
           }
        }
        if(!ok){
            return -1;
        }
        return ans-1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends