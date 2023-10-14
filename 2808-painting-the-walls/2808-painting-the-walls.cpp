class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        vector<vector<int>> dp(501,vector<int>(501,-1));
        function<int(int,int)> helper = [&](int i,int cnt)->int{
            if(cnt<=0) return 0;
            if(i>=cost.size()) return 1e9;
            
            if(dp[i][cnt]!=-1) return dp[i][cnt];
            int a = helper(i+1,cnt);
            int b = cost[i]+helper(i+1,cnt-time[i]-1);
            return dp[i][cnt] = min(a,b);
        };
        return helper(0,time.size());
    }
};