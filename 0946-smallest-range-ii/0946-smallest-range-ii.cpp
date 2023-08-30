class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans = nums[nums.size()-1]-nums[0];
        for(int i=0;i<nums.size()-1;i++){
            int a = min(nums[0]+k,nums[i+1]-k);
            int b = max(nums[nums.size()-1]-k,nums[i]+k);
            // if(a-b>0)
            ans = min(ans,abs(b-a));
        }
        return ans;
    }
};