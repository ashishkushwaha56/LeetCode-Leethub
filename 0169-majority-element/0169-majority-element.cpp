class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt= 1;
        int l = 0;
        for(int i = 1;i<nums.size();i++){
            if(nums[i]!=nums[l]){
                cnt--;
            }
            else{
                cnt++;
            }
            if(cnt == 0){
                l = i;
                cnt = 1;
            }
        }
        return nums[l];
    }
};