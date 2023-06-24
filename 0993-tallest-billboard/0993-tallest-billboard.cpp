class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int d = 0;
        for(auto &it:rods){
            d+=it;
        }
        int dp[d+1];
        dp[0] = 0;
        for(int i = 1;i<d+1;i++){
            dp[i] = -1;
        }
        for(auto &it:rods){
            int dpcopy[d+1];
            copy(dp,dp+(d+1),dpcopy);
            for(int i = 0;i<=d-it;i++){
                if(dpcopy[i]<0) continue;
                dp[i+it] = max(dp[i+it],dpcopy[i]);
                dp[abs(i-it)] = max(dp[abs(i-it)],dpcopy[i]+min(i,it));
            }
        }
        return dp[0];
    }
};