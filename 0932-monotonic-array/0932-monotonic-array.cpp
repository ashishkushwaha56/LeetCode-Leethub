class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int flag = 0;
        int d = nums[nums.size()-1]-nums[0];
        if(d>0) flag = 1;
        else if(d <0) flag = 2;
        if(d == 0){
            for(int i = 1;i<nums.size();i++){
                if(nums[i]!=nums[i-1]) return false;
            }
            return true;
        }
        else{
            for(int i = 1;i<nums.size();i++){
                if(nums[i] == nums[i-1]) continue;
                if(nums[i]>nums[i-1] and flag == 2) return false;
                if(nums[i]<nums[i-1] and flag == 1) return false;
            }
            return true;
        }
    }
};