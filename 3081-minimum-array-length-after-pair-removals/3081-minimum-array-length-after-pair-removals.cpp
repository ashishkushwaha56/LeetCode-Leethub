class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int d = nums[nums.size()/2];
        int cnt = count(nums.begin(),nums.end(),d);
        if(cnt>nums.size()/2) return 2*cnt-nums.size();
        if(nums.size()&1) return 1;
        return 0;
    }
};