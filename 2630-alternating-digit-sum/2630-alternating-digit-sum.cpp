class Solution {
public:
    int alternateDigitSum(int n) {
        string a =to_string(n);
        int ans = 0;
        for(int i = 0;i<a.size();i++){
            if(i&1) ans-=(a[i]-'0');
            else ans+=(a[i]-'0');
        }
        return ans;
    }
};