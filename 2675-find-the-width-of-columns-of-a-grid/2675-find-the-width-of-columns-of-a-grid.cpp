class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int> ans(grid[0].size());
        int cnt = 0;
        // int a;
        // int d = 0;
        string a = "";
        for(int j = 0;j<grid[0].size();j++){
            cnt = 0;
            for(int i = 0;i<grid.size();i++){
                a = to_string(grid[i][j]);
                cnt = max(cnt,(int)a.size());
            }
            ans[j] = cnt;
        }
        return ans;
    }
};