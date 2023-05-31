class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans(1);
        int carry = 0;
        ans[0] = (digits[digits.size()-1]+1)%10;
        carry = (carry+digits[digits.size()-1]+1)/10;
        for(int i =digits.size()-2;i>=0;i--){
            ans.push_back((carry+digits[i])%10);
            carry = (carry+digits[i])/10;
        }
        if(carry!=0) ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};