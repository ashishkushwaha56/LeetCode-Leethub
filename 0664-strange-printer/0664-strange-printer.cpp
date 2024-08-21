class Solution {
public:
    int strangePrinter(string s) {
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
        function <int(int,int)> helper = [&](int i,int j)->int{
            if(i == j) return dp[i][j] = 1;
            if(dp[i][j]!=-1) return dp[i][j];
            int ans;
            if(s[j-1] == s[j]) ans = helper(i,j-1);
            else if(s[i] == s[i+1] or s[i] == s[j]) ans = helper(i+1,j);
            else{
                ans = 1 + helper(i,j-1);
                for(int k = i+1; k < j;k++){
                    if(s[k] == s[j]){
                        ans = min(ans,helper(i,k-1)+helper(k,j-1));
                    }
                } 
            }
            return dp[i][j] = ans;
        };
        return helper(0,s.size()-1);
    }
};