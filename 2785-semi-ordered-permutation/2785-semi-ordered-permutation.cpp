class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int l = -1;
        int r = -1;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == 1) l = i;
            if(nums[i] == nums.size()) r = i;
        }
        if(l>r) return l+(nums.size()-r)-2;
        else return l+(nums.size()-r)-1;
    }
};