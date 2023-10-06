class Solution {
public:
    int idealArrays(int n, int maxValue) {
        vector<vector<int>> dp(22,vector<int>(1e4+5,-1));
        vector<vector<int>> lenghts(1e4+5,vector<int>(21));
        for(int i = 1;i<1e4+5;i++){
            lenghts[i][1] = 1;
            for(int k = i+i;k<=maxValue;k+=i){
                for(int j = 0;j<20;j++){
                    lenghts[k][j+1]+=lenghts[i][j];
                }
            }
        }
        int mod = 1e9+7;
        function<int(int,int)> helper = [&](int lenght,int n)->int{
            if(n == 0) return lenght == 0;
            if(lenght == 0) return 0;
            if(dp[lenght][n]!=-1) return dp[lenght][n];
            int ans = 0;
            ans = (ans+helper(lenght,n-1)%mod)%mod;
            ans = (ans+helper(lenght-1,n-1)%mod)%mod;
            return dp[lenght][n] = ans;
        };
        int ans = 0;
        for(int i = maxValue;i>=1;i--){
            for(int j = 1;j<21;j++){
                long long d = helper(j,n);
                ans = (ans+(d*lenghts[i][j])%mod)%mod;
            }
        }
        return ans;
    }
};