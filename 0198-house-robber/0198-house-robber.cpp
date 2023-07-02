class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()<2) return nums[0];
        for(int i = 0;i<nums.size();i++){
            int a = nums[i];
            int b = 0;
            if(i>0){
                b = nums[i-1];
            }
            if(i>1){
                a+=nums[i-2];
            }
            nums[i] = max(a,b);
        }
        return max(nums[nums.size()-1],nums[nums.size()-2]);
    }
};