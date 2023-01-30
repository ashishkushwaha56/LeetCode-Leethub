class Solution {
public:
    vector<int> dx = {0,0,1,-1};
    vector<int> dy = {1,-1,0,0};
    void dfs(vector<vector<char>>&v,int i,int j){
        for(int k = 0;k<4;k++){
            if(i+dx[k]>=0 and i+dx[k]<v.size() and j+dy[k]>=0 and j+dy[k]<v[i].size()){
                if(v[i+dx[k]][j+dy[k]] == 'X'){
                    v[i+dx[k]][j+dy[k]] = '.';
                    dfs(v,i+dx[k],j+dy[k]);
                }
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int ans = 0;
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[i].size();j++){
                if(board[i][j]  == 'X'){
                    board[i][j] = '.';
                    dfs(board,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};