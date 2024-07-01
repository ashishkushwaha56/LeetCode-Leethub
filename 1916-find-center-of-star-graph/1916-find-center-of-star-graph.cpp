class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> mb;
        for(auto &it:edges){
            mb[it[0]]++;
            mb[it[1]]++;
        }
        for(auto &it:mb){
            if(it.second == mb.size()-1){
                return it.first;
            }
        }
        return 0;
    }
};