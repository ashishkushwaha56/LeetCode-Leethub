class Solution {
public:
    
    vector<int> dx = {0,1};
    vector<int> dy = {1,0};
    vector<pair<int,int>> temp;
    void dfs2(vector<vector<int>>&grid,int i,int j, bool &ok){
        if(i == grid.size()-1 and j == grid[0].size()-1){
            ok  = true;
            return;
        }
        grid[i][j] = 0;
        for(int k = 0;k<2;k++){
            if(ok) continue;
            if(i+dx[k]>=0 and i+dx[k]<grid.size() and j+dy[k]>=0 and j+dy[k]<grid[0].size() and grid[i+dx[k]][j+dy[k]]!=0){
                // temp.push_back({i+dx[k],j+dy[k]});
                dfs2(grid,i+dx[k],j+dy[k],ok);
                // temp.pop_back();
            }
        }
        // grid[i][j] = 1;
    }
    void dfs1(vector<vector<int>>&grid,int i,int j,bool &ok){
        if(i == grid.size()-1 and j == grid[0].size()-1){
            ok  = true;
            return;
        }
        if(ok) return;
        grid[i][j] = 0;
        for(int k = 0;k<2;k++){
            
            if(i+dx[k]>=0 and i+dx[k]<grid.size() and j+dy[k]>=0 and j+dy[k]<grid[0].size() and grid[i+dx[k]][j+dy[k]]!=0 and !ok){
                // temp.push_back({i+dx[k],j+dy[k]});
                dfs1(grid,i+dx[k],j+dy[k],ok);
                // temp.pop_back();
            }
        }
        if(ok) return;
        grid[i][j] = 1;
    }
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        bool ok = false;
        if(grid.size() == 1 and grid[0].size()==2) return false;
        dfs1(grid,0,0,ok);
        // cout<<ok<<endl;
        if(ok){
            // cout<<temp.size()<<endl;
            // temp.pop_back();
            // for(auto &it:temp){
            //     grid[it.first][it.second] = 0;
            // }
            ok = false;
            dfs2(grid,0,0,ok);
            if(ok) return false;
            return true;
        }
        return true;
    }
};