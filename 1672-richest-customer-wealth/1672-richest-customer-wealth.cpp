class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        for(int i = 0;i<accounts.size();i++){
            ans = max(ans,(int)accumulate(accounts[i].begin(),accounts[i].end(),0ll));
        }
        return ans;
    }
};