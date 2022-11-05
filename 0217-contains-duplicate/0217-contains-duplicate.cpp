class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> vb;
        for(int i = 0;i<nums.size();i++){
            if(vb.count(nums[i]) == 1){
                return true;
            }
            vb.insert(nums[i]);
        }
        return false;
    }
};