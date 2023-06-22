class Solution {
public:
    int check(vector<int>&prices,vector<vector<int>>&dp,int buy_stock,int fee,int i){
        if(i == prices.size()) return 0;
        if(dp[i][buy_stock]!=-1) return dp[i][buy_stock];
        int a = check(prices,dp,buy_stock,fee,i+1);
        int b=0;
        if(buy_stock == 0){
            b = check(prices,dp,1,fee,i+1)+prices[i];
        }
        else{
            b = check(prices,dp,0,fee,i+1)-prices[i]-fee;
        }
        return dp[i][buy_stock] = max(a,b);
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return check(prices,dp,1,fee,0);
    }
};