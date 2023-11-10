class Solution {
public:
    int countHomogenous(string s) {
        const int mod = 1e9+7;
        int ans = 0;
        long long cnt = 1;
        for(int i = 1;i<s.size();i++){
            if(s[i]!=s[i-1]){
                ans = (ans+ ((cnt*(cnt+1))/2)%mod)%mod;
                cnt = 1;
            }
            else cnt++;
        }
        ans = (ans+ ((cnt*(cnt+1))/2)%mod)%mod;
        return ans;
    }
};