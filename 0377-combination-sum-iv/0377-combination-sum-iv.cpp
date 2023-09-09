class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        function <int(int)> helper = [&](int n)->int{
            if(n == 0) return 1;
            if(dp[n]!=-1) return dp[n];
            int ans = 0;
            for(int i = 0;i<nums.size();i++){
                if(n-nums[i]>=0){
                    ans+=helper(n-nums[i]);
                }
            }
            return dp[n] = ans;
        };
        return helper(target);
    }
};