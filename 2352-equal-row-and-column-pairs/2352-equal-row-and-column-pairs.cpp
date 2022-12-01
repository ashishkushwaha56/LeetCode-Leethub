class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string,int> row,col;
        string s = "";
        vector<string> vb(grid.size());
        for(int i = 0;i<grid.size();i++){
            s="";
            for(int j = 0;j<grid[i].size();j++){
                s+=(" "+to_string(grid[i][j]));
                vb[j]+=(" "+to_string(grid[i][j]));
                if(j == grid.size()-1){
                    row[s]++;
                }
            }
            
        }
        for(auto &it:vb){
            col[it]++;
        }
        int ans = 0;
        for(auto &it:row){
            if(col.find(it.first)!=col.end()){
                ans+=col[it.first]*it.second;
                col.erase(it.first);
            }
        }
        
        for(auto &it:col){
            if(row.find(it.first)!=row.end()){
                ans+=row[it.first]*it.second;
            }
        }
        return ans;
    }
};