class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int d = 1;
        for(auto &it:nums){
            d&=it;
        } 
        if(d>0) return 1;
        int ans = 0;
        d= 0;
        for(auto &it:nums){
            
            if(d == 0) {
                d = it;
            }
            else{
                d&=it;
            }
            if(d == 0) ans++;
        } 
        return max(1,ans);
    }
};