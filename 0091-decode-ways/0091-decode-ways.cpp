class Solution {
public:
    int helper(vector<int>&dp,string&s,int i){
        if(i == s.size()) return 1;
        if(dp[i]!=-1) return dp[i];
        int cnt = 0;
        if(s[i]!='0'){
            cnt+=helper(dp,s,i+1);
        }
        if(i<s.size()-1 and (s[i] == '1' or s[i] == '2' and s[i+1]<='6'))
            cnt+=helper(dp,s,i+2);
        return dp[i]=cnt;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size(),-1);
        return helper(dp,s,0);
    }
};