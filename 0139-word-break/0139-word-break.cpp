class Solution {
public:
    bool helper(string s, unordered_set<string>&v){
        if(!v.size()) return false;
        vector<bool>dp(s.size()+1,false);
        dp[0] = true;
        for(int i = 1;i<=s.size();i++){
            for(int j = i-1;j>=0;j--){
                if(dp[j]){
                    string a=s.substr(j,i-j);
                    if(v.find(a)!=v.end()){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> v;
        for(auto &it:wordDict){
            v.insert(it);
        }
        return helper(s,v);
    }
};