class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int j;
        for(int i = 0;i<nums.size();i++){
            j = abs(nums[i]);
            if(nums[j]<0) return j;
            nums[j] = -nums[j];
        }
        return nums.size();
    }
};