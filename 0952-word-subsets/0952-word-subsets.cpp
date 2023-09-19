class Solution {
public:
    vector<string> wordSubsets(vector<string>& word1, vector<string>& word2) {
        vector<int> v(26);
        vector<int> b(26);
        for(int i = 0;i<word2.size();i++){
            for(auto &it:word2[i]){
                b[it-'a']++;
            }
            for(int k = 0;k<26;k++){
                v[k] = max(v[k],b[k]);
                b[k] = 0;
            }
        }
        vector<string> ans;
        for(auto &it:word1){
            for(auto &i:it){
                b[i-'a']++;
            }
            bool ok = true;
            for(int i = 0;i<26;i++){
                if(b[i]<v[i]){
                    ok = false;
                }
                b[i] = 0;
            }
            if(ok) ans.push_back(it);
        }
        return ans;
    }
};