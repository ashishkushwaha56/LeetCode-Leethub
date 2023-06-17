class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for(int i = 0;i<words.size();i++){
            int j = 0;
            while(j<min(words[i].size(),pref.size())){
                if(words[i][j]!=pref[j]) break;
                j++;
            }
            if(j==pref.size()) ans++;
        }
        return ans;
    }
};