class Solution {
public:
    vector<int> dx = {2,2,-2,-2,1,1,-1,-1};
    vector<int> dy = {1,-1,-1,1,2,-2,2,-2};
    void dfs(vector<vector<int>>&v,vector<vector<int>>&vis,int i,int j,int cnt,bool &ok){
        if(ok) return;
        for(int k = 0;k<8;k++){
            if(i+dx[k]>=0 and i+dx[k]<v.size() and j+dy[k]>=0 and j+dy[k]<v.size()){
                if(v[i+dx[k]][j+dy[k]] == cnt+1){
                    vis[i+dx[k]][j+dy[k]]=1;
                    dfs(v,vis,i+dx[k],j+dy[k],cnt+1,ok);
                }
            }
        }
        ok =true;
        
    }
    
    bool checkValidGrid(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(),vector<int>(grid.size(),0));         if(grid[0][0]!=0) return false;
        vis[0][0] = 1;
        bool ok = false;
        dfs(grid,vis,0,0,0,ok);
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid.size();j++){
                if(!vis[i][j]) return false;
            }
        }
        return true;
    }
};