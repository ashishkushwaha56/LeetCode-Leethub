class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(3,-1));
        function<int(int,int)> helper = [&](int i,int rem)->int{
            if(i>=nums.size()){
                return rem?-1e8:0;
            }
            if(dp[i][rem]!=-1) return dp[i][rem];
            int a = nums[i]+helper(i+1,(rem+nums[i])%3);
            int b = helper(i+1,rem);
            return dp[i][rem] = max({a,b});
        };
        return helper(0,0);
    }
};