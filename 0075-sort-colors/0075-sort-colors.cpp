class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0 = 0, count1 = 0, count2 = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 0){
                count0++;
            }
            else if(nums[i] == 1){
                count1++;
            }
            else{
                count2++;
            }
        }
        
        for(int i = 0; i<nums.size(); i++){
            if(i<count0){
                nums[i] = 0;
            }
            if(i>=count0 && i<(count0+count1)){
                nums[i] = 1;
            }
            if(i>=(count0+count1) && i<(count0+count1+count2)){
                nums[i] = 2;
            }
        }
    }
};