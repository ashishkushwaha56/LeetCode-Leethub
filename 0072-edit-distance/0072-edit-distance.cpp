class Solution {
public:
    int helper(string&word1,string&word2,vector<vector<int>>&dp,int i,int j){
        if(i == 0) return j;
        if(j==0) return i;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = INT_MAX;
        if(word1[i-1]==word2[j-1]) ans = min(helper(word1,word2,dp,i-1,j-1),ans);
        else{
            ans = min({1+helper(word1,word2,dp,i-1,j-1),1+helper(word1,word2,dp,i-1,j),1+helper(word1,word2,dp,i,j-1)});
        }
        return dp[i][j] = ans;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        return helper(word1,word2,dp,word1.size(),word2.size());
    }
};