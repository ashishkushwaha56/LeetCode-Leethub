class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans =0,t=0;
        for(auto &it:nums){
            t+=(it==1)?1:(t=0);
            ans=max(t,ans);
        }
        return ans;
    }
};