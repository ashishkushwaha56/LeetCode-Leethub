class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int cnt  = 0;
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            ans = (ans^nums[i])&~cnt;
            cnt = (cnt^nums[i])&~ans;
        }
        return ans;
    }
};