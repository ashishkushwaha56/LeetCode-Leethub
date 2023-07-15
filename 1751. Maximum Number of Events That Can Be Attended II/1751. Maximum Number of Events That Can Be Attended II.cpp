class Solution {
public:
    int helper(vector<vector<int>>&dp,vector<vector<int>>&events,int k,int i){
        if(i >= events.size() or k == 0 or i == -1) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        int ans = 0;
        int next = events[i][1]+1;
        vector<int> d = {next,0,0};
        auto it = lower_bound(events.begin(),events.end(),d)-events.begin();
        ans = max(ans,events[i][2]+helper(dp,events,k-1,it));
        ans = max(ans,helper(dp,events,k,i+1));
        return dp[i][k] = ans;
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        vector<vector<int>> dp(events.size(),vector<int>(k+1,-1));
        return helper(dp,events,k,0);
    }
};
