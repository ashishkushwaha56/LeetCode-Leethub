class Solution {
public:
    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,1,-1};  
    bool ok = false;  
    void helper(vector<vector<int>>&vis,vector<vector<int>>&gg,int n, int m ,int i, int j){
        if(i == n-1) {
            ok = true;
            return;
        }
        if(ok) return;
        vis[i][j] = 1;
        for(int k= 0;k<4;k++){
            if(ok) return;
            if(i+dx[k]>=0 and i+dx[k]<n and j+dy[k]>=0 and j+dy[k]<m and gg[i+dx[k]][j+dy[k]]!=1 and !ok and !vis[i+dx[k]][j+dy[k]])
            {
                helper(vis,gg,n,m,i+dx[k],j+dy[k]);
            }
        }
        // gg[i][j] = 0;
        // return false;
    }
    // bool check(vector<vector<int>>&gg,int n, int m){
    //     for(int j = 0;j<m and !ok;j++){
    //         if(gg[0][j]!=1 and !ok){
    //             helper(gg,n,m,0,j);
    //             if(ok) return true;
    //         }
    //     }
    //     return false;
    // }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int l = 0;
        int r = cells.size()-1;
        vector<vector<int>> gg(row,vector<int>(col));
        int ans = l;

        while(l<=r){
            int mid = l+(r-l)/2;
            vector<vector<int>> vis(row,vector<int>(col));
            for(int i = 0;i<row;i++){
                for(int j = 0;j<col;j++){
                    gg[i][j] = 0;
                }
            }
            ok=false;
            for(int i = 0;i<mid;i++){
                gg[cells[i][0]-1][cells[i][1]-1] = 1;
            }
            for(int j = 0;j<col and !ok;j++){
                if(gg[0][j]!=1 and !ok and vis[0][j]!=1){
                    helper(vis,gg,row,col,0,j);
                    // if(ok) return true;
                }
            }
            // return false;
            if(ok){
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        return ans;
    }
};