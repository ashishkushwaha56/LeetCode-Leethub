class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        vector<string> sd(words.size());
        for(int i = 0;i<words.size();i++){
            sd[i]= words[i];
            reverse(sd[i].begin(),sd[i].end());
        }
        int ans = 0;
        for(int i = 0;i<words.size()-1;i++){
            for(int j = i+1;j<words.size();j++){
                if(words[i]==sd[j]) ans++;
            }
        }
        return ans;
    }
};