class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int cnt = 0;
        vector<int> ans(nums.size());
        int sum = accumulate(nums.begin(),nums.end(),0ll);
        int n= nums.size()-1;
        for(int i = 0;i<nums.size();i++){
            sum-=nums[i];
            ans[i] += abs((n-i)*nums[i]-(sum));
            ans[i]+=abs(i*nums[i]-cnt);
            cnt+=nums[i];
        }
        return ans;
    }
};