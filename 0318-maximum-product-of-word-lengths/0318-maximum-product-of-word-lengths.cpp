class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> v(26),b(26);
        vector<vector<int>> g(words.size(),vector<int>(26));
        for(int i = 0;i<words.size();i++){
            for(int j = 0;j<words[i].size();j++){
                g[i][words[i][j]-'a']++;
            }
        }
        int cnt = 0;
        int ans = 0;
        for(int i = 0;i<words.size()-1;i++){
            for(int j = i+1;j<words.size();j++){
                cnt = 0;
                for(int k = 0;k<26;k++){
                    cnt+=min(g[i][k],g[j][k]);
                }
                if(cnt == 0){
                    ans = max(ans,(int)(words[i].size()*words[j].size()));
                }
            }
        }
        return ans;
    }
};