class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int cnt = 0;
        vector<set<int>> row_co(9),col_co(9);
        vector<int> row(9),col(9);
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board.size();j++){
                if(board[i][j]!='.'){
                    row_co[i].insert(board[i][j]-'0');
                    row[i]++;
                    col_co[j].insert(board[i][j]-'0');
                    col[j]++;
                }
            }
        }
        vector<set<int>> three(9);
        vector<int> three_cnt(9);
        int h = 0;
        for(int i = 0;i<board.size();i+=3){
            for(int j = 0;j<board.size();j+=3){
                for(int k = i;k<i+3;k++){
                    for(int g = j;g<j+3;g++){
                        if(board[k][g]!='.'){
                            three[h].insert(board[k][g]-'0');
                        three_cnt[h]++;
                        }
                        
                    }
                }
                h++;
            }
        }
        
        for(int i = 0;i<9;i++){
            if(row_co[i].size()!=row[i] or col_co[i].size()!=col[i] or three[i].size()!=three_cnt[i]) return false;
        }
        return true;
    }
};