class Solution {
public:
    int minSteps(string &s, string &t) {
        pair<int,int> vc[26] = {{0,0}};
        for(int i = 0;i<s.size();i++){
            vc[s[i]-'a'].first++;
        }
        
        for(int i = 0;i<t.size();i++){
            vc[t[i]-'a'].second++;
        }
        int ans = 0;
        for(int i = 0;i<26;i++){
            ans+=abs(vc[i].first-vc[i].second);
        }
        return ans;
    }
    
};