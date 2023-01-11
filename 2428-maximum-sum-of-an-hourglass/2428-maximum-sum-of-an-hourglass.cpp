class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0;i<grid.size()-2;i++){
            for(int j = 0;j<grid[i].size()-2;j++){
                int d = grid[i][j]+grid[i][j+2];
                d+=(grid[i+2][j]+grid[i+2][j+2]);
                for(int k = i;k<i+3;k++){
                    d+=grid[k][j+1];
                }
                // cout<<d<<endl;
                ans = max(ans,d);
            }
        }
        return ans;
    }
};