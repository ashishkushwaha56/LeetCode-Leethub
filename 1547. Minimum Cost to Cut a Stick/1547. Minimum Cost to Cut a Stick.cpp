class Solution {
public:
    int helper(vector<vector<int>>&dp,vector<int>&cuts,int left,int right,int a,int b){
        if(right<left) return 0;
        if(dp[left][right]!=-1) return dp[left][right];
        int ans = INT_MAX;
        for(int i = left;i<=right;i++){
            int d = (b-a)+helper(dp,cuts,left,i-1,a,cuts[i])+helper(dp,cuts,i+1,right,cuts[i],b);
            ans = min(ans,d);
        }
        return dp[left][right] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        vector<vector<int>> dp(cuts.size(),vector<int>(cuts.size(),-1));
        sort(cuts.begin(),cuts.end());
        return helper(dp,cuts,0,cuts.size()-1,0,n);
    }
};
