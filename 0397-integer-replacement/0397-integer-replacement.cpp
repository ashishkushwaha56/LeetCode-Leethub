class Solution {
public:
    int helper(unordered_map<long long,int>&dp,long long n){
        if(n == 1) return 0;
        if(dp.find(n)!=dp.end()){
            return dp[n];
        }
        int ans;
        if(n&1){
            int a = helper(dp,n-1);
            int b = helper(dp,n+1);
            ans = 1+min(a,b);
        }
        else{
            ans = 1+helper(dp,n/2);
        }
        return dp[n]=ans;
    }
    int integerReplacement(int n) {
        unordered_map<long long,int> dp;
        return helper(dp,n);
    }
};