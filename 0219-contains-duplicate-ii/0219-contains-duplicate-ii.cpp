class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mb;
        for(int i = 0;i<nums.size();i++){
            if(mb.find(nums[i])!=mb.end()){
                if(abs(mb[nums[i]]-i)<=k) return true;
            }
            mb[nums[i]] = i;
        }
        return false;
    }
};