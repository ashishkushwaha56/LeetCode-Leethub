class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        if(nums.size()<=2) return 2;
        vector<unordered_map<int,int>> dp(nums.size()+1);
        int ans = 2;
        for(int i=1;i<nums.size();i++){
            for(int j = 0;j<i;j++){
                int d = nums[i]-nums[j];
                int cnt = 1;
                if(dp[j].find(d)!=dp[j].end()){
                    cnt = dp[j][d];
                }
                dp[i][d] = 1+cnt;
                ans = max(ans,dp[i][d]);
            }
        }
        return ans;
    }
};