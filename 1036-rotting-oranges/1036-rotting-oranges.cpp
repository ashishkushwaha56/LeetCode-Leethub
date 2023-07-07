class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        // pair<int,int> temp;
        int t = 0;
        int needed = 0;
        
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == 2) {
                    grid[i][j] = 0;
                    q.push({i,j});
                    t++;
                }
                if(grid[i][j] == 1){
                    needed++;
                }
            }
        }
        // if(t==0) return 0;
        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};
        int c = 0;
        int ans =0;
        // cout<<needed<<endl;
        // cout<<t<<endl;
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            t--;
            // grid[i][j] = 0;
            for(int k = 0;k<4;k++){
                if(i+dx[k]>=0 and i+dx[k]<grid.size() and j+dy[k]>=0 and j+dy[k]<grid[0].size() and grid[i+dx[k]][j+dy[k]]==1){
                    // cout<<i+dx[k]<<" "<<j+dy[k]<<endl;
                    grid[i+dx[k]][j+dy[k]] = 0;
                    q.push({i+dx[k],j+dy[k]});
                    c++;
                    needed--;
                }
            }
            if(t == 0){
                ans++;
                t = c;
                c= 0;
            }
        }
        if(needed>0) return -1;
        if(ans>0) return ans-1;
        else if(ans == 0) return 0; 
        return ans-1;
    }
};