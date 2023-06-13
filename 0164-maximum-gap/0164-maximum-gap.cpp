class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2) return 0;
        sort(nums.begin(),nums.end());
        int maxd = 0;
        for(int i = 1;i<nums.size();i++){
            maxd = max(nums[i]-nums[i-1],maxd);
        }
        return maxd;
    }
};