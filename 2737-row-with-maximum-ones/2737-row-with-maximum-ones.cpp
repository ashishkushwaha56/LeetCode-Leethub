class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        map<int,set<int>> mb;
        int cnt = 0;
        for(int i = 0;i<mat.size();i++){
            cnt = 0;
            for(int j = 0;j<mat[0].size();j++){
                cnt+=(mat[i][j]);
            }
            mb[cnt].insert(i);
        }
        auto it = mb.end();
        it--;
        return {(*(*it).second.begin()),(*it).first};
    }
};