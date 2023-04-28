class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int j = 0;
        while(true){
            while(j<nums.size() and nums[j]!=val){
                j++;
            }
            i = j;
            while(i<nums.size() and nums[i] == val) i++;
            if(j<nums.size() and i<nums.size()){
                swap(nums[i],nums[j]);
                j++;
            }
            if(i==nums.size()) break;
        }
        return j;
    }
};