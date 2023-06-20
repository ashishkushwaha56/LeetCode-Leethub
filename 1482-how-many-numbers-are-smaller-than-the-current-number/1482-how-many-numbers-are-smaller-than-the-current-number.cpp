class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> v = nums;
        sort(v.begin(),v.end());
        for(int i = 0;i<nums.size();i++){
            auto it = lower_bound(v.begin(),v.end(),nums[i])-v.begin();
            nums[i]=it;
        }   
        return nums;
    }
};