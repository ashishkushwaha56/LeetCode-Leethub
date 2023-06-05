class Solution {
public:
    int longestContinuousSubstring(string s) {
        int i = 0;
        int cnt = 1;
        int ans = 1;
        while(i<s.size()-1){
            if(s[i]+1 == s[i+1]) cnt++;
            else cnt = 1;
            ans = max(ans,cnt);
            i++;
        }
        return ans;
    }
};