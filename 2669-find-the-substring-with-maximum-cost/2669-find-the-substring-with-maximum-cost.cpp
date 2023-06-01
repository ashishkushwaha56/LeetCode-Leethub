class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> v(26);
        for(int i = 0;i<26;i++){
            v[i] = i+1;
        }
        for(int i = 0;i<chars.size();i++){
            v[chars[i]-'a'] =vals[i]; 
        }
        vector<int> sd(s.size());
        for(int i = 0;i<s.size();i++){
            sd[i] = v[s[i]-'a'];
        }
        int ans = 0;
        int sum = 0;
        for(int i = 0;i<sd.size();i++){
            sum+=sd[i];
            if(sum<0){
                sum = 0;
            }
            ans = max(ans,sum);
        }
        return ans;
    }
};