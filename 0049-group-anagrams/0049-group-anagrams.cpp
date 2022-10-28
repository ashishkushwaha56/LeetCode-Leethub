class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> vb;
        string s;
        for(int i = 0;i<strs.size();i++){
            s = strs[i];
            sort(s.begin(),s.end());
            vb[s].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto &it:vb){
            ans.push_back(it.second);
        }
        return ans;
    }
};