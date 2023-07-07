class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> mb;
        for(auto &it:nums){
            mb[it]++;
        }
        for(auto &it:mb){
            if(it.second%2!=0) return false;
        }
        return true;
    }
};