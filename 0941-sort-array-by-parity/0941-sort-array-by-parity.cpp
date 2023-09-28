class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int j = 0,i = 0;
        while(i<nums.size()){
            if(!(nums[i]&1)){
                swap(nums[j],nums[i]);
                j++;
            }
            i++;
        }
        return nums;
    }
};