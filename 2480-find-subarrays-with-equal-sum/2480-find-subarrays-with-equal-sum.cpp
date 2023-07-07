class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        map<int,int> mb;
        for(int i = 0;i<nums.size()-1;i++){
            mb[nums[i]+nums[i+1]]++;
        }
        for(auto &it:mb){
            if(it.second >=2) return true;
        }
        return false;
    }
};