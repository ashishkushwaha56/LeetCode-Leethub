class Solution {
public:
    int ans= 0;
    void check(vector<int>&nums,int target, int cnt,int i){
        if(i==nums.size()-1){
            ans+=(cnt == target);
            return;
        }
        check(nums,target,cnt+nums[i+1],i+1);
        check(nums,target,cnt-nums[i+1],i+1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        check(nums,target,nums[0],0);
        check(nums,target,-nums[0],0);
        return ans;
    }
};