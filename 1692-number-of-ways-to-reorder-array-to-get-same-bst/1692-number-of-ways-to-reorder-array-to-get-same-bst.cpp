class Solution {
public:
    vector<vector<long long>>dp;
    // int mod = 1e9+7;
    long long dfs(vector<int>&v,long long mod){
        if(v.size()<=2) return 1;
        vector<int>left,right;
        for(int i = 1;i<v.size();i++){
            if(v[i]<v[0]) left.push_back(v[i]);
            else right.push_back(v[i]);
        }
        long long left_side = dfs(left,mod)%mod;
        long long right_side = dfs(right,mod)%mod;
        return (((dp[v.size()-1][left.size()])%mod*left_side)%mod*right_side%mod)%mod;
    }
    int numOfWays(vector<int>& nums) {
        long long mod = 1e9+7;
        dp.resize(nums.size()+1,vector<long long>(nums.size()+1));
        for(int i = 0;i<nums.size()+1;i++){
            dp[i][0] = 1;
        }
        for(int i = 1;i<nums.size()+1;i++){
            // dp[i][0] = 1;
            for(int j = 1;j<=i;j++){
                dp[i][j] = (dp[i-1][j-1]+dp[i-1][j])%mod;
            }
        }
        return (dfs(nums,mod)%mod-1)%mod;
    }
    
};