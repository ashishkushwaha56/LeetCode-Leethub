class Solution {
public:
    int similarPairs(vector<string>& words) {
        int ans =0;
        for(int i = 0;i<words.size()-1;i++){
            vector<bool> v(26,false);
            for(int k = 0;k<words[i].size();k++){
                v[words[i][k]-'a'] = true;
            }
            
            for(int j = i+1;j<words.size();j++){
                vector<bool> b(26,false);
                for(int k = 0;k<words[j].size();k++){
                    b[words[j][k]-'a'] = true;
                }   
                ans+=(v == b);
            }
        }
        return ans;
    }
};