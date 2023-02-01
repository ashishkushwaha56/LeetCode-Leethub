//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    vector<int> dx = {0,0,1,-1,1,1,-1,-1};
    vector<int> dy = {1,-1,0,0,1,-1,1,-1};
    
    void dfs(vector<vector<int>>&v,int i,int j,int &ans){
        for(int k = 0;k<8;k++){
            if(i+dx[k]>=0 and i+dx[k]<v.size() and j+dy[k]>=0 and j+dy[k]<v[i].size() ){
                if(v[i+dx[k]][j+dy[k]] == 0) continue;
                v[i+dx[k]][j+dy[k]] = 0;
                ans++;
                dfs(v,i+dx[k],j+dy[k],ans);
            }
        }
    }
    int findMaxArea(vector<vector<int>>& grid) {
        int ans = 0;
        int temp = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[i].size();j++){
                if(grid[i][j] == 1){
                    temp = 0;
                    grid[i][j] = 0;
                    dfs(grid,i,j,temp);
                    ans = max(ans,1+temp);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends