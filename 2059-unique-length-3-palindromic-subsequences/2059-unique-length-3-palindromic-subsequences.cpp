class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int>v(26);
        vector<int> b(26);
        map<pair<int,int>,int> mb;
        for(auto &it:s){
            v[it-'a']++;
        }
        int ans = 0;
        for(int i = 0;i<s.size();i++){
            v[s[i]-'a']--;
            for(int k = 0;k<26;k++){
                if(v[k]>0 and b[k]>0 and mb.find({k,s[i]-'a'})==mb.end()){
                    ans++;
                    mb[{k,s[i]-'a'}]++;
                }
            }
            b[s[i]-'a']++;
        }
        return ans;
    }
};