class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int>ans;
        unordered_set<char> s = {'a','e','i','o','u'};
        vector<int> pre(words.size()+1);
        for(int i = 0;i<words.size();i++){
            pre[i+1] = pre[i]+(s.find(words[i][0])!=s.end() and s.find(words[i][words[i].size()-1])!=s.end());
        }
        for(int i = 0;i<queries.size();i++){
            ans.push_back(pre[queries[i][1]+1]-pre[queries[i][0]]);
        }
        return ans;
    }
};