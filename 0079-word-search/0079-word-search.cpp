class Solution {
public:
    bool ok = false;
    bool check(vector<vector<char>>&v,int cnt,int i,int j,string &word){
        if(word.size() == cnt) return true;
        if(i>= v.size() or i<0 or j>=v[i].size() or j<0 or word[cnt]!=v[i][j]) return false;
        
        char c = v[i][j];
        v[i][j] = '.';
        bool ans = check(v,cnt+1,i+1,j,word) or check(v,cnt+1,i-1,j,word) or check(v,cnt+1,i,j+1,word) or check(v,cnt+1,i,j-1,word);
        
        v[i][j] = c;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> vis(board.size(),vector<int>(board[0].size()));
        string s = "";
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[i].size();j++){
                if(board[i][j] == word[0]){
                    if(check(board,0,i,j,word)) return true;
                }
            }
        }
        return false;
    }
};