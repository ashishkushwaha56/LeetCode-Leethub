class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> pre(n+1,0);
        for(int i = 1;i<n+1;i++){
            pre[i] = pre[i-1]+stoneValue[i-1];
        }
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        function<int(int,bool)> helper =[&](int i,bool flag)->int{
            if(i>=n) return 0;
            if(dp[i][flag]!=-1) return dp[i][flag];
            if(flag){
                int ans = INT_MIN;
                for(int d = 0;d<3;d++){
                    if(i+d<n){
                        ans = max(ans,(pre[i+d+1]-pre[i])+helper(i+d+1,false));
                    }
                }
                return dp[i][flag] = ans;
            }
            int ans = INT_MAX;
            for(int d = 0;d<3;d++){
                if(i+d<n){
                    ans = min(ans,helper(i+d+1,true));
                }

            }
            return dp[i][flag] = ans;
        };
        int alice = helper(0,true);
        int bob = pre.back()-alice;
        if(alice>bob){
            return "Alice";
        }
        else if(alice<bob){
            return "Bob";
        }
        return "Tie";
    }
};