class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long> ans(nums.size());
        int maxe = 0;
        for(int i = 0;i<nums.size();i++){
            maxe = max(maxe,nums[i]);
            if(i == 0){
                ans[i] = maxe+nums[i];
            }
            else{
                ans[i] = ans[i-1]+maxe+nums[i];
            }
        }
        return ans;
    }
};