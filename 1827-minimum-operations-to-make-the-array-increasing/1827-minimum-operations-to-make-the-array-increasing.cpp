class Solution {
public:
    int minOperations(vector<int>& nums) {
        int last = nums[0];
        int ans= 0;
        for(int i = 1;i<nums.size();i++){
            if(last<nums[i]){
                last = nums[i];
                continue;
            }
            else{
                ans+=(last-nums[i]+1);
                last++;
            }
        }
        return ans;
    }
};