class Solution {
public:
    unordered_map<int,int> mb;
    vector<int> singleNumber(vector<int>& nums) {
        
        for(auto &ot:nums){
            mb[ot]++;
        }
        vector<int> ans;
        for(auto &it:mb){
            if(it.second == 1) ans.push_back(it.first);
        }
        return ans;
    }
};