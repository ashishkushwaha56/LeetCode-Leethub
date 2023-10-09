class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        auto it2 = upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(it == nums.size()){
            return {-1,-1};
        }
        else{
            if(nums[it]>target){
                return {-1,-1};
            }
            else{
                it2--;
                return vector<int>({(int)it,(int)it2});
            }
        }
    }
};