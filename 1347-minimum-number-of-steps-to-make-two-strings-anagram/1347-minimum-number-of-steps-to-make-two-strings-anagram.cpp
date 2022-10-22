class Solution {
public:
    int minSteps(string s, string t) {
        vector<pair<int,int>> v(26);
        for(int i = 0;i<s.size();i++){
            v[s[i]-'a'].first++;
            v[t[i]-'a'].second++;
        }
        int ans = 0;
        for(auto &it:v){
            if(it.first>it.second) ans+=(it.first-it.second);
        }
        return ans;
    }
};