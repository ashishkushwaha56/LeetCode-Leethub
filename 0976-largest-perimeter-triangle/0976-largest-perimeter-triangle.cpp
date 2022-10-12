class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        for(int i = 1;i<nums.size()-1;i++){
            if(nums[i-1]<nums[i]+nums[i+1]) return (nums[i-1]+nums[i]+nums[i+1]);
        }
        return 0;
    }
};