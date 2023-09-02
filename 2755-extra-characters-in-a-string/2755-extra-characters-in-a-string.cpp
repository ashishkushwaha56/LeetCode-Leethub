class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string,int> mb;
        for(auto &it:dictionary){
            mb[it]++;
        }
        vector<int> dp(51,-1);
        function <int(int)> helper = [&](int i)->int{
            if(i>=s.size()) return 0;
            if(dp[i] !=-1) return dp[i];
            int ans = 51;
            ans = min(ans,1+helper(i+1));
            string a;
            for(auto &it:mb){
                a = it.first;
                if(s.compare(i,a.size(),a)==0){
                    ans = min(ans,helper(i+a.size()));
                }
            }
            return dp[i] = ans;
        };
        return helper(0);
    }
};