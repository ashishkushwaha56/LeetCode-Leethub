class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        unordered_set<int> s;
        for(int i = 1;i<strs.size();i++){
            for(int j = 0;j<strs[i].size();j++){
                if(s.find(j)!=s.end() or strs[i-1][j] == strs[i][j]) continue;
                if(strs[i-1][j]>strs[i][j]){
                    s.insert(j);
                    i=0;
                }
                break;
            }
        }
        return s.size();
    }
};