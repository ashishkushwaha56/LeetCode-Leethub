class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        set<string> sd;
        string t = "";
        for(int i = 0;i<s.size();i++){
            t+=s[i];
            sd.insert(t);
        }
        int ans = 0;
        for(int i = 0;i<words.size();i++){
            if(sd.find(words[i])!=sd.end()) ans++;
        }
        return ans;
    }
};