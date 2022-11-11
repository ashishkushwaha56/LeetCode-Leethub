class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 1;
        int i = 1;
        while(i<nums.size()){
            if(nums[i] == nums[l-1]){
                i++;
            }
            else{
                nums[l] = nums[i];
                l++;
                i++;
            }
        }
        return l;
    }
};