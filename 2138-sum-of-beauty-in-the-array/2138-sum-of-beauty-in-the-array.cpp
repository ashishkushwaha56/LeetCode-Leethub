class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        vector<int> ad(nums.size()),bd(nums.size());
        ad[0] = nums[0];
        for(int i = 1;i<nums.size();i++){
            ad[i] = max(nums[i],ad[i-1]);
        }
        bd[nums.size()-1] = nums[nums.size()-1];
        for(int i = nums.size()-2;i>=0;i--){
            bd[i] = min(bd[i+1],nums[i]);
        }
        int ans = 0;
        for(int i = 1;i<nums.size()-1;i++){
            if(bd[i+1]>nums[i] and ad[i-1]<nums[i]) ans+=2;
            else if(nums[i-1]<nums[i] and nums[i+1]>nums[i]) ans++;
        }
        return ans;
    }
};