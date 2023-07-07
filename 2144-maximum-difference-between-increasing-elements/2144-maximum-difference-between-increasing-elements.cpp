class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = -1;
        int maxe = nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            if(maxe-nums[i]>0)
                ans = max(ans,maxe-nums[i]);
            maxe = max(maxe,nums[i]);
        }
        return ans;
    }
};