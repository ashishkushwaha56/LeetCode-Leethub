class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp = nums;
        int ans = 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]); 
        for(int i = 0;i<nums.size()-1;i++){
            int a = dp[i];
            int b = 0;
            if(i>0){
                b = dp[i-1];
            }
            if(i>1){
                a+=dp[i-2];
            }
            dp[i]=max(a,b);
        }   

        ans = max(ans,max(dp[nums.size()-2],dp[nums.size()-3]));
        dp = nums;
        for(int i = 1;i<nums.size();i++){
            int a = dp[i];
            int b = 0;
            if(i>1){
                b = dp[i-1];
            }
            if(i>2){
                a+=dp[i-2];
            }
            dp[i]=max(a,b);
        }
        ans = max(ans,max(dp[nums.size()-2],dp[nums.size()-1]));
        return ans;
    }
};