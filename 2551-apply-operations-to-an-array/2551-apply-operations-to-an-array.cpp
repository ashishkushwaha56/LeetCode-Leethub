class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i = 0;i<nums.size()-1;i++){
            if(nums[i] == nums[i+1]) {
                nums[i+1] = 0;
                nums[i]*=2;
            }
        }
        int j = 0;
        // int i = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
        return nums;
    }
};