class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& s) {
        unordered_map<int,vector<int>> mb;
        for(int i = 0;i<s.size();i++){
            mb[s[i]].push_back(i);
        }
        vector<vector<int>> ans;
        vector<int> temp;
        int k;
        
        for(auto &it:mb){
            k = it.first;
            for(int i = 0;i<it.second.size();i++){
                temp.push_back(it.second[i]);
                
                if((i+1)%k == 0){
                    ans.push_back(temp);
                    temp.clear();
                }
            }
        }
        return ans;
    }
};