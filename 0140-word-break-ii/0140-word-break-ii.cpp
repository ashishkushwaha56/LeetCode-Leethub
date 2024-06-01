class Solution {
public:
    vector<string> ans;
    void dfs(string &s,int i,unordered_set<string>&sd,vector<string>&temp){
        if(i>=s.size()){
            string tt = "";
            for(auto &it:temp){
                tt+=it;
                tt+=' ';
            }
            tt.pop_back();
            ans.push_back(tt);
            return;
        }
        string tt = "";
        for(int j = i;j<s.size();j++){
            tt+=s[j];
            if(sd.find(tt)!=sd.end()){
                temp.push_back(tt);
                dfs(s,j+1,sd,temp);
                temp.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> sd;
        for(auto &it:wordDict){
            sd.insert(it);
        }
        vector<string> temp;
        dfs(s,0,sd,temp);
        return ans;
    }
};